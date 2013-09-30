#include "robot_algorithm.h"
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

//Definition for UP,LEFT,RIGHT,DOWN
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

//DEFINITION OF MAZE SIZE (REMEMBER TO +1 TO AMT SHOWN. 0 IS NUMBER!)
#define MAX_X 11
#define MAX_Y 11


//constructor
robot_algorithm::robot_algorithm()
{
	current_direction = LEFT;
	
	exitFound = false;
		
	maze_max_x = MAX_X; //max 4
	maze_max_y = MAX_Y; //max 2
	
	//initialize the maze data from file example.maze
	cout << endl << "initializing" << endl;
	
	//backup;
	//for (int x=0;x<8;x++)
		for(int y=0; y<9;y++)
			maze[0][y] = "1111";
		
		//for(int x=0; y<9;y++)
			//maze[x][0] = "1111";
		
	
	for(int j=0; j<	10;j++)
		for (int x=1;x<10;x++)
			maze[x][j] = "1101";
	
	MazeInitialize();
	
	//current_pos_x = maze_start_x;
	//current_pos_y = maze_start_y;
	
	
	//test code
	
	current_pos_x = 1;
	current_pos_y = 1;
	
	maze_start_x = 1;
	maze_start_y = 1;
	
	maze_end_x = 3;
	maze_end_y = 6;
	
	
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
	/*
	//maze is trap
	maze[0][0] = "1001" ;
	maze[1][0] = "1100" ;
	maze[2][0] = "1001" ;
	maze[3][0] = "1100" ;
	maze[0][1] = "0111" ;
	maze[1][1] = "0011" ;
	maze[2][1] = "0110" ;
	maze[3][1] = "0111" ;
	*/
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
		cout << endl << "ROBOT TURNING RIGHT!" << endl;
		
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
		cout << endl << "ROBOT TURNING LEFT!" << endl;
		
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
		cout << endl << "ROBOT DRIVING DRIVING DRIVING!" << endl;
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
				cout << endl << "ROBOT ENOUNTERED AN ERROR TURNING LEFT" << endl;
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
		
		cout << endl << "Maze location is now: [" << current_pos_x << "], [" << current_pos_y << "]" << endl;
		cout << "Current Direction is " << current_direction_word << endl; 
		
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
			
			//fstream data ( "example.maze" );
			
		
			fstream data;
			 data.open ("example.maze", fstream::in | fstream::out | fstream::app);
			
			string temp;
			int inc_maze_x = 1;
			
		
			//getline(data,temp);
			//cout << endl << temp << "COUNT: " <<temp.size() <<endl;
			//getline(data,temp);
			//cout << endl << temp << "COUNT: " <<temp.size() <<endl;
			
			//int offset =0;
			//int x=1;
			//int inc_maze_x =0;
			
			//for (int y= 0; y < 9; y++)
				//for (int x = 0 ; x < 9 ; x++)
				//	cout<<maze[x][y]<<endl;
		
			
			for(int y=1;y<5;y++)
			{
				  
				getline(data,temp);
				cout << "copying in maze[][]" <<endl;
						
				for (int x= 0;x<12; x+=2)
					{
						
						//cout << (temp[x]);
						//cout << endl << x << y <<endl;
						//for y=0
						
						
						//the following does wrk when x = o && y = o
				//	/*
						if (  maze[inc_maze_x -1][y][RIGHT] =='1' && maze[x][y-1][DOWN] == '1' &&  temp[x] == '_' && temp[x+1] == '|')
							maze[inc_maze_x][y] = "1111";
						else if (  maze[inc_maze_x -1][y][RIGHT] =='1' && maze[x][y-1][DOWN] == '1' &&  temp[x] == '_' && temp[x+1] == ' ')
							maze[inc_maze_x][y] = "1011";
						else if (  maze[inc_maze_x -1][y][RIGHT] =='1' && maze[x][y-1][DOWN] == '1' &&  temp[x] == ' ' && temp[x+1] == '|')
							maze[inc_maze_x][y] = "1101";
						else if (  maze[inc_maze_x -1][y][RIGHT] =='1' && maze[x][y-1][DOWN] == '1' &&  temp[x] == ' ' && temp[x+1] == ' ')
							maze[inc_maze_x][y] = "1001";
						
						else if (  maze[inc_maze_x -1][y][RIGHT] =='1' && maze[x][y-1][DOWN] == '0' &&  temp[x] == '_' && temp[x+1] == '|')
							maze[inc_maze_x][y] = "0111";
						else if (  maze[inc_maze_x -1][y][RIGHT] =='1' && maze[x][y-1][DOWN] == '0' &&  temp[x] == '_' && temp[x+1] == ' ')
							maze[inc_maze_x][y] = "0011";
						else if (  maze[inc_maze_x -1][y][RIGHT] =='1' && maze[x][y-1][DOWN] == '0' &&  temp[x] == ' ' && temp[x+1] == '|')
							maze[inc_maze_x][y] = "0101";
						else if (  maze[inc_maze_x -1][y][RIGHT] =='1' && maze[x][y-1][DOWN] == '0' &&  temp[x] == ' ' && temp[x+1] == ' ')
							maze[inc_maze_x][y] = "0001";
						
						else if (  maze[inc_maze_x -1][y][RIGHT] =='0' && maze[x][y-1][DOWN] == '1' &&  temp[x] == '_' && temp[x+1] == '|')
							maze[inc_maze_x][y] = "1110";
						else if (  maze[inc_maze_x -1][y][RIGHT] =='0' && maze[x][y-1][DOWN] == '1' &&  temp[x] == '_' && temp[x+1] == ' ')
							maze[inc_maze_x][y] = "1010";
						else if (  maze[inc_maze_x -1][y][RIGHT] =='0' && maze[x][y-1][DOWN] == '1' &&  temp[x] == ' ' && temp[x+1] == '|')
							maze[inc_maze_x][y] = "1100";
						else if (  maze[inc_maze_x -1][y][RIGHT]=='0'  && maze[x][y-1][DOWN] == '1' &&  temp[x] == ' ' && temp[x+1] == ' ')
							maze[inc_maze_x][y] = "1000";
						
						else if (  maze[inc_maze_x -1][y][RIGHT] =='0' && maze[x][y-1][DOWN] == '0' &&  temp[x] == '_' && temp[x+1] == '|')
							maze[inc_maze_x][y] = "0110";
						else if (  maze[inc_maze_x -1][y][RIGHT] =='0' && maze[x][y-1][DOWN] == '0' &&  temp[x] == '_' && temp[x+1] == ' ')
							maze[inc_maze_x][y] = "0010";
						else if ( maze[inc_maze_x -1][y][RIGHT] =='0'  && maze[x][y-1][DOWN] == '0' &&  temp[x] == ' ' && temp[x+1] == '|')
							maze[inc_maze_x][y] = "0100";
						else if (  maze[inc_maze_x -1][y][RIGHT] =='0' && maze[x][y-1][DOWN] == '0' &&  temp[x] == ' ' && temp[x+1] == ' ')
							maze[inc_maze_x][y] = "0000";
						else
							maze[inc_maze_x][y] = "1111";
						
					//	*/	
							
							
						/*
							maze[inc_maze_x][0] = "1111";
						else if (y == 0 &&  temp[x] == ' ' && temp[x+1] == '|')
							maze[inc_maze_x][0] = "1101";
						else if (y == 0 &&  temp[x] == '_' && temp[x+1] == ' ')
							maze[inc_maze_x][0] = "1011";
						else //if (y == 0 &&  temp[x] == ' ' && temp[x+1] == ' ')
							maze[inc_maze_x][0] =  "1001";  //"1001";
							
						
						if ( temp[x] == '_' && temp[x+1] == '|')
							maze[inc_maze_x][y] = "1111";
						else if ( temp[x] == ' ' && temp[x+1] == '|')
							maze[inc_maze_x][y] = "1101";
						else if (temp[x] == '_' && temp[x+1] == ' ')
							maze[inc_maze_x][y] = "1011";
						else// if (y == 0 &&  temp[x] == ' ' && temp[x+1] == ' ')
							maze[inc_maze_x][y] =  "0000";  //"1001";
						*/
						//cout << inc_maze_x << y << "," <<maze[inc_maze_x][0] << endl;
						
						if (inc_maze_x == 8)
							 inc_maze_x =1;
						else						
							inc_maze_x++;	
							
						//cout <<"wgat the " << maze[LEFT][y][RIGHT] <<endl;		
						//else if (temp[x-1] =='|' &&  temp[x] == '_' && temp[x+1] == '|' && maze[inc_maze_x][y][DOWN] == '1')
						
						
						//code snip works great!
						//can't access i in maze[x][y][i]
						
						//if (temp[x] == '_')
							//maze[0][0] = "1011";
							//maze[1][0] = "1111";/
						
					}
				//cout << endl <<endl;
				
				/*
				
				for (int x =1 ; x < 14 ; x+=2)
					{	//offset+=16;	maze[2][0] = "1001" ;
							
						if (y == 0)
							{
							maze[x-1][y][UP] = '1';
							maze[x-1][y][LEFT] = '1';
							
							if ( temp[x-1] == '_')
								maze[x-1][y][DOWN] = '1';
							else
								maze[x-1][y][DOWN] = '0';
								
							if (temp[x] == '|')
								maze[x-1][y][RIGHT] = '1';
							else 
								maze[x-1][y][RIGHT] = '0';
					
							}
					
						else
							{
							
							if (maze[x-1][y-1][2] == '1')
								maze[x-1][y][0] = '1';
							else
								maze[x-1][y][0] = '0';
											
							if (temp[x-1] == '_')
								maze[x-1][y][2] = '1';
							else
								maze[x-1][y][2] = '0';
								
							if (temp[x] == '|')
								maze[x-1][y][1] = '1';
							else 
								maze[x-1][y][1] = '0';
					
							}
							
						
						
					}*/
			}
			cout <<endl;
			
			
			
			data.close();
			
		
	}
			
	
	void robot_algorithm::DrawMaze()
	{
		for (int j=0; j < 10; j++)
			{
			cout << " _";
			if (j == 9)
				cout <<endl;
			}
			
			//for (int y= 0; y < 9; y++)
				//for (int x = 0 ; x < 9 ; x++)
					//cout<<maze[x][y]<<endl;
		
		for (int y= 1; y < 9; y++)
			for (int x = 1 ; x < 9 ; x++)
				{
					/*
					if (maze[x+1][y][3] == '1')	
						cout << "|";
					else 
						cout << " ";
					*/
					
					//cout << maze[x][y];
					
					if (x == 1)
						cout << "|";
					
					
					if (current_pos_x == x-1 && current_pos_y == y-1)
						cout << "R";
					else if (maze[x][y][DOWN] == '1')	
						cout << "_";
					else 
						//cout << " h";
						cout << " "; 
					
					if (maze[x][y][RIGHT] == '1')	
						cout << "|";
					else 
						cout << " ";
					
						
					
					if (x == 8)
						cout <<endl;
					
				}
	}
	
	//End Functions
