/*
 * This file does some things.
 * 
 * File created by Phil Ring
 */ 

#include "Arduino.h"
#include "ArmClass.h"

// Constructors
RobotArm::RobotArm(int nDOF) { 
}

// Functions
void RobotArm::setUp() {
	base.attach(BASE_SERVO_PIN);
	elbow.attach(ELBOW_SERVO_PIN);
	hand.attach(HAND_SERVO_PIN);
	base.write(0); // start at 0
	elbow.write(0);
	hand.write(0);
	delay(15);
}
void RobotArm::moveJointToAngle(Servo servo, int servoNum, int angle, int step=1) {
	if (angle < 0 || angle > 180) return;

	if (pos[servoNum] < angle) {
		for (; pos[servoNum] <= angle; pos[servoNum] += step) {
			servo.write(pos[servoNum]); // maybe a delay?
		}
	} else {
		for (; pos[servoNum] > angle; pos[servoNum] -= step) {
			servo.write(pos[servoNum]);
		}
	}
}
void RobotArm::moveBaseToAngle(int angle, int step=1) {
	moveJointToAngle(base, 0, angle, step);
}
void RobotArm::moveElbowToAngle(int angle, int step=1) {
	moveJointToAngle(elbow, 1, angle, step);
}
void RobotArm::moveHandToAngle(int angle, int step=1) {
	moveJointToAngle(hand, 2, angle, step);
}

void RobotArm::moveJointByXDegrees(Servo servo, int servoNum, int deltaAngle, int step=1) {
	if (deltaAngle < 0 || deltaAngle > 180) return;

	if (deltaAngle >= 0) {
		for (int i=1; i <= deltaAngle; pos[servoNum] += step) {
			servo.write(pos[servoNum]);
		}
	} else {
		for (int i=1; i <= deltaAngle; pos[servoNum] -= step) {
			servo.write(pos[servoNum]);
		}
	}
}
void RobotArm::moveBaseByXDegrees(int deltaAngle, int step=1) {
	moveJointToAngle(base, 0, deltaAngle, step);
}
void RobotArm::moveElbowByXDegrees(int deltaAngle, int step=1) {
	moveJointToAngle(elbow, 1, deltaAngle, step);
}
void RobotArm::moveHandByXDegrees(int deltaAngle, int step=1) {
	moveJointToAngle(hand, 2, deltaAngle, step);
}


