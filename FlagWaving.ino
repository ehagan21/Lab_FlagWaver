#include <AccelStepper.h>
//#define HALFSTEP 8

// Define a stepper and the pins it will use
AccelStepper *stepper = new AccelStepper(AccelStepper::DRIVER, 3, 2); // Defaults to AccelStepper::FULL4WIRE (4 pins) on 2, 3, 4, 5
AccelStepper *stepper2 = new AccelStepper(AccelStepper::DRIVER, 4, 5);

const int timeOn = 5000;
long LsetTime;
long RsetTime;

char inChar;

void setup()
{  
  LsetTime = 0;
  RsetTime = 0; 

  //stepper setup 
  stepper->setMaxSpeed(2500.0);
  stepper->setAcceleration(1000.0);
  stepper->setSpeed(2500.0);

  stepper2->setMaxSpeed(-2500.0);
  stepper2->setAcceleration(1000.0);
  stepper2->setSpeed(-2500.0);

  Serial.begin(115200);
}

void loop(){  
    if ((millis() - LsetTime) > timeOn){
      //do nothing
    }
    else{
      stepper->runSpeed();
    }

    if ((millis() - RsetTime)> timeOn){
      //do nothing
    }
    else{
      stepper2->runSpeed();
    }

    if (inChar == 'A'){
       LsetTime = millis();
       //Serial.println("start L!");
    }
    else if (inChar == 'B'){
       RsetTime = millis();
       //Serial.println("start R!");
    }
    else if (inChar == 'C'){
      LsetTime = millis();
      RsetTime = millis();
      //Serial.println("start Both!");
    }
}

void serialEvent(){
  while(Serial.available()){
    inChar = (char)Serial.read();
  }
}
