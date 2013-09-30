#include <iostream>
#include "solver.h"


#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

using namespace std;

solver::solver()
{
	//do nothing.
	aLoc = 0;
	move = 1;
	
}

void solver::push(int x, int y, int dir)
{
	//cout << "push" <<endl;
	pathx[aLoc] = x;
	pathy[aLoc] = y;
	direction[aLoc] = dir;
	
	aLoc++;
}

void solver::pop()
{
	//cout << "pop" <<endl;
	pathx[aLoc] = 0;
	pathy[aLoc] = 0;
	direction[aLoc] = 0;
	aLoc--;
	
	
	aLoc--; //don't worry if it becomes negative
}

bool solver::Check4Duplicate(int x, int y, int dir)
{
	//cout << "CHECKING " << x<< " " <<y  <<endl;
	
	int duplicate = aLoc;
	bool duplicate_exists = false;
	
	if (aLoc != 0)
		for (int i = (aLoc - 1); i >= 0; i--)
			if (pathx[i] == x &&  pathy[i] == y)
				{
					duplicate_exists = true;
					duplicate = i;
				}
	
	if (aLoc != 0)
		for (int j = duplicate; j <= (aLoc-1); j++)
			pop();
	
	return duplicate_exists;
	
	
}

void solver::printout()
{
	for (int i = 0; i <aLoc; i++)
		cout << pathx[i] << pathy[i] << direction[i] << endl;
		//cout <<"what?";
}


int solver::NextMove(int dir)
{
	int instruction = 0;
	int temp = direction[move];
	
	int direction = 1;// 0: fwd, 1: right, 2: left
	if (dir == temp)
		{
			instruction = 0;
			pop();	
			
		}
	else
		instruction = 1;		
	
	move++;
	return instruction;	
}

int solver::NextX()
{
	return pathx[move];
}
	int  solver::NextY()
{
	return pathy[move];
}
	int  solver::NextDir()
{
	return direction[move];
}
	
	void  solver::competition_pop()
	{
		move++;
	}
