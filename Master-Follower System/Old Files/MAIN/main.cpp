// includes
#include <mainloop.h>
#include <qlearning.h>
#include <visualizer.h>
#include <serial.h>

// stl
#include <array>
#include <cmath>
#include <iostream>

// vtk
#include <vtkCommand.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkRenderWindowInteractor.h>

// Eigen
#include <Eigen/Dense>

// Boost
#include <boost/asio.hpp>

int main(int argc, char **argv) {
    //if (argc >= 1) {}
   // if (strcmp(scen, "a1") == 0) {}

    //boost::asio::io_service ioservice;
    //boost::asio::serial_port serial(ioservice, "/dev/ttyACM0");
    //std::cout<< "/dev/ttyACM0\n";

    Visualizer vis;
    MainLoop eventLoop(vis);

    // Turn off warning messages to prevent them from spamming the terminal
    vtkObject::GlobalWarningDisplayOff();
    
    // Create Window Interactor
    vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    renderWindowInteractor->SetRenderWindow(vis.g_renderWindow());
    
    // Set up and start main loop
    renderWindowInteractor->UpdateSize(400, 400);
    vtkSmartPointer<vtkInteractorStyleTrackballCamera> style = vtkSmartPointer<vtkInteractorStyleTrackballCamera>::New();
    renderWindowInteractor->SetInteractorStyle(style);
    renderWindowInteractor->Initialize();
    renderWindowInteractor->CreateRepeatingTimer(0.01 * 1000.0);
    renderWindowInteractor->AddObserver(vtkCommand::TimerEvent, &eventLoop);
    renderWindowInteractor->AddObserver(vtkCommand::KeyPressEvent, &eventLoop);
    renderWindowInteractor->Start();

    return 1;
}

