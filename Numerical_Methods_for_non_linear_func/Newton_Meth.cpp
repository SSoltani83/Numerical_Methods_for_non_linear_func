//Newton_Meth.cpp defines is an implementation file for the functions defined in Newton_Neth.h
//Newton_Meth_Iteration(),Newton_Meth_Recursive and N_Recursive()
// To use the Newton's method we need to have 1 good guess close to the solution| the function and its derivative must be hard coded in the main source file
// This is the recursive relation Xnew=Xold-(F(Xold)/F'(Xold))
//where x_0 is the first guess solution(it must be a  good guess)


//Including Libraries and headrefiles
#include<iostream>
#include<iomanip>
#include"Newton_Meth.h"
using namespace std;


//Implementation of the Newton_Meth_Iteration()
 void Newton_Meth_Iteration (double x_0,double Tol_consec,double Tol_approx, double(*FuncToCall)(double), double (*Derivative_FuncToCall)(double))
{
	double x_new;
	double x_old;
	int counter=0;
	
	
	//Output statement for the header
	cout<<"NEWTON'S METHOD WITH ITERATIVE IMPLEMENTATION\n"<<endl;
	cout<<left<< setw(25)<<setfill(' ')<<"# of recursive calls";
	cout<<left<< setw(25)<<setfill(' ')<<"Temp_Solution x";
	cout<<left<< setw(1)<<setfill(' ')<<"Tol_approx="<<fixed<<setprecision(1)<<scientific<<Tol_approx;
	cout<<right<< setw(19)<<setfill(' ')<<"Tol_Consec="<<scientific<<Tol_consec<<endl;
	//defining x_new and x_old
	x_new=x_0;
	x_old=x_0-1;
	//looping using a while loop
	while (abs((*FuncToCall)(x_new)) >Tol_approx || (abs(x_new-x_old) > Tol_consec))
	{
		counter++;
		x_old=x_new;
		x_new=x_old-((*FuncToCall)(x_old)/(*Derivative_FuncToCall)(x_old));
	
	// Output statements of the result of the current iteration
		cout<<left<<fixed<<setw(25)<<setfill(' ')<<counter;
		cout<<left<<fixed<<setprecision(10)<<setw(28)<<setfill(' ')<<x_new;
		cout<<left<<fixed<<setprecision(10)<<setw(28)<<setfill(' ')<< abs((*FuncToCall)(x_new))<<abs(x_new-x_old)<<endl;
	
	}
	cout<<"Newton's method with x_0= "<<x_0<<" and iteratative implementation converged to :"<<x_new<<" after "<<counter<<" iterations!"<<endl;
		
};
 //Implementation of the N_Recursive() function that 
 //Will pass the first guess x_0 and the counter by reference
 void N_Recursive(double &x_old,double &x_new,double Tol_consec,double Tol_approx, int & counter, double (*funcTocall)(double), double (*Derivative_funcToCall)(double))
 {
	 if (Tol_consec>= abs(x_new-x_old) && Tol_approx>= abs((*funcTocall)(x_new))) // base case
	 {
		 cout<<"Newton's Method using recursive calls converged to "<<x_new<<" after "<<counter<<" recursive calls."<<endl;
	 }
	 else if (( Tol_consec<abs(x_new-x_old)) || (Tol_approx <abs((*funcTocall)(x_new))))
	 {
		 counter++;// incrementing the counter
		 x_old=x_new;
		 x_new= x_old- (*funcTocall)(x_old)/(*Derivative_funcToCall)(x_old); // defining the new x x_new-x_old-f(x_old)/f'(x_old)
		 // nice formated output of the counter, temporary x_new, Tol_approx, and Tol_consecutive errors
		 cout<<left<<fixed<<setw(25)<<setfill(' ')<<counter;
		 cout<<left<<fixed<<setprecision(10)<<setw(28)<<setfill(' ')<<x_new;
		 cout<<left<<fixed<<setprecision(10)<<setw(28)<<setfill(' ')<< abs((*funcTocall)(x_new))<<abs(x_new-x_old)<<endl;
		 
		 N_Recursive(x_old,x_new,Tol_consec,Tol_approx,counter,(*funcTocall),(*Derivative_funcToCall));
 
	 }
 };
	
	 //Implementation of the Newton_Meth_recursive() Function
	 void Newton_Meth_Recursive (double x_0,double Tol_consec, double Tol_approx, double(*funcTocall)(double),double (*Derivative_funcToCall)(double))
	 {

		double x_new;
		double x_old;
		int counter=0;//setting the counter equal to 0
		x_old=x_0-1;
		x_new=x_0;
		 //Output statement for the header
		cout<<"NEWTON'S METHOD WITH RECURSIVE IMPLEMENTATION\n"<<endl;
		cout<<left<< setw(25)<<setfill(' ')<<"# of recursive calls";
		cout<<left<< setw(25)<<setfill(' ')<<"Temp_Solution x";
		cout<<left<< setw(1)<<setfill(' ')<<"Tol_approx="<<fixed<<setprecision(1)<<scientific<<Tol_approx;
		cout<<right<< setw(19)<<setfill(' ')<<"Tol_Consec="<<scientific<<Tol_consec<<endl;
		//Calling the recursive function N_Recursive()
		N_Recursive(x_old,x_new,Tol_consec,Tol_approx,counter,(*funcTocall),(*Derivative_funcToCall));
	 };