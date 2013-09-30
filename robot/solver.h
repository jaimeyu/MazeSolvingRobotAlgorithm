#ifndef SOLVER_H_
#define SOLVER_H_

//#include <iostream>
//#include <string.h> maybe


//using namespace std;

class solver
{
public:
 	//constructor
	solver(); 

	//timer(); //need time.h
	
	//mapping functions
	void push(int, int, int);
	void pop(); //throwaway
	
	//char *nextblock();
	
	bool Check4Duplicate(int, int, int);
	
	//Competition functions
	int NextMove(int); //first checks direction and then returns if 0, fwd, 1, right, 2, left turn
	
	int NextX();
	int NextY();
	int NextDir();
	
	void competition_pop();
	
	void printout();

private:

	int pathx[127]; //can be any amount!
	int pathy[127];
	int direction[127];
	int move;
	
	int aLoc;//current location in array
		

};

#endif /*SOLVER_H_*/

