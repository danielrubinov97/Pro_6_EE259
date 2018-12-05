<<<<<<< HEAD
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>
#include "sample_p5.h"
//#include "/ee259/tools/pro_5/sample_p5.h"


using namespace std;

#define LOG_START output<<"********** P6 BEGIN *************"<<endl
#define LOG_END output<<"*********** P6 END **************"<<endl

ofstream output("out.6", ios::out);

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
      LOG_START;
      int i,j;
      int acceptable = 1;
      n = x;
      ifstream input_file("in_6_1", ios::in);

      output<<"*** OUTPUT FROM P6_LINEAR_SOLVER:"<< endl;

      for (i=0;i<n;i++)
      {
            for (j=0;j<n;j++)
            {
                  input_file>>A[i][j];
                  if ((A[i][j]<-99)||(A[i][j]>99))
                  {
                        acceptable=0;
                   }
                  else {}
            }
      }
      for (i=0;i<n;i++)
      {
            input_file>>B[i];
            if ((B[i]<-99)||(B[i]>99))
            {
                   acceptable=0;
	    }
            else {}
       }
       if (acceptable==1)
       {
            output<<"*** INSTANTIATED AN OBJECT WITH "<<n<<" EQUATIONS"<<endl;
       }
       else 
       {
             output<<"Input Error."<<endl;
       }
       LOG_END;
}
 
void 
LINEAR_SOLVER::SOLVE_LINEAR_EQUATION(char * commd)
{
      LOG_START;
      int i,j,k,r,v;
      int FOUND=1;
      float temp;
      float X[50];
      
      for (i=0;i<n;i++)
      {
            
            if (A[i][i]==0)
            {
                  FOUND=0;
                  for (j=i+1;(j<n && FOUND==0);j++)
                  {
                        
                        if (A[j][i]!=0)
                        {
                              temp=B[i];
                              B[i]=B[j];
                              B[j]=temp;
                              for (k=0;k<n;k++)
                              {
                                    temp=A[i][k];
                                    A[i][k]=A[j][k];
                                    A[j][k]=temp;
                              }
                              FOUND=1;
                        }
                  }
                  if (FOUND==0)
                  {
                        output << "*** MY GAUSSIAN ELIMINATION SOLUTION: "<<endl;
                        output << "*** EQUATION IS SINGULAR"<<endl;
                  }
            }
            for (j=i+1;(j<n && FOUND==1);j++)
            {
                  float m;
                  m= (-A[j][i]/A[i][i]);
                  for (k=i;k<n;k++)
                  {
                        A[j][k] += m*A[i][k];
                  }
                  B[j]+= m*B[i];
            }
      }
      for (r=n-1; (r>=0 && FOUND!=0); r--)
      {
            float sum=0;
            for (v=n-1;v>r;v--)
            {
                  sum += A[r][v] * X[v];
            }
            X[r] = (B[r] -sum)/(A[r][r]);
      }
      
      if (FOUND==1)
      {                     
            
            if (strcmp(commd,"DESCEND")==0)
            {
                  int max_pos,temp_pos; 
                  int true_pos[50];
                  float max;
                  
                  for (i=0;i<n;i++)
                  {
                        true_pos[i]=i;
                  }
                  
                  for (i=0;i<n;i++)
                  {
                        max = X[i];
                        max_pos=i;
                        for (j=i;j<n;j++)
                        {
                              if (max < X[j])
                              {
                                    max = X[j];
                                    max_pos =j;
                              }
                        }
                        temp=X[i];
                        X[i]=X[max_pos];
                        X[max_pos]=temp;
                        temp_pos = true_pos[i];
                        true_pos[i] = true_pos[max_pos];
                        true_pos[max_pos]=temp_pos;
                  }
                  
                  output<< "*** MY GAUSSIAN ELIMINATION SOLUTION (SORTED IN DESCENDING ORDER):"<<endl;
                  for (i=0;i<n;i++)
                  {
                        output << "X[" <<true_pos[i] << "]= " << setprecision(2) << setiosflags(ios::fixed | ios::showpoint) << X[i]<<endl;
                  }
                  
                  
            
            
            }
            else if (strcmp(commd,"ASCEND")==0)
            {
                  
                  int min_pos,temp_pos; 
                  int true_pos[50];
                  float min;
                  
                  for (i=0;i<n;i++)
                  {
                        true_pos[i]=i;
                  }
                  
                  for (i=0;i<n;i++)
                  {
                        min = X[i];
                        min_pos=i;
                        for (j=i;j<n;j++)
                        {
                              if (min > X[j])
                              {
                                    min = X[j];
                                    min_pos =j;
                              }
                        }
                        temp=X[i];
                        X[i]=X[min_pos];
                        X[min_pos]=temp;
                        temp_pos = true_pos[i];
                        true_pos[i] = true_pos[min_pos];
                        true_pos[min_pos]=temp_pos;
                  }                                   
                  output<< "*** MY GAUSSIAN ELIMINATION SOLUTION (SORTED IN ASCENDING ORDER):"<<endl;
                  
                  for (i=0;i<n;i++)
                  {
                        output << "X[" << true_pos[i] << "]= " << setprecision(2) << setiosflags(ios::fixed | ios::showpoint) << X[i] << endl;
                  }
            
            }
            else 
            {
                  output<<"Input Error."<<endl;
            }
            
      }
      LOG_END;
}

