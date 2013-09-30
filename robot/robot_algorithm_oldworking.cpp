#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include "robot_algorithm.h"

using namespace std;

//Definition for UP,LEFT,RIGHT,DOWN
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

//DEFINITION OF MAZE SIZE (REMEMBER TO +1 TO AMT SHOWN. 0 IS NUMBER!)
#define MAX_X 7
#define MAX_Y 7


//constructor
robot_algorithm::robot_algorithm()
{
	
	
	exitFound = false;
		
	maze_max_x = MAX_X; //max 4
	maze_max_y = MAX_Y; //max 2
	
	//initialize the maze data from file example.maze
	//cout << endl << "initializing" << endl;
	
	//backup;
	//for (int x=0;x<8;x++)
		for(int y=0; y<9;y++)
			maze[0][y] = "1111";
		
		//for(int x=0; y<9;y++)
			//maze[x][0] = "1111";
		
	
	for(int j=0; j<	10;j++)
		for (int x=1;x<10;x++)
			maze[x][j] = "0010";
	
	//MazeInitialize();
	
	//current_pos_x = maze_start_x;
	//current_pos_y = maze_start_y;
	
	
	//test code

	maze_start_x = 2;
	maze_start_y = 3;
	current_direction = UP;
	
	current_pos_x = maze_start_x;
	current_pos_y = maze_start_y;
	

	
	maze_end_x = 3;
	maze_end_y = 1;
	
	
	//maze[x][y]
	/* simple maze with two walls isnide
	maze[0][0] = "1001" ;
	maze[1][0] = "1100" ;
	maze[2][0] = "1001" ;
	maze[3][0] = "1100" ;
	maze[0][1] = "0011" ;
	maze[1][1] = "0010" ;
	maze[2][1] = "0110" ;
	maze[3][1] = "0111" ;
	*/
	
	//maze is trap
	//As qouted in Star Wars
	// "ITS A TRAP!"
	maze[0][0] = "1001" ;
	maze[1][0] = "1100" ;
	maze[2][0] = "1001" ;
	maze[3][0] = "1100" ;
	
	maze[0][1] = "0101" ;
	maze[1][1] = "0011" ;
	maze[2][1] = "0110" ;
	maze[3][1] = "0111" ;
	
	maze[0][2] = "0001" ;
	maze[1][2] = "1100" ;
	maze[2][2] = "1001" ;
	maze[3][2] = "1100" ;
	
	maze[0][3] = "0111" ;
	maze[1][3] = "0011" ;
	maze[2][3] = "0110" ;
	maze[3][3] = "0101" ;
	
	maze[0][4] = "1011" ;
	maze[1][4] = "1100" ;
	maze[2][4] = "1001" ;
	maze[3][4] = "0100" ;
	
	maze[0][5] = "1111" ;
	maze[1][5] = "0011" ;
	maze[2][5] = "0110" ;
	maze[3][5] = "0111" ;
	
}

robot_algorithm::~robot_algorithm()
{	
}

