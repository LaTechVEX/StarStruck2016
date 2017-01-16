#pragma config(Motor,  port2,           frontRight,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           backRight,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           frontLeft,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           backLeft,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           armLT,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           armLB,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           armRT,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           armRB,         tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*+++++++++++++++++++++++++++++++++++++++++++++| Notes |++++++++++++++++++++++++++++++++++++++++++++++
Mecanum Drive with Deadzone Thresholds
- This program allows you to remotely control a robot with mecanum wheels.
- The left joystick Y-axis controls the robot's forward and backward movement.
- The left joystick X-axis controls the robot's left and right movement.
- The right joystick X-axis controls the robot's rotation.
- This program incorportes a threshold/deadzone that allows very low Joystick values to be ignored.
This allows the robot to ignore values from the Joysticks when they fail to center at 0,
and provides a margin of error for the driver when they only want the robot to move in one axis.

[I/O Port]          [Name]              [Type]                [Description]
Motor Port 2        frontRight          VEX Motor             Front Right wheel
Motor Port 3        backRight           VEX Motor             Back Right wheel
Motor Port 4        frontLeft           VEX Motor             Front Left wheel
Motor Port 5        backLeft            VEX Motor             Back Left wheel

Arm Raise and Catapult
- This program allows you to control the movement of a robot's arm.
- The "6U" button raises the arm.
- The "6D" button lowers the arm.
- The "5U" button flings the catapult.
- The "5D" button resets the catapult to its resting positions.
- The "8" buttons are used to set off a set of predefined tasks.

[I/O Port]          [Name]              [Type]                [Description]
Motor Port 6				armLT								VEX Motor							Top Left arm
Motor Port 7				armLB								VEX Motor							Bottom Left arm
Motor Port 8				armRT								VEX Motor							Top Right arm
Motor Port 9				armRB								VEX Motor							Bottom Right arm
----------------------------------------------------------------------------------------------------*/

task main()
{
	//Create "deadzone" variables. Adjust threshold value to increase/decrease deadzone
	int X2 = 0, Y1 = 0, X1 = 0, threshold = 15;
	int speed[] = {0, 64, 128, 192, 256};
	//Loop Forever
	while(1 == 1)
	{
		//Create "deadzone" for Y1/Ch3
		if(abs(vexRT[Ch3]) > threshold)
			Y1 = vexRT[Ch3];
		else
			Y1 = 0;
		//Create "deadzone" for X1/Ch4
		if(abs(vexRT[Ch4]) > threshold)
			X1 = vexRT[Ch4];
		else
			X1 = 0;
		//Create "deadzone" for X2/Ch1
		if(abs(vexRT[Ch1]) > threshold)
			X2 = vexRT[Ch1];
		else
			X2 = 0;

		//Remote Control Commands for Wheels
		motor[frontRight] = Y1 + X2 - X1;//Ch3-Ch1-Ch4
		motor[backRight] =  Y1 + X2 + X1;//Ch3-Ch1+Ch4
		motor[frontLeft] = Y1 - X2 + X1;//Ch3+Ch1+Ch4
		motor[backLeft] =  Y1 - X2 - X1;//Ch3+Ch1-Ch4

		//Moving the Arm
		//if one potientiometer reads higher than the other, need to slow down
		//the motor and speed up the other; include a threshold
		if(vexRT[Btn6U])
		{
			//all motors will move at the same speed
			motor[armLT] = motor[armLB]
			= motor[armRT]
			= motor[armRB] = -speed[3];
		}
		else if(vexRT[Btn6D])
		{
			motor[armLT] = motor[armLB]
			= motor[armRT]
			= motor[armRB] = speed[3];
		}
		else
		{
			//tell the motors to stop
			motor[armLT] = motor[armLB]
			= motor[armRT]
			= motor[armRB] = speed[0];
		}

		//Moving the Catapult
		//if(vexRT[Btn5U])
		//{
		//}
		//else if(vexRT[Btn5D]
		//{
		//}
		//else
		//{
		//}

		//Presets
		//if(vexRT[Btn8U])
		//{
		//}
		//else if(vexRT[Btn8D])
		//{
		//}
		//else if(vexRT[Btn8L])
		//{
		//}
		//else if(vexRT[Btn8R])
		//{
		//}
		//else
		//{
		//}
		//
	}
}
