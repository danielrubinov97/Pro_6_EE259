#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>
#include "/ee259/tools/pro_5/sample_p5.h"

using namespace std;

ofstream output("out.6.txt", ios::out);

class LINEAR_SOLVER: public MATRIX{
   public:
	LINEAR_SOLVER(int);  
			// constructor; example: s.LINEAR_SOLVER(5);
			// there are 5 equations and 5 variables;

	void SOLVE_LINEAR_EQUATION(char *); 
			// example: s.SOLVE_LINEAR_EQUATION("ASCEND");
			// solve the linear equations and
			// sort the output in ascending order;
			// if the input is "DESCEND" then the order
			// of the output is descending;
			// returns no values;

	void SOLVE_BY_MATLAB(void); 
			// example: s.SOLVE_BY_MATLAB();
			// generate and run a MATLAB program to 
			// solve a set of linear equations;
			// returns no values;

	void INHERITED_INVERT(void); 
			// example: s.INHERITED_INVERT();
			// perform matrix inversion on
			// the input system by inheriting
			// from PROGRAM_BANK class;
			// returns no values;

	void INVERT_BY_MATLAB(void); 
			// example: s.INVERT_BY_MATLAB();
			// generate and run a MATLAB program to 
			// invert a matrix;
			// returns no values;
   private:
	int n; 		// max of n is 50
	float A[50][50];
	float B[50];
};

LINEAR_SOLVER::LINEAR_SOLVER(int x)
  	:MATRIX(x, x, "in.6.txt") 	// instantiate MATRIX with input file in.6.txt and 
  				// dim1=x, dim2=x;
{
	// your code for LINEAR_SOLVER constructor goes here
	n = x;
        // read the elements of A and B from in.6.txt
}
 
void 
LINEAR_SOLVER::SOLVE_LINEAR_EQUATION(char * commd)
{

}

void
LINEAR_SOLVER::SOLVE_BY_MATLAB()
{

}

void 
LINEAR_SOLVER::INHERITED_INVERT()
{
	// ...
	
	MATRIX temp_m(n, n,"in.6.txt"); // create a temp matrix from in.6.txt file;

	// ...
	1/temp_m; // use the friend function in MATRIX for inversion;
	// ...
}

void
LINEAR_SOLVER::INVERT_BY_MATLAB()
{

}
