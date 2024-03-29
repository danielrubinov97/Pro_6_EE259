# Pro_6_EE259
Seventh Project in EE259 C++ Course
\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_
\_                                                                    \_
\_   THE CITY COLLEGE OF NEW YORK, ELECTRICAL ENGINEERING DEPARTMENT  \_
\_                            EE259, Fall 2018                        \_
\_                                                                    \_
\_                              PROJECT 6                             \_
\_                                                                    \_
\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

PROJECT 6 DESCRIPTION:

Write a C++ class definition called LINEAR_SOLVER which will solve a set 
of linear equations.  You will inherit from a class called MATRIX
located in /ee259/tools/pro_6/sample_p5.h file. You should include this
file in your p6.h file.

class LINEAR_SOLVER: public MATRIX{
   public:
	LINEAR_SOLVER(int);  // constructor; example: s.LINEAR_SOLVER(5);
			// there are 5 equations and 5 variables;

	void SOLVE_LINEAR_EQUATION(char *); // example: s.SOLVE_LINEAR_EQUATION("ASCEND");
			// solve the linear equations and
			// sort the output in ascending order;
			// if the input is "DESCEND" then the order
			// of the output is descending;
			// returns no values;

	void SOLVE_BY_MATLAB(void); // example: s.SOLVE_BY_MATLAB();
			// generate and run a MATLAB program to 
			// solve a set of linear equations;
			// returns no values;

	void INHERITED_INVERT(void); // example: s.INHERITED_INVERT();
			// perform matrix inversion on
			// the input system by inheriting
			// from PROGRAM_BANK class;
			// returns no values;

	void INVERT_BY_MATLAB(void); // example: s.INVERT_BY_MATLAB();
			// generate and run a MATLAB program to 
			// invert a matrix;
			// returns no values;
   private:
	int n; 		// dimension of A max 50
	float A[50][50];
	float B[50];
};

// constructor code with inheritance:
LINEAR_SOLVER::LINEAR_SOLVER(int x)
  	:MATRIX(x, x, "in.6.txt") // instantiate MATRIX with input file in.6.txt
				// and dim1=x, dim2=x;
   { 	// your code for LINEAR_SOLVER constructor goes here
	n = x;
        // read the elements of A and B from in.6.txt
   }

The format of in.6.txt is as follows:

	a_00 a_01 ... a_0(n-1)  
	a_10 a_11 ... a_1(n-1)  
	...
	a_(n-1)0 a_(n-1)1 ... a_(n-1)(n-1) 
	b_0
	b_1
	...
	b_(n-1)

where a_ij, b_k are floating point numbers for the elements of A matrix and
B vector (0 < n < 50). Any element of A and B is between -99.00 and 99.00 
inclusive. The output to out.6.txt is:

	********** P6 BEGIN *************
	*** OUTPUT FROM P6_LINEAR_SOLVER: 
	*** INSTANTIATED AN OBJECT WITH n EQUATIONS
	*********** P6 END **************

\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_
 
The definition of SOLVE_LINEAR_EQUATION method is as follows:

       	s.SOLVE_LINEAR_EQUATION(DIRECTION);

where s is a object of class LINEAR_SOLVER and DIRECTION is a character string 
which can be either "ASCEND" or "DESCEND".  Use Gaussian Elimination method to 
solve the input system given in in.6.txt file. 

If the character string in command is "DESCEND", the output to out.6.txt is:
	
	********** P6 BEGIN *************
	*** MY GAUSSIAN ELIMINATION SOLUTION (SORTED IN DESCENDING ORDER):
	X[a]= s_k 
	.....
	X[k]= s_a
	*********** P6 END **************
	
where s_i is the floating point number (with 2 decimal digits) sorted in 
descending order.

If the character string in command is "ASCEND", the output to out.6.txt is:
	
	********** P6 BEGIN *************
	*** MY GAUSSIAN ELIMINATION SOLUTION (SORTED IN ASCENDING ORDER):
	X[a]= s_a 
	.....
	X[k]= s_k
	*********** P6 END **************
	
where s_i is the floating point number (with 2 decimal digits) sorted in 
ascending order.

In either case, if the input system is singular, out.6.txt format is:

	********** P6 BEGIN *************
	*** MY GAUSSIAN ELIMINATION SOLUTION:
	*** EQUATION IS SINGULAR
	*********** P6 END **************

\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

The definition of SOLVE_BY_MATLAB method is as follows:

		s.SOLVE_BY_MATLAB();

Generate an output file called out_62.m with the following content:  

	A=[a_11,...,a_1n;...;a_n1,...,a_nn];
	B=[b_1;...;b_n];
	X=inv(A)*B;
	fid=fopen('out.6.txt','a');
	fprintf(fid,'*** RESULT FROM MATLAB (UNSORTED):\n');
	for k=1:n
	fprintf(fid,'X[%d]=%6.2f\n',k-1,X(k));
	end

