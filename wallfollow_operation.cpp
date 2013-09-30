#include <iostream>
#include <fstream>
#include "robot/robot_algorithm.h"
#include "robot/robot_algorithm_oldworking.cpp"
//#include "robot/robot_algorithm.cpp"
#include <string.h>

#include "robot/solver.h"
#include "robot/solver.cpp"


using namespace std;

int main()
{

 bool isExitFound = false;
 char garbage;
 
 robot_algorithm Robot; //create an object called robot 
 
//Robot.DrawMaze();
 
 // TESTING MAZE DRAWER
 do{
 	Robot.DrawMaze();
 	
 	Robot.CurrentPosition();
	cin >> garbage;
 	

	if ( !Robot.SensorRight() )
			{
				Robot.TurnRight(); //AFTER IT TURNS RIGHT, it needs to set a boolean -- otherwise in a blank spacve, it will spin
				
				
			}
	else if ( Robot.SensorFront() )
 			{
 				Robot.TurnLeft();
 				
			}
	else 
			{
				
			}
	
	if (!Robot.SensorFront())
	{
		Robot.DriveForward();
		//Robot.CurrentPosition();
	}	
		
 	isExitFound = Robot.isExitFound();
 	//test++;
 	
 }while(!isExitFound);    //(!isExitFound);



//Robot.test();

Robot.DrawMaze();
cout << endl << "Exit has been found!! ";
Robot.CurrentPosition();
		
		
		
		
		return (0);
}
