#include <iostream>
#include <fstream>
#include <string>
#include <windows.h> //this is for the Sleep() function.

#include "robot/robot_algorithm.h"
//#include "robot/robot_algorithm_oldworking.cpp"

#include "robot/solver.h"
//#include "robot/solver.cpp"


using namespace std;

int main()
{

 bool isExitFound = false;
 char garbage;
 
 solver maze;
 robot_algorithm Robot; //create an object called robot 
 
 robot_algorithm Robot2;

	//origin 
 maze.push(Robot.current_x(), Robot.current_y(), Robot.current_dir());


//Salutations
//
Robot1.clearscr(); //clearing the screen

cout << "         _______________________________________________________________________________________" <<endl;
cout << "        /   _______           _        ______   _______  _______        ___      ___           /\ " <<endl;
cout << "       /   (  ____ \|\     /|( (    /|(  __  \ (  ___  )(       )     //   ) ) //   ) )       /  \" <<endl;
cout << "      /    | (    \/| )   ( ||  \  ( || (  \  )| (   ) || () () |    //   / / //   / /       /   /" <<endl;
cout << "     /     | |      | |   | ||   \ | || |   ) || (___) || || || |   //   / / //   / /       /   /" <<endl;
cout << "    /      | | ____ | |   | || (\ \) || |   | ||  ___  || |(_)| |  ((___/ / ((___/ /       /   /" <<endl;
cout << "   /       | | \_  )| |   | || | \   || |   ) || (   ) || |   | |                         / 8 /" <<endl;
cout << "  /        | (___) || (___) || )  \  || (__/  )| )   ( || )   ( |                        / 0 /" <<endl;
cout << " /         (_______)(_______)|/    )_)(______/ |/     \||/     \|                       / 0 /" <<endl;
cout << "/______________________________________________________________________________________/ 2 /" <<endl;
cout << "|                                                                                      |  /" <<endl;
cout << "|______________________________________________________________________________________|_/" <<endl;


cout << endl;




cout << "Good afternoon Jaime." <<endl;
cout << "I am an simulation construct designed to virtually test maze algorithms." <<endl;
cout << "Today, I will be showing you a small test of my abilities." <<endl;

cout << "Created by Jaime Yu." <<endl;
cout << "Course: COEN 390" <<endl;
cout << "Group: Team Mobile Suit Gundam 390" <<endl;
cout << "Version: BETA" <<endl;
cout << "Distributable copy is found at: http://www.jaimeyu.com/" <<endl;


 // Mapping algorithm
 
 
 Robot.DrawMaze();
 
 cout << endl <<endl << "Gundam 00 Algorithm Simulation" <<endl <<endl;
 
 cout << "R = ROBOT" << endl;
 cout << "X = EXIT (Rendering error: There is a wall under X.)" << endl;
 cout << "Input 's' and then 'enter' to start" <<endl; //only useful for presentation.

 cin >> garbage;
 
 
 cout << endl << endl << "Mapping Phase Begins" << endl <<endl;
 
 Sleep(3000);
 
 do{
 	Robot.DrawMaze();
 	
 	Robot.CurrentPosition();
	//cin >> garbage;
 	Sleep(570);

	if ( !Robot.SensorRight() )
			{
				Robot.TurnRight(); 
								
			}
	else if ( Robot.SensorFront() )
 			{
 				Robot.TurnLeft();
 				
			}
	//else do nothing
	
	if (!Robot.SensorFront())
	{
		Robot.DriveForward();
		
		//check if robot has visited this block already
			maze.Check4Duplicate(Robot.current_x(), Robot.current_y(), Robot.current_dir() );
			
		//Push current block location into memory	
			maze.push(Robot.current_x(), Robot.current_y(), Robot.current_dir());
		
	}	
		
 	isExitFound = Robot.isExitFound();
 	//test++;
 	
 }while(!isExitFound);    //(!isExitFound);

//maze.printout();

//Robot.test();

Robot.DrawMaze();
cout << endl <<endl << "Exit has been found!! " <<endl <<endl;
Robot.CurrentPosition();

cout << "Mapping Phase is Finish." <<endl <<endl;

Sleep(3000);		
isExitFound = false;
	
	
	
	
	
	
	
	
	
// COMPETITION ALGORITHM
	
Robot.DrawMaze();
cout << endl << endl << "Competition Phase Begins" << endl <<endl;
		
Sleep(6000);

do{
	
 	Robot2.DrawMaze();
 	
 	Robot2.CurrentPosition();
	//cin >> garbage;
 	Sleep(570);
 	
 	
 	if (Robot2.current_dir() == maze.NextDir() )
 		{
 			Robot2.DriveForward();
 			maze.competition_pop();
 		}
 	else
 		Robot2.TurnRight();
 	
	/*
	if (maze.NextMove(Robot2.current_dir()) == 1)
		Robot2.TurnRight();
	else if (!Robot.SensorFront())
	{
		Robot2.DriveForward();
	}
		*/
 	isExitFound = Robot2.isExitFound();
 	
 }while(!isExitFound);    //(!isExitFound);		
		
	Robot2.DrawMaze();
cout << endl <<endl << "Exit has been found!! " <<endl <<endl;
		
cin >> garbage;

		return (0);
}

