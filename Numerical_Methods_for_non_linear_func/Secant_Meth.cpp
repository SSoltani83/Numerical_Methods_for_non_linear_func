//Secant_Meth.cpp is an implementation file for the functions defined in Secant_Neth.h
//Secant_Meth_Iteration(),Secant_Meth_Recursive and S_Recursive()
// To use the Secant method we need to have 2 good guesses close to the solution| the function and its derivative must be hard coded in the main source file
// This is the recursive relation Xnew=Xold-f(xold)*(xold-xoldest)/(f(xold)-f(xoldest))
//Where x_0 and x_1 are the first guesses

//Including Libraries and headrefiles
#include<iostream>
#include<iomanip>
#include"Secant_Meth.h"
using namespace std;

void Secant_Meth_Iteration (double x_0,double x_1,double Tol_consec, double Tol_approx,double(*FuncToCall)(double))
{
	//declaration of variables
	double x_new,x_old,x_oldest;
	int counter=0;
	//Defining x_new, x_old and x_oldest
	x_old=x_0;
	x_oldest=x_1;
	x_new= x_old -(*FuncToCall)(x_old)*(x_old-x_oldest)/((*FuncToCall)(x_old)-(*FuncToCall)(x_oldest));
	
	//Output statement for the header
	cout<<"SECANT METHOD WITH ITERATIVE IMPLEMENTATION\n"<<endl;
	cout<<left<< setw(25)<<setfill(' ')<<"# of recursive calls";
	cout<<left<< setw(25)<<setfill(' ')<<"Temp_Solution x";
	cout<<left<< setw(1)<<setfill(' ')<<"Tol_approx="<<fixed<<setprecision(1)<<scientific<<Tol_approx;
	cout<<right<< setw(19)<<setfill(' ')<<"Tol_Consec="<<scientific<<Tol_consec<<endl;

	//while loop
	while ((abs(x_new-x_old) > Tol_consec) || (abs((*FuncToCall)(x_new)) > Tol_approx))
	{
		counter++;
		x_oldest=x_old;
		x_old=x_new;
		x_new= x_old - (*FuncToCall)(x_old)*(x_old-x_oldest)/((*FuncToCall)(x_old)-(*FuncToCall)(x_oldest));
		//Output of each Iteration
		cout<<left<<fixed<<setw(25)<<setfill(' ')<<counter;
		cout<<left<<fixed<<setprecision(10)<<setw(28)<<setfill(' ')<<x_new;
		cout<<left<<fixed<<setprecision(10)<<setw(28)<<setfill(' ')<< abs((*FuncToCall)(x_new))<<abs(x_new-x_old)<<endl;

	}	
	cout<<"The Secant method with x_0= "<<x_0<<" and iteratative implementation converged to :"<<x_new<<" after "<<counter<<" iterations!"<<endl;
};

void S_Recursive(double &x_new,double &x_old, double &x_oldest,int &counter,const double Tol_consec,const double Tol_approx, double (*FuncToCall)(double))
{
	if ( (abs(x_new-x_old)<=Tol_consec) && (abs((*FuncToCall)(x_new))<=Tol_approx))
	{
		 cout<<"Secant Method using recursive calls converged to "<<x_new<<" after "<<counter<<" recursive calls."<<endl;
	}
	else
	{
		counter++;
		x_oldest=x_old;
		x_old=x_new;
		x_new= x_old - (*FuncToCall)(x_old)*(x_old-x_oldest)/((*FuncToCall)(x_old)-(*FuncToCall)(x_oldest));
		//Output of each Iteration
		cout<<left<<fixed<<setw(25)<<setfill(' ')<<counter;
		cout<<left<<fixed<<setprecision(10)<<setw(28)<<setfill(' ')<<x_new;
		cout<<left<<fixed<<setprecision(10)<<setw(28)<<setfill(' ')<< abs((*FuncToCall)(x_new))<<abs(x_new-x_old)<<endl;
		//Recursive call
		S_Recursive(x_new,x_old,x_oldest,counter,Tol_consec,Tol_approx,(*FuncToCall));
	}
};

void Secant_Meth_Recursive(double x_0, double x_1,double Tol_consec, double Tol_approx,double (*FuncToCall)(double))
{
	//declaration of variables
	double x_new, x_old,x_oldest;
	int counter=0;
	x_old=x_0;
	x_oldest=x_1;
	x_new= x_old - (*FuncToCall)(x_old)*(x_old-x_oldest)/((*FuncToCall)(x_old)-(*FuncToCall)(x_oldest));
	
	//Output statement for the header
	cout<<"SECANT METHOD WITH RECURSIVE IMPLEMENTATION\n"<<endl;
	cout<<left<< setw(25)<<setfill(' ')<<"# of recursive calls";
	cout<<left<< setw(25)<<setfill(' ')<<"Temp_Solution x";
	cout<<left<< setw(1)<<setfill(' ')<<"Tol_approx="<<fixed<<setprecision(1)<<scientific<<Tol_approx;
	cout<<right<< setw(19)<<setfill(' ')<<"Tol_Consec="<<scientific<<Tol_consec<<endl;
	// calling the recursive function
	S_Recursive(x_new,x_old,x_oldest,counter,Tol_consec,Tol_approx,(*FuncToCall));
}



		