where the contents of A and B are populated based on the values of the private
variables of A and B. Similarly, private variable n is used for the value of n.

After creating this file, include the following code in your method:

        system("/bin/csh /ee259/tools/pro_6/run_out_62");
	
which will run your out_62.m file in MATLAB. The above MATLAB program will generate
the output to be written (appended) into out.6.txt file as follows:

	********** P6 BEGIN *************
	*** RESULT FROM MATLAB (UNSORTED):
	X[0]= s_0 
	...
	X[n-1]= s_n-1 
	*********** P6 END **************
	
There will not be any SOLVE_BY_MATLAB method calls for singular systems
since MATLAB may crash the system. You do not have to check for it.

\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

The definition of INHERITED_INVERT method is as follows:

		s.INHERITED_INVERT();

To invert a matrix in this method, you will inherit from a class called MATRIX 
located in /ee259/tools/pro_6/sample_p5.h file. 

In your INHERITED_INVERT method, you can perform matrix inversion from MATRIX
as follows:

	void LINEAR_SOLVER::INHERITED_INVERT()
   	{
		MATRIX temp_m(n, n,"in.6.txt"); // create a temp matrix from in.6.txt file;

		...
		1/temp_m; // use the friend function in MATRIX for inversion;
		...
   	}

Object of class MATRIX writes its output to out.5.txt file as follows:

	+++ P5 START +++++++++++++++++++++++++++++++++++++++++
	+++ P5_OUTPUT >>> CREATED A n X n MATRIX FROM in.6.txt
	+++ P5 END +++++++++++++++++++++++++++++++++++++++++++
	+++ P5 START +++++++++++++++++++++++++++++++++++++++++
	+++ P5_OUTPUT >>> THE RESULT OF 1 / X OPERATION IS:
	b_0_0   	b_0_1    ... b_0_d1-1
	...
	b_d1-1_0   	b_d1-1_1 ... b_d1-1_d1-1
      	+++ P5 END +++++++++++++++++++++++++++++++++++++++++++
      
You should read out.5.txt file to obtain the result. Then your output 
to out.6.txt file is:
	
	********** P6 BEGIN *************
	*** AFTER INHERITING FROM MATRIX CLASS, MY RESULT IS:
	+++ P5 START +++++++++++++++++++++++++++++++++++++++++
	+++ P5_OUTPUT >>> CREATED A n X n MATRIX FROM in.6.txt
	+++ P5 END +++++++++++++++++++++++++++++++++++++++++++
	+++ P5 START +++++++++++++++++++++++++++++++++++++++++
	+++ P5_OUTPUT >>> THE RESULT OF 1 / X OPERATION IS:
	b_0_0   	b_0_1    ... b_0_d1-1
	...
	b_d1-1_0   	b_d1-1_1 ... b_d1-1_d1-1
      	+++ P5 END +++++++++++++++++++++++++++++++++++++++++++
	*********** P6 END **************

In this output, the lines starting with +++ P5 START are read from 
out.5.txt file (as an output of MATRIX).  

IMPORTANT NOTE: YOU SHOULD COPY THESE LINES DIRECTLY FROM out.5.txt 
FILE. WE WILL CHANGE THE CONTENTS OF out.5.txt FILE DURING GRADING.

There will not be inversion attempts for singular matrices for simplicity.

\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

The definition of INVERT_BY_MATLAB method is as follows:

                s.INVERT_BY_MATLAB();

Generate an output file called out_63.m with the following content:

        A=[a_11,...,a_1n;...;a_n1,...,a_nn];
        X=inv(A);
        fid=fopen('out.6.txt','a');
        fprintf(fid,'*** INVERSION RESULT FROM MATLAB:\n');
        for i=1:n
        for j=1:n
        fprintf(fid,'X[%d][%d]=%6.2f ',i-1,j-1,X(i,j));
	end
	fprintf(fid,'\n');
        end
	
where the contents of A and B are populated based on the values of the private
variables of A and B. Similarly, private variable n is used for the value of n.

After creating this file, include the following code in your method:

        system("/bin/csh /ee259/tools/pro_6/run_out_63");

which will run your out_63.m file in MATLAB. The above MATLAB program will generate
the output to be written (appended) into out.6.txt file as follows:

	********** P6 BEGIN *************
	*** INVERSION RESULT FROM MATLAB:
	X[0][0]= s_00 X[0][1]= s_01 ...  X[0][n-1]= s_0n-1 
	...
	X[n-1][0]= s_n-10 X[n-1][1]= s_n-11 ...  X[n-1][n-1]= s_n-1n-1 
	*********** P6 END **************

\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

THERE ARE NO INPUT ERRORS FOR SIMPLICITY!!!

\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

