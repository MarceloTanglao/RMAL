#include <Encoder.h>
#define ENCODER_DO_NOT_USE_INTERRUPTS

const int STEPTIME = 1000; // in microseconds; controls the speed of the linear actuator

//  PIN LABELS
// char move1, move2, move3;

// CATHETER ASSEMBLY
  // BENDING
    long p2 = 0;             // Encoder Current Position   (internal)
    long np2O = 0;           // Encoder Previous Position  (internal)
    Encoder CATHETER_BENDING_ENCODER(CATHETER_BENDING_ENCODER_A_PIN, CATHETER_BENDING_ENCODER_B_PIN);  // Encoder Variable
  //
  // ROTATION
    long p4 = 0;             // Encoder Current Position   (internal)
    long np4O = 0;           // Encoder Previous Position  (internal)
    Encoder CATHETER_ROTATION_ENCODER(CATHETER_ROTATION_ENCODER_A_PIN, CATHETER_ROTATION_ENCODER_B_PIN);
//

// ASSIST ASSEMBLY

  // LINEAR TRANSLATION
    long p1 = 0;          // Encoder Current Position   (internal)
    long np1O = 0;        // Encoder Previous Position  (internal)
    Encoder ASSIST_LINEAR_ENCODER(ASSIST_LINEAR_ENCODER_A_PIN, ASSIST_LINEAR_ENCODER_B_PIN);  // Encoder Variable
  //

  // ROTATION
    long p3 = 0;            // Encoder Current Position   (internal)
    long np3O = 0;          // Encoder Previous Position  (internal)
    Encoder ASSIST_ROTATION_ENCODER(ASSIST_ROTATION_ENCODER_A_PIN, ASSIST_ROTATION_ENCODER_B_PIN);  // Encoder Variable
  //

//

uint64_t loop1Time100Hz = 0;
long ASSIST_LINEAR_ENCODER_POSITION = 0;
long ASSIST_ROTATION_ENCODER_POSITION = 0;
long CATHETER_BENDING_ENCODER_POSITION = 0;
long CATHETER_ROTATION_ENCODER_POSITION = 0;


double error_motor_1;
double ASSIST_ROTATION_THETA_ERROR;
double error_motor_3;
double error_motor_4;
double error_motor_5;


double Motor_1_Theta_Rad = 0;
double Motor_2_Theta_Rad = 0;
double Motor_3_Theta_Rad = 0;
double Motor_4_Theta_Rad = 0;
double Motor_5_Theta_Rad = 0;


double PI = 3.1415926535897932384626;

int P_constant = 1; 
int ENCODER_RESOLUTION = 100;



struct pos {
  double linear_position_1;
  double theta2;
  double theta3;
  double theta4;
  double linear_position_2;
};
typedef struct pos Pose;