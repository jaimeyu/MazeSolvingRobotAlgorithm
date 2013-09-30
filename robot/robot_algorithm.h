#ifndef ROBOT_ALGORITHM_H_
#define ROBOT_ALGORITHM_H_

#include <iostream>
#include <string>


using namespace std;

class robot_algorithm
{
public:
	//constructors
	
	robot_algorithm();
	virtual ~robot_algorithm();

	//end constructors
	
	//Variable calls
	
	bool SensorRight();
	bool SensorFront();
	bool isExitFound();
	void CurrentPosition();
	
	int current_x();
	int current_y();
	int current_dir();
	
	//End Variable calls
	
	//Functions
	
	void TurnRight();
	void TurnLeft();
	void DriveForward();
	
	
	//Graphical
	void DrawMaze();
	
	
	
	//Test function	
	void test();
	void clrscr();
	
	//End Functions

private:
	
	//int load_maze(); //returns the location of the robot starting position... ie: 27
	
	//Grab maze data from file.
	void MazeInitialize(); //IMPORTANT, MOVE THIS TO PRIVATE!!!! 
							//DANGEROUS IF MAIN() GETS ACCESS TO IT!!!
	
	int current_pos_x;
	int current_pos_y;
	int current_direction;
	bool exitFound;
	
	int maze_start_x;
	int maze_start_y;
	int maze_end_x;
	int maze_end_y;
	
	char* maze[11][11]; //create an array for the maze data. 
	
	int maze_max_x;
	int maze_max_y;
	
	
};

#endif /*ROBOT_ALGORITHM_H_*/
