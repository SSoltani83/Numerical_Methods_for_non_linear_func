//Source.cpp
//This is our main file. From here we will call all our functions to see how they work

//Including libraries and headerfiles
#include<iostream>
#include<cmath>
#include"Bisection_Meth.h"
#include"Newton_Meth.h"
#include"Secant_Meth.h"
// Using macros to define the tolerance interval and Tolerance_Approxaimation. In reality we could make it up to the user as an input parameter in the functions.
#ifndef Tolerance_interval 
#define Tolerance_interval (pow(10,-6))
#endif
#ifndef Tolerance_consec
#define Tolerance_consec (pow(10,-6))
#endif
#ifndef Tolerance_Approx
#define Tolerance_approx (pow(10,-9))
#endif


using namespace std;

// Our function prototype
;
double dFx(double);
double Fx (double);

int main()
{
	
	//Function pointer declaration
	double (*N)(double);
	double (*dN)(double);
	
	N=Fx;
	dN=dFx;
	cout<<"								BISECTION METHOD"<<endl;
	// Calling Bisection_Meth_Iteration Function
	Bisection_Meth_Iteration(-3,-2,Tolerance_interval,Tolerance_approx,Fx);
	cout<<"\n"<<endl;
	
	// Calling Bisection_Meth_Recursive
	Bisection_Meth_Recursive(-3,-2,Tolerance_interval,Tolerance_approx,Fx);

	//Newton's Method
	cout<<"\n\n							NEWTON'S METHOD"<<endl;
	Newton_Meth_Iteration(-3,Tolerance_consec,Tolerance_approx,Fx,dFx);

	cout<<"\n"<<endl;
	Newton_Meth_Recursive(-3,Tolerance_consec,Tolerance_approx,Fx,dFx);

	//Secant Method
	cout<<"\n\n							SECANT METHOD"<<endl;
	//Calling Secant_Meth_Iteration
	Secant_Meth_Iteration(-3,-10,Tolerance_consec,Tolerance_approx,Fx);

	//Calling Secant_Meth_Recursive
	Secant_Meth_Recursive(-3,-10,Tolerance_consec,Tolerance_approx,Fx);

	return 0;
};

//The implementation of the function that we are looking forward to solve with newton or 
//Insert the function of which you would like to find a solution using Bisection method here......
double Fx (double x)
{
	return (pow(x,4)-5*pow(x,2)+4-(1/(1+exp(x*x*x))));
}
//insert the derivative of the function above here for newton approximation......
double dFx (double x)
{
	return (4*pow(x,3)-10*x+((3*pow(x,2)*exp(x*x*x))/(pow((1+exp(-x*x*x)),2))));
}

