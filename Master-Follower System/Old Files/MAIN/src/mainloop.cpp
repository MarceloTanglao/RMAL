#include <mainloop.h>

#include <fstream>
#include <iostream>
#include <string>


MainLoop::MainLoop(Visualizer vis) {

    m_serial.s_portName("/dev/ttyACM0");
    m_serial.s_baudRate(115200); 

    f_serial.s_portName("/dev/ttyACM1");
    f_serial.s_baudRate(115200); 


    mp_vis = vis;

    m_cPos = 0;

    m_cath.s_baseFrame(Eigen::MatrixXd::Identity(4,4));
    m_cath.s_nseg(1);
    m_cath.s_nq(3);         // bend, rot, trans
    m_cath.s_pps(250);      
    m_cath.s_bbLen(100);
    m_cath.s_rad(1);

    m_aorta.s_deadD(1);
    m_aorta.s_dangerD(5);
    int catSeg = 1;
    int catQ = 3;
    Eigen::MatrixXd q(catQ,catSeg);
    for (int i=0; i<catSeg; i++){
        q(0,i) = 0;
        q(1,i) = 0;
        q(2,i) = 0;
    }
    m_q = q;

    // Original Enviroment Variables
    double r = 10;   // 2mm in diameter
    double h = 100;   // 2mm in Height
    double max = 1000;
    double rot = M_PI/64;

    /*
    //double max = 240;
    for (int i=0; i<max; i++){
        Eigen::Matrix4d point = Eigen::MatrixXd::Identity(4,4);
        point(0,3) = r*sin(i*rot);
        point(1,3) = r*cos(i*rot);
        point(2,3) = (h/2) + (h/2)*i/max;
                
        m_aorta.s_point(point);
    }*/    


    // Aorta Point Cloud
    std::ifstream inFile;
    std::string STRING;
    inFile.open("/home/marcelot/Desktop/RMAL/PointCloud.txt");
    Eigen::Matrix4d point = Eigen::MatrixXd::Identity(4,4);
    while (inFile.eof() != true) {
        getline(inFile, STRING);
        std::stringstream ss(STRING);
        for(int i=0;i<3;i++){    
            ss >> point(i,3);
        }
        m_aorta.s_point(point);  
    }
    inFile.close();
    


    m_engaged = false;
    m_cathEn = true;
    m_aortaEn = false;
    m_cPos = 0;




} 

MainLoop::~MainLoop() {}


void MainLoop::md_safetySim(){
    // Finding all possible motions
    std::vector<int> safetyRatings;
    std::vector<double> distanceRatings;
    std::vector<double> goalRatings;
    for (int i=0; i<3; i++){    // i is each degree of freedom
        for (int j=-1; j<2; j++){   // j is each direction we can go.
            Eigen::Matrix editQ = m_q;
            editQ(i,0) = m_q(i,0) + j*m_cath.g_qChange(i);

            m_cath.fkine(editQ);
            m_aorta.checkDistance(m_cath.g_eeFrame());
            safetyRatings.push_back(m_aorta.g_safety());
            distanceRatings.push_back(m_aorta.g_distance());
            goalRatings.push_back(m_cath.g_distEE());

            // Reset back to original State
            m_cath.fkine(m_q);
        }
    }

    // Go through each of the possibileities and find the best
    for (int i=0; i<3; i++){    // i is each degree of freedom
        int safestMove=-2;      // if the output is -2 there is a big problen
        double safestRate=1000;

        // Running Going throuth each segment movements
        int c1 = safetyRatings.at(i*3);
        int c2 = safetyRatings.at(i*3+1);
        int c3 = safetyRatings.at(i*3+2);
        int safeRates[3] = {safetyRatings.at(i*3), safetyRatings.at(i*3+1), safetyRatings.at(i*3+2)};
    
        // Finding the best spot
        for (int j=-1; j<2; j++){
            int currentSpot = i*3+(j+1);

            // Why do anything if we have a safety rate of dead.
            if(safetyRatings.at(currentSpot) == 0)  {continue;}

            // if our current spot is the same as the best.
            if (safetyRatings.at(currentSpot) >= *std::max_element(safeRates, safeRates+3)){
                // Update distance only if it is less than the previous or j=0.
                if(distanceRatings.at(currentSpot) < safestRate || j==0){
                    safestRate = distanceRatings.at(currentSpot);
                    safestMove = j;
                }
            }
        }
    }
}