void
LINEAR_SOLVER::SOLVE_BY_MATLAB()
{
      
      	LOG_START;
	int i,j;
      	ofstream out_62("out_62.m",ios::out);
      
      	out_62<< "A=[";
      for (i=0;i<n;i++)
      {
            for (j=0;j<n;j++)
            {     
                  if (j<n-1)
                  {
                        out_62 << A[i][j] << ",";
                  }
                  else
                  {
                        out_62 << A[i][j] << ";";
                  }
            }
      }
      	out_62 <<"];"<<endl;
	out_62<< "B=[";
      for (i=0;i<n;i++)
      {
            if (i<n-1)
            {
                  out_62 << B[i]<< ";";
            }
            else
            {
                  out_62 << B[i] << "];"<<endl;
            }
      }      
      
      
	out_62<< "X=inv(A)*B;"<<endl;
	out_62<< "fid=fopen('out.6','a')"<<endl;
	out_62<< "fprintf(fid,'*** RESULT FROM MATLAB (UNSORTED):\\n');"<<endl;
	out_62<< "for k=1:"<<n<<endl;
	out_62<< "fprintf(fid,'X[%d]= %3.2f\\n',k-1,X(k));"<<endl;
	out_62<< "end"<<endl;
	out_62<< "fprintf(fid,'*********** P6 END **************\\n');"<<endl;
      
        system("/bin/csh /ee259/tools/pro_6/run_out_62");
}

void 
LINEAR_SOLVER::INHERITED_INVERT()
{
	LOG_START;	

      	int i;
      	char out_file_5[5000]; //Next Version might put a vector function.
      
      	MATRIX temp_m(n, n,"in.6.txt");//temp matrix
      
      	1/temp_m; // For Matrix Inversion
      
      	ifstream input_file_count("out.5.txt", ios::in);
      
      	int numLines=0;
      
            
      while(!input_file_count.eof())
      {
	  input_file_count.getline(out_file_5,1000);
	  numLines++;
      }
      
      	input_file_count.close();
      
      	ifstream input_file_inv("out.5.txt", ios::in);
      
      	output<< "*** AFTER INHERITING FROM MATRIX CLASS, MY RESULT IS:" << endl;
      
      for (i=0; i<numLines; i++)
      {
	input_file_inv.getline(out_file_5,1000);
	if (i > (numLines-(n+8)) && i < (numLines-1))
	{
	    output << out_file_5 << endl;
	}
	
      }
	LOG_END;     
}

void
LINEAR_SOLVER::INVERT_BY_MATLAB()
{
 	LOG_START;
 
      	int i,j;
      
      
      	ofstream out_63("out_63.m",ios::out);
      	out_63<< "A=[";
      for (i=0;i<n;i++)
      {
            for (j=0;j<n;j++)
            {     
                  if (j<n-1)
                  {
                        out_63 << A[i][j] << ",";
                  }
                  else
                  {
                        out_63 << A[i][j] << ";";
                  }
            }
      }
      	out_63 <<"];"<<endl;
      
      	out_63<< "X=inv(A);"<<endl;
      	out_63<< "fid=fopen('out.6','a')"<<endl;
      	out_63<< "fprintf(fid,'*** INVERSION RESULT FROM MATLAB:\\n');"<<endl;
      	out_63<< "for k=1:"<<n<<endl;
      	out_63<< "for l=1:"<<n<<endl;
      	out_63<< "fprintf(fid,'X[%d][%d]= %3.2f ',k-1,l-1,X(k,l));"<<endl;
      	out_63<< "end"<<endl;
      	out_63<< "fprintf(fid,'\\n');"<<endl;
      	out_63<< "end"<<endl;
      	out_63<< "fprintf(fid,'*********** P6 END **************\\n');"<<endl;
      
      	system("/bin/csh /ee259/tools/pro_6/run_out_63");
}
=======
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
>>>>>>> 10e14fd2c02e71710edc4f2f07a9c243a5e766f9
