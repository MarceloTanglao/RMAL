

// FOR ENCODER
void read_encoder(){
  // READING ENCODERS: 
    // - LINEAR TRANSLATION
    long np1 = ASSIST_LINEAR_ENCODER.read();
    if (np1 != np1O) {
      np1O = np1;
      p1 = np1;
      }

    // - BENDING
    long np2 = CATHETER_BENDING_ENCODER.read();
    if (np2 != np2O) {
      np2O = np2;
      p2 = np2;
      }

    // - ROTATION
      long np3 = ASSIST_ROTATION_ENCODER.read();
      if (np3 != np3O) {
      np3O = np3;
      p3 = np3;
      }

      // - ROTATION
      long np4 = CATHETER_ROTATION_ENCODER.read();
      if (np4 != np4O) {
      np4O = np4;
      p4 = np4;
      }



    Serial.print(p1);
    Serial.print(" ");
    Serial.print(p2);
    Serial.print(" ");
    Serial.print(p3);
    Serial.print(" ");
    Serial.println(p4);
}

// FOR LINEAR ACTUATOR
  void ACTUATOR_FORWARD(int steps){
    int i;
    digitalWrite(ENAPIN,HIGH);//ENABLE IS ACTIVE HIGH
    digitalWrite(DIRPIN,HIGH);//SET DIRECTION 
    for(i=0;i<steps;i++){
      digitalWrite(STEPPIN,HIGH);
      delayMicroseconds(STEPTIME);
      digitalWrite(STEPPIN,LOW);
      delayMicroseconds(STEPTIME);
    }
    digitalWrite(ENAPIN,LOW);//DISABLE STEPPER


     
      
  }
  void ACTUATOR_BACKWARD(int steps){
    int i;
    digitalWrite(ENAPIN,HIGH);//ENABLE IS ACTIVE HIGH
    digitalWrite(DIRPIN,LOW);//SET DIRECTION 
    for(i=0;i<steps;i++){
      digitalWrite(STEPPIN,HIGH);
      delayMicroseconds(STEPTIME);
      digitalWrite(STEPPIN,LOW);
      delayMicroseconds(STEPTIME);
    }
    digitalWrite(ENAPIN,LOW);//DISABLE STEPPER
  }


// FOR CATHETER ASSEMBLY
void CATHETER_BENDING_CW(int duration){
    analogWrite(CATHERER_BENDING_PWM_PIN,255);
    digitalWrite(CATHETER_BENDING_DIR_A_PIN, HIGH);
    digitalWrite(CATHETER_BENDING_DIR_B_PIN, LOW); 
    delay(duration);
    analogWrite(CATHERER_BENDING_PWM_PIN,0);
    digitalWrite(CATHETER_BENDING_DIR_A_PIN, LOW);
    digitalWrite(CATHETER_BENDING_DIR_B_PIN, LOW);
}
void CATHETER_BENDING_CCW(int duration){
    analogWrite(CATHERER_BENDING_PWM_PIN,255);
    digitalWrite(CATHETER_BENDING_DIR_A_PIN, LOW);
    digitalWrite(CATHETER_BENDING_DIR_B_PIN, HIGH); 
    delay(duration);
    analogWrite(CATHERER_BENDING_PWM_PIN,0);
    digitalWrite(CATHETER_BENDING_DIR_A_PIN, LOW);
    digitalWrite(CATHETER_BENDING_DIR_B_PIN, LOW);
}
void CATHETER_ROTATING_CW(int duration) {
  analogWrite(CATHETER_ROTATION_PWM_PIN,255);
  digitalWrite(CATHETER_ROTATION_DIR_A_PIN, HIGH);
  digitalWrite(CATHETER_ROTATION_DIR_B_PIN, LOW); 
  delay(duration);
  analogWrite(CATHETER_ROTATION_PWM_PIN,0);
  digitalWrite(CATHETER_ROTATION_DIR_A_PIN, LOW);
  digitalWrite(CATHETER_ROTATION_DIR_B_PIN, LOW);
} 
void CATHETER_ROTATING_CCW(int duration) {
  analogWrite(CATHETER_ROTATION_PWM_PIN,255);
  digitalWrite(CATHETER_ROTATION_DIR_A_PIN, LOW);
  digitalWrite(CATHETER_ROTATION_DIR_B_PIN, HIGH); 
  delay(duration);
  analogWrite(CATHETER_ROTATION_PWM_PIN,0);
  digitalWrite(CATHETER_ROTATION_DIR_A_PIN, LOW);
  digitalWrite(CATHETER_ROTATION_DIR_B_PIN, LOW);
}



// FOR ASSIST SUBASSEMBLY
void ASSIST_LINEAR_FORWARD(int duration) {
    analogWrite(ASSIST_LINEAR_PWM_PIN,255);
    digitalWrite(ASSIST_LINEAR_DIR_A_PIN, HIGH);
    digitalWrite(ASSIST_LINEAR_DIR_B_PIN, LOW); 
    delay(duration);
    analogWrite(ASSIST_LINEAR_PWM_PIN,0);
    digitalWrite(ASSIST_LINEAR_DIR_A_PIN, LOW);
    digitalWrite(ASSIST_LINEAR_DIR_B_PIN, LOW);
}

void ASSIST_LINEAR_BACKWARD(int duration) {
  analogWrite(ASSIST_LINEAR_PWM_PIN,255);
  digitalWrite(ASSIST_LINEAR_DIR_A_PIN, LOW);
  digitalWrite(ASSIST_LINEAR_DIR_B_PIN, HIGH); 
  delay(duration);
  analogWrite(ASSIST_LINEAR_PWM_PIN,0);
  digitalWrite(ASSIST_LINEAR_DIR_A_PIN, LOW);
  digitalWrite(ASSIST_LINEAR_DIR_B_PIN, LOW);
}

void ASSIST_ROTATING_CW(int duration) {
  analogWrite(ASSIST_ROTATION_PWM_PIN,255);
  digitalWrite(ASSIST_ROTATION_DIR_A_PIN, HIGH);
  digitalWrite(ASSIST_ROTATION_DIR_B_PIN, LOW); 
  delay(duration);
  analogWrite(ASSIST_ROTATION_PWM_PIN,0);
  digitalWrite(ASSIST_ROTATION_DIR_A_PIN, LOW);
  digitalWrite(ASSIST_ROTATION_DIR_B_PIN, LOW);
}
  
void ASSIST_ROTATING_CCW(int duration) {
  analogWrite(ASSIST_ROTATION_PWM_PIN, 255);
  digitalWrite(ASSIST_ROTATION_DIR_A_PIN, LOW);
  digitalWrite(ASSIST_ROTATION_DIR_B_PIN, HIGH); 
  delay(duration);
  analogWrite(ASSIST_ROTATION_PWM_PIN,0);
  digitalWrite(ASSIST_ROTATION_DIR_A_PIN, LOW);
  digitalWrite(ASSIST_ROTATION_DIR_B_PIN, LOW); 
}