//End Constructor

	//Variable calls
	
	bool robot_algorithm::SensorRight()
	{
		if (current_direction == UP && maze[current_pos_x][current_pos_y][RIGHT] == '1' )
			return true;
		else if(current_direction == RIGHT && maze[current_pos_x][current_pos_y][DOWN] == '1' )
			return true;
		else if (current_direction == LEFT && maze[current_pos_x][current_pos_y][UP] == '1' )
			return true;
		else if (current_direction == DOWN && maze[current_pos_x][current_pos_y][LEFT] == '1' )
			return true;
		else
		{
			return false;
			//cout << endl << current_pos_x << " " << current_pos_y << endl;
		}	
	}
	

	bool robot_algorithm::SensorFront()
	{
		if (current_direction == UP && maze[current_pos_x][current_pos_y][UP] == '1' )
			return true;
		else if(current_direction == RIGHT && maze[current_pos_x][current_pos_y][RIGHT] == '1' )
			return true;
		else if (current_direction == LEFT && maze[current_pos_x][current_pos_y][LEFT] == '1' )
			return true;
		else if (current_direction == DOWN && maze[current_pos_x][current_pos_y][DOWN] == '1' )
			return true;
		else
			return false;
	}


	bool robot_algorithm::isExitFound()
	{
		if (current_pos_x == maze_end_x && current_pos_y == maze_end_y)
		{
			return true;
			//cout << endl << "Maze location is now: [" << current_pos_x << "], [" << current_pos_y << "]" << endl;	
		}
		else
			return false;	
	}	
	//End Variable calls
	
	//Functions
	
	void robot_algorithm::TurnRight()
	{
		cout << endl << "ROBOT IS TURNING RIGHT!" << endl;
		
		if (current_direction == UP)
			current_direction = RIGHT;
		else if (current_direction == RIGHT)
			current_direction = DOWN;
		else if (current_direction == LEFT)
			current_direction = UP;
		else if (current_direction == DOWN)
			current_direction = LEFT;
		else
			{
				cout << endl << "ROBOT ENOUNTERED AN ERROR TURNING RIGHT" << endl;
				current_direction = UP;  
			}
	}

	void robot_algorithm::TurnLeft()
	{
		cout << endl << "ROBOT IS TURNING LEFT!" << endl;
		
		if (current_direction == UP)
			current_direction = LEFT;
		else if (current_direction == RIGHT)
			current_direction = UP;
		else if (current_direction == LEFT)
			current_direction = DOWN;
		else if (current_direction == DOWN)
			current_direction = RIGHT;
		else
			{
				cout << endl << "ROBOT ENOUNTERED AN ERROR TURNING LEFT" << endl;
				current_direction = UP;  
			}
			
	}

	void robot_algorithm::DriveForward()
	{
		cout << endl << "ROBOT IS DRIVING FORWARD!" << endl;
		if (current_direction == UP)
			current_pos_y--;
		else if (current_direction == RIGHT)
			current_pos_x++;
		else if (current_direction == LEFT)
			current_pos_x--;
		else if (current_direction == DOWN)
			current_pos_y++;
		else
			{
				//cout << endl << "ROBOT ENOUNTERED AN ERROR TURNING LEFT" << endl;
				current_direction = UP;  
			}
			
		//cout << endl << "Maze location is now: [" << current_pos_x << "], [" << current_pos_y << "]" << endl;
		//cout << endl << "Current Direction is " << current_direction << endl; 
	}	
	
	
	void robot_algorithm::CurrentPosition()
	{
		char *current_direction_word;
		
		switch (current_direction)
		{
			case 0:
				current_direction_word = "UP";
				break;
			case 1:
				current_direction_word = "RIGHT";
				break;
			case 2:
				current_direction_word = "DOWN";
				break;
			case 3:
				current_direction_word = "LEFT";
				break;
			default:	
				current_direction_word = "ERROR";
				break;
		}
		
		cout << endl << "Robot is in [X,Y] location: [" << current_pos_x << "], [" << current_pos_y << "]" << endl;
		cout << "Robot is facing " << current_direction_word << endl; 
		
	}
	
	
	void robot_algorithm::test() //DELETE THIS LATER
	{
		for (int y = 0; y <= maze_max_y ; y++)
			for(int x = 0; x <= maze_max_x ; x++)
				{cout << maze[y][x] << endl;}
		
		for (int i = 0; i <=4 ; i++)		
		cout << endl << maze[1][0][i] <<endl;
		
		 char poop = maze[0][0][UP];
		
		cout << poop;
		
		if (poop == '1')
			cout << "YES" <<endl;
		else
			cout << "NO" <<endl;
		
	}
	
	

	void robot_algorithm::MazeInitialize()
	{
			
	}
			
	
	void robot_algorithm::DrawMaze()
	{
		clrscr();

		cout << " ";
		
		for (int j =0; j < 4; j++)
			{
			cout << j << "___";
			if (j == 3)
				cout << j+1 << endl;
				
				
			}
			
		
		for (int y= 0; y < 24; y++)
			for (int x = 0 ; x < 4 ; x++)
				{

					
					if (x == 0 && ( y = 0 || 4 || 8 || 12 || 16 || 20 ) )
						cout << y << "|";
					
					if ( y % 4 != 0)
						cout << "   ";

					else if (current_pos_x == x && current_pos_y == y/4)
						cout << " R ";

					else if (x == maze_end_x && y/4 == maze_end_y)	
						cout << " X";

					else if (maze[x][y/4][DOWN] == '1')	
						cout << "___";

					else 

						cout << "   "; 
					
					if (maze[x][y/4][RIGHT] == '1')	
						cout << "|";

					else 
						cout << "  ";
					
						
					
					if (x == 3)
						cout <<endl;
					
				}
	}
	
	
	int robot_algorithm::current_x()
	{
		return current_pos_x;
		
	}
	
		int robot_algorithm::current_y()
	{
		return current_pos_y;
		
	}
	
		int robot_algorithm::current_dir()
	{
		return current_direction;
		
	}
	
	//End Functions
	
		void robot_algorithm::clrscr() 
{ 
    COORD coordScreen = { 0, 0 }; 
    DWORD cCharsWritten; 
    CONSOLE_SCREEN_BUFFER_INFO csbi; 
    DWORD dwConSize; 
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 
    
    GetConsoleScreenBufferInfo(hConsole, &csbi); 
    dwConSize = csbi.dwSize.X * csbi.dwSize.Y; 
    FillConsoleOutputCharacter(hConsole, TEXT(' '), dwConSize, 
        coordScreen, &cCharsWritten); 
    GetConsoleScreenBufferInfo(hConsole, &csbi); 
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, 
        coordScreen, &cCharsWritten); 
    SetConsoleCursorPosition(hConsole, coordScreen); 
}
