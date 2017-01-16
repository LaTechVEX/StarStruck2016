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
Basic Autonomous
----------------------------------------------------------------------------------------------------*/

	//all the wheels stop moving
	void still()
	{
		motor[frontRight] = motor[backLeft]
											= motor[frontLeft]
											= motor[backRight] = 0;
	}

	//everything shuts off
	void die()
	{
		still();
		motor[armLT] = motor[armLB]
								 = motor[armRT]
								 = motor[armRB] = 0;
	}

//moves the robot forward (f) or backward (b)
	void move(char dir, int speed,int time)
	{
		//assume CW is + and CCW is -
		if(dir == 'f')
		{
			motor[frontRight] = motor[backLeft]  = -speed;
			motor[frontLeft]  = motor[backRight] = speed;
			wait1Msec(time);
		}
		else if (dir == 'b')
		{
			motor[frontRight] = motor[backLeft]  = speed;
			motor[frontLeft]  = motor[backRight] = -speed;
			wait1Msec(time);
		}
		else
			still();
	}

	//makes the robot turn left (l) or right (r)
	void turn(char dir, int speed, int time)
	{
		//assume CW/+ and CCW/-
		if(dir == 'l')
		{
			motor[frontRight] = motor[backLeft]
												= motor[frontLeft]
												= motor[backRight] = speed;
			wait1Msec(time);
		}
		else if (dir == 'r')
		{
			motor[frontRight] = motor[backLeft]
												= motor[frontLeft]
												= motor[backRight] = -speed;
			wait1Msec(time);
		}
		else
			still();
	}

	/*allows the robot to move diagonally to the
	forward right (fr), forward left (fl)
	backward right (br) or backward left (bl)
	*/
	void diag(string dir, int speed, int time)
	{
		//assume CW/+ and CCW/-
		if(strcmp(dir,"fl") == 0)
		{
			motor[frontRight] = -speed;
			motor[backLeft]   = speed;
			motor[frontLeft]  = motor[backRight] = 0;
			wait1Msec(time);
		}
		else if (strcmp(dir,"fr") == 0)
		{

			motor[frontLeft]  = speed;
			motor[backRight]  = -speed;
			motor[frontRight] = motor[backLeft] = 0;
			wait1Msec(time);
		}
		else if (strcmp(dir,"bl") == 0)
		{
			motor[frontLeft]  = -speed;
			motor[backRight] 	= speed;
			motor[frontRight] = motor[backLeft] = 0;
			wait1Msec(time);
		}
		else if (strcmp(dir,"br") == 0)
		{
			motor[frontRight] = speed;
			motor[backLeft]   = -speed;
			motor[frontLeft]  = motor[backRight] = 0;
			wait1Msec(time);
		}
		else
			still();
	}

	//move the arm
	void arm(int speed, int time)
	{
		//assume drop = - and lift = +
		motor[armLT] = motor[armLB]
								 = motor[armRT]
								 = motor[armRB] = speed;
		wait1Msec(time);
	}

	//void fling()

task main()
{

		int s = 128;
		int t = 1000;
		string mv[] = {"fl","fr","bl","br"};

		move('f',s,t);
		wait1Msec(5*t);
		//move('b',s,t);
		//wait1Msec(5*t);
		die();
		wait1Msec(3*t);
		turn('l',s,t);
		wait1Msec(5*t);
		//turn('r',s,t);
		//wait1Msec(5*t);
		diag(mv[0],s,t);
		wait1Msec(5*t);
		//diag(mv[3],s,t);
		//wait1Msec(5*t);
		//diag(mv[1],s,t);
		//wait1Msec(5*t);
		//diag(mv[2],s,t);
		//wait1Msec(5*t);
		//still();
		//wait1Msec(5*t);
		arm(s,t);
		wait1Msec(5*t);
		//arm(-s,t);
		die();
	}