void MainLoop::Execute(vtkObject *caller, unsigned long eventId, void *vtkNotUsed(callData)) {
    // Event Loop
    if (vtkCommand::TimerEvent == eventId) {
        
        // Code block for connecting to the master 
        std::string datain;
        try {
            m_serial.sendString("DIR");
            std::cout << "HERE" << std::endl;
            datain = m_serial.g_data();
            if (datain[0] == 'G'){
                if( datain[11] == 'S'){
                    std::cout << datain << std::endl;
                    std::string motor1 = datain.substr (1,3);
                    std::string motor2 = datain.substr (4,3);
                    std::string motor3 = datain.substr (7,9);
                    int mo1 = stoi(motor1);
                    int mo2 = stoi(motor2);
                    int mo3 = stoi(motor3);
                    double m01Base = 3.00;
                    double multi=6.0/360.0;
                    std::cout << mo1 << std::endl;
                    m_q(0,0) = ((double)mo1)*multi - m01Base;
                    m_q(1,0) = ((double)mo2)*M_PI/180;
                    m_q(2,0) = ((double)mo3);
                    std::cout <<m_q<< std::endl;
                    m_cath.fkine(m_q);
                    mp_vis.drawCath(m_cath.g_backbone(), 0.89/2);
                    mp_vis.update();
                }
                else{
                    std::cout << datain[12] << std::endl;
                }
            }
         
            //if (newInt > 1000){
            //    m_cPos = (pressent-1500)/1000;
            //    
           // }
            

            //m_cPos = datain;
        }

        catch (...) {
        }

        // Code block for connecting to the follower
        std::string datain_follower;
        try {
            f_serial.sendString("DIR");
            std::cout << "HERE" << std::endl;
            datain_follower = f_serial.g_data();
            if (datain_follower[0] == 'G'){
                if( datain_follower[11] == 'S'){
                    std::cout << datain << std::endl;
                    std::string motor1 = datain_follower.substr (1,3);
                    std::string motor2 = datain_follower.substr (4,3);
                    std::string motor3 = datain_follower.substr (7,9);
                    int mo1 = stoi(motor1);
                    int mo2 = stoi(motor2);
                    int mo3 = stoi(motor3);
                    double m01Base = 3.00;
                    double multi=6.0/360.0;
                    std::cout << mo1 << std::endl;
                    m_q(0,0) = ((double)mo1)*multi - m01Base;
                    m_q(1,0) = ((double)mo2)*M_PI/180;
                    m_q(2,0) = ((double)mo3);
                    std::cout <<m_q<< std::endl;
                    m_cath.fkine(m_q);
                    mp_vis.drawCath(m_cath.g_backbone(), 0.89/2);
                    mp_vis.update();
                }
                else{
                    std::cout << datain_follower[12] << std::endl;
                }
            }
         
            //if (newInt > 1000){
            //    m_cPos = (pressent-1500)/1000;
            //    
           // }
            

            //m_cPos = datain;
        }


        catch (...) {
        }

        
        
        //std::cout << m_serial.g_data() << std::endl;;
        //m_serial.sendString("AHHH");
        

        // Drawing Aorta
        if (m_aortaEn){
            std::cout << "Drawning\n";
            mp_vis.drawAorta(m_aorta.g_points(), 1, 5);
            mp_vis.update();
            mp_vis.drawSTL();
            m_aortaEn = false;
        }

        // Drawing Catheter
        if(m_cathEn){
            m_cath.fkine(m_q);
            mp_vis.drawCath(m_cath.g_backbone(), 0.89/2);
            mp_vis.update();
            //m_cathEn = false;
            //m_engaged = true;
        }

        





        // Running collision simulation
        if(m_engaged){
            md_safetySim();
            m_engaged = false;
        }
    }


    // Key Presses
    else if (vtkCommand::KeyPressEvent == eventId){
        vtkRenderWindowInteractor *iren = static_cast<vtkRenderWindowInteractor *>(caller);
        if (*(iren->GetKeySym()) == 'a') {
            mp_vis.clear();
            mp_vis.update();
        }
        if (*(iren->GetKeySym()) == 'c') {
            mp_vis.clear();
            mp_vis.update();
        }
        if (*(iren->GetKeySym()) == 'u') {
            m_cathEn = true;
        }
        if (*(iren->GetKeySym()) == 'j') {
            m_q(0,0) = m_q(0,0) + m_cath.g_q1change();
            std::cout << m_q(0,0) << std::endl;
            m_cathEn = true;
        }
        if (*(iren->GetKeySym()) == 'l') {
            m_q(0,0) = m_q(0,0) - m_cath.g_q1change();
            m_cathEn = true;
        }
        if (*(iren->GetKeySym()) == 'm') {
            m_q(1,0) = m_q(1,0) + m_cath.g_q2change();
            m_cathEn = true;
        }
        if (*(iren->GetKeySym()) == 'n') {
            m_q(1,0) = m_q(1,0) - m_cath.g_q2change();
            m_cathEn = true;
        }
        if (*(iren->GetKeySym()) == 'k') {
            m_q(2,0) = m_q(2,0) + m_cath.g_q3change();
            m_cathEn = true;
        }
        if (*(iren->GetKeySym()) == 'h') {
            m_q(2,0) = m_q(2,0) - m_cath.g_q3change();
            m_cathEn = true;
        }
        // Test scenario interactions
        if (strcmp((iren->GetKeySym()), "Up") == 0) {}
        if (strcmp((iren->GetKeySym()), "Down") == 0) {}
        if (strcmp((iren->GetKeySym()), "Left") == 0) {}
        if (strcmp((iren->GetKeySym()), "Right") == 0) {}
        if (strcmp((iren->GetKeySym()), "Return") == 0) {
            m_aortaEn = true;
        }
    }
    
}
