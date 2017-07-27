/*
 * This file does some things.
 * 
 * File created by Phil Ring
 */ 

#ifndef ARMCLASS_H 
#define ARMCLASS_H

#include "Arduino.h"
#include <Servo.h> 

#define N_DOF 3
#define BASE_SERVO_PIN   9
#define ELBOW_SERVO_PIN  10
#define HAND_SERVO_PIN   11


class RobotArm {
private:
	int pos[3] = { 0, 0, 0};
	int desiredPos[99];

	Servo base;
	Servo elbow;
	Servo hand;

public:
	// Constructors
	RobotArm(int nDOF); 
	
	// Functions
	void setUp();

	void moveJointToAngle(Servo servo, int servoNum, int angle, int step=1);
	void moveBaseToAngle(int angle, int step=1); 
	void moveElbowToAngle(int angle, int step=1);
	void moveHandToAngle(int angle, int step=1);
	
	void moveJointByXDegrees(Servo servo, int servoNum, int deltaAngle, int step=1);
	void moveBaseByXDegrees(int deltaAngle, int step=1); 
	void moveElbowByXDegrees(int deltaAngle, int step=1);
	void moveHandByXDegrees(int deltaAngle, int step=1);

	// don't know how this will work yet..
//	void followMe() {
		// Start sequence
//	}


};


#endif // ARMCLASS_H