::::::::::: EXAMPLE 1:::::::::::::::
// example of program: main6_1.cc
#include "p6.h"
int main()
{       LINEAR_SOLVER s(2);
        s.SOLVE_LINEAR_EQUATION("DESCEND");
        return 0;
}
=========== contents of in.6.txt: ===========
2  1
1 -1
4
-1
======== expected contents of out.6.txt: ========
********** P6 BEGIN *************
*** OUTPUT FROM P6_LINEAR_SOLVER: 
*** INSTANTIATED AN OBJECT WITH 2 EQUATIONS
*********** P6 END **************
********** P6 BEGIN *************
*** MY GAUSSIAN ELIMINATION SOLUTION (SORTED IN DESCENDING ORDER):
X[1]= 2.00
X[0]= 1.00
*********** P6 END **************	
::::::::::: EXAMPLE 2:::::::::::::::
// example of program: main6_2.cc
#include "p6.h"
int main()
{       LINEAR_SOLVER s(2);
        s.SOLVE_BY_MATLAB();
        return 0;
}
=========== contents of in.6.txt: ===========
2  1
1 -1
4
-1
======== expected contents of out_62.m: ========
A=[2,1;1,-1];
B=[4;-1];
X=inv(A)*B;
fid=fopen('out.6.txt','a');
fprintf(fid,'*** RESULT FROM MATLAB (UNSORTED):\n');
for k=1:2
fprintf(fid,'X[%d]=%6.2f\n',k-1,X(k));
end
======== expected contents of out.6.txt: ========
********** P6 BEGIN *************
*** OUTPUT FROM P6_LINEAR_SOLVER: 
*** INSTANTIATED AN OBJECT WITH 2 EQUATIONS
*********** P6 END **************
********** P6 BEGIN *************
*** RESULT FROM MATLAB (UNSORTED):
X[0]= 1.00
X[1]= 2.00
*********** P6 END **************
::::::::::: EXAMPLE 3:::::::::::::::
// example of program: main6_3.cc
#include "p6.h"
int main()
{
	LINEAR_SOLVER m1(2);
	m1.INHERITED_INVERT();
	return 0;
}
=========== contents of in.6.txt: ===========
2  1 
1 -1
4
-1
======== expected contents of out.5.txt (generated by MATRIX class): ========
+++ P5 START +++++++++++++++++++++++++++++++++++++++++
+++ P5_OUTPUT >>> CREATED A 2 X 2 MATRIX FROM in.6.txt
+++ P5 END +++++++++++++++++++++++++++++++++++++++++++
+++ P5 START +++++++++++++++++++++++++++++++++++++++++
+++ P5_OUTPUT >>> THE RESULT OF 1 / X OPERATION IS:
0.33 0.33
0.33 -0.67
+++ P5 END +++++++++++++++++++++++++++++++++++++++++++
======== expected contents of out.6.txt: ========
********** P6 BEGIN *************
*** OUTPUT FROM P6_LINEAR_SOLVER: 
*** INSTANTIATED AN OBJECT WITH 2 EQUATIONS
*********** P6 END **************
********** P6 BEGIN *************
*** AFTER INHERITING FROM MATRIX CLASS, MY RESULT IS:
+++ P5 START +++++++++++++++++++++++++++++++++++++++++
+++ P5_OUTPUT >>> CREATED A 2 X 2 MATRIX FROM in.6.txt
+++ P5 END +++++++++++++++++++++++++++++++++++++++++++
+++ P5 START +++++++++++++++++++++++++++++++++++++++++
+++ P5_OUTPUT >>> THE RESULT OF 1 / X OPERATION IS:
0.33 0.33
0.33 -0.67
+++ P5 END +++++++++++++++++++++++++++++++++++++++++++
*********** P6 END **************   
::::::::::: EXAMPLE 4:::::::::::::::
// example of program: main6_4.cc
#include "p6.h"
int main()
{
	LINEAR_SOLVER m1(2);
	m1.INVERT_BY_MATLAB();
	return 0;
}
=========== contents of in.6.txt: ===========
2  1 
1 -1
4
-1
======== expected contents of out_63.m ========
A=[2,1;1,-1];
X=inv(A);
fid=fopen('out.6.txt','a');
fprintf(fid,'*** INVERSION RESULT FROM MATLAB:\n');
for i=1:2
for j=1:2
fprintf(fid,'X[%d][%d]=%6.2f ',i-1,j-1,X(i,j));
end
fprintf(fid,'\n');
end
======== expected contents of out.6.txt: ========
********** P6 BEGIN *************
*** OUTPUT FROM P6_LINEAR_SOLVER: 
*** INSTANTIATED AN OBJECT WITH 2 EQUATIONS
*********** P6 END **************
********** P6 BEGIN *************	
*** INVERSION RESULT FROM MATLAB:
X[0][0]= 0.33 X[0][1]= 0.33 
X[1][0]= 0.33 X[1][1]= -0.67 
*********** P6 END **************
