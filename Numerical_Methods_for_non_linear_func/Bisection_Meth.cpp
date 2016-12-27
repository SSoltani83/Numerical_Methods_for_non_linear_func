//Bisection_Meth.cpp defines the functions declared on Bisection_Meth.h
//Bisection_Meth_Iterration(), Bisection_Meth_Recursive() and B_recursive() functions
// Our functions take the argument and print each iteration or recursive call in a nice format just for demonstration purposes
//To use bisection Method we need to have at least 1 interval [a,b] in wich is located one solution such that f(a)*f(b)<0 | the function must be hard coded in the main source file 
//a: Is the leftside ofr the interval [a,b]
//b: Is the right side of the interval [a,b]
//Tol_interval: is the our tolerance interval for (a,b)/(2^n) is a one of the conditions to exit the loop or recursive call as needed
//Tol_approx: Is our tolerance approximation error for the convergence to a solution Max(|f(xl)|,|f(xr)|) how close to 0 would be ok. 
//(*FuncToCall) is our function pointer that would point to the function we would like to solve for at least 1 solution
//12/21/2016

//Including Libraries and headrefiles
#include<iostream>
#include<iomanip>
#include"Bisection_Meth.h"
using namespace std;

//Implementation of Bisection_Met_Iteration function
void Bisection_Meth_Iteration (double a,double b, double Tol_interval,double Tol_approx, double (*FuncToCall)(double))
{

	double x_m;// This would be our bisecting point on interval [a,b]
	double x_l=a;// x_l would be the left point on the new interval
	double x_r=b;//x_r would be the right point on the new interval
	unsigned int counter=0;//Just to keep track of iterations
	
	//Output statement for the header
	cout<<"BISECTION METHOD WITH ITERATIVE IMPLEMENTATION\n"<<endl;
	cout<<left<< setw(25)<<setfill(' ')<<"# of Iterations";
	cout<<left<< setw(25)<<setfill(' ')<<"Temp_Solution_x_m";
	cout<<left<< setw(1)<<setfill(' ')<<"Tol_approx="<<fixed<<setprecision(1)<<scientific<<Tol_approx;
	cout<<right<< setw(19)<<setfill(' ')<<"Tol_interval="<<fixed<<scientific<<setprecision(1)<<Tol_interval<<endl;

	// While loop 
	while ((abs(x_l-x_r) >  Tol_interval) || (max(abs((*FuncToCall)(x_l)),abs((*FuncToCall)(x_r))) >  Tol_approx))
	{
		x_m= (x_l+x_r)/2;// defining the midpoint interval [a,b]
		//if (fx(x_m)*f(x_l))<0 then f(x_r)=f(x_m). 
		if((*FuncToCall)(x_m)*(FuncToCall)(x_l) < 0)
		{ 
			counter++;// incrementing our count of iterations
			x_r=x_m;
			// Output statements of the result of the current iteration
			cout<<left<<fixed<<setw(25)<<setfill(' ')<<counter;
			cout<<left<<fixed<<setprecision(10)<<setw(28)<<setfill(' ')<<x_m;
			cout<<left<<fixed<<setprecision(10)<<setw(28)<<setfill(' ')<< abs(x_l-x_r)<<max(abs((*FuncToCall)(x_l)),abs((*FuncToCall)(x_r)))<<endl;
		}
		else //else x_l=x_m
		{
			counter++;//incrementing our iterations' counter
			x_l=x_m;
			//Output statement for the result of the current iteration
			cout<<left<<fixed<<setw(25)<<setfill(' ')<<counter;
			cout<<left<<fixed<<setprecision(10)<<setw(28)<<setfill(' ')<<x_m;
			cout<<left<<fixed<<setprecision(10)<<setw(28)<<setfill(' ')<< abs(x_l-x_r)<<max(abs((*FuncToCall)(x_l)),abs((*FuncToCall)(x_r)))<<endl;
			
		}
	}
	//coutput statement for the result
	cout<<"Bisection method using iteration on interval ["<<a<<","<<b<<"] converged to :"<<x_m<<" after "<<counter<<" iterations!"<<endl;
};

//Implementation for Bisection_Meth_Recursive used for printing header and introducing the recursive call counter. To count and print each recursive call we will call B_Recursive() function.
void Bisection_Meth_Recursive (double a,double b, double Tol_interval,double Tol_approx, double (*FuncToCall)(double))
{
	int counter=0;
	//output of the header (Basically This is the purpose of this function, just to have a nice clean output)
	cout<<"BISECTION METHOD WITH RECURSIVE IMPLEMENTATION\n"<<endl;
	cout<<left<< setw(25)<<setfill(' ')<<"# of Recursive Calls";
	cout<<left<< setw(25)<<setfill(' ')<<"Temp_Solution_x_m";
	cout<<left<< setw(1)<<setfill(' ')<<"Tol_approx="<<fixed<<setprecision(1)<<scientific<<Tol_approx;
	cout<<right<< setw(19)<<setfill(' ')<<"Tol_interval="<<fixed<<scientific<<setprecision(1)<<Tol_interval<<endl;
	//calling the recursive function B_Recursive that will actually do all the calculations and output each recursive call result
	B_Recursive(a,b,Tol_interval,Tol_approx,counter,(*FuncToCall));

}
//Implementation of the B_Recursive call function
//we will pass a,b and counter arguments by reference 
void B_Recursive (double &a,double &b,double Tol_interval,double Tol_approx,int &counter,double (*FuncToCall)(double))
{
	//if our conditions are satisfied (Both error are less than their respective tolerences)
	if ((abs(a-b) <= Tol_interval) && (max(abs((*FuncToCall)(a)),abs((*FuncToCall)(b))) <=Tol_approx))     //base case 
	{
		//Outputting the final statement 
		cout<<"Bisection method  using recursive calls converged to "<<(a+b)/2<<" after "<<counter<<" recursive calls!"<<endl;
	}
	
	//if (f(x_m)*(f(x_l)<0) and one of the two errors is bigger than our tolerance
	if (((*FuncToCall)((a+b)/2)*(*FuncToCall)(a)<0) && ((abs(a-b)> Tol_interval) || (max(abs((*FuncToCall)(a)),abs((*FuncToCall)(b))) >Tol_approx)))
	{
		++(counter);// increment our counter
		b=(a+b)/2;// x_r takes the value of x_m the midpoint
		 //Output statements of the result of the current iteration
		cout<<left<<fixed<<setw(25)<<setfill(' ')<<counter;
		cout<<left<<fixed<<setprecision(10)<<setw(28)<<setfill(' ')<<(a+b)/2;
		cout<<left<<fixed<<setprecision(10)<<setw(28)<<setfill(' ')<< abs(b-a)<<max(abs((*FuncToCall)(a)),abs((*FuncToCall)(b)))<<endl;
		
		//recursive call	
		B_Recursive(a,b,Tol_interval,Tol_approx,counter,(*FuncToCall));
	}
	//else if the  interval error and approx_error are bigger than our prescribed tollerances
	else if (((abs(a-b)> Tol_interval) || (max(abs((*FuncToCall)(a)),abs((*FuncToCall)(b))) >Tol_approx)))
	{
		++(counter);// increment counter
		a=(b+a)/2;// x_l=x_m
		
		// Output statements of the result of the current iteration
		cout<<left<<fixed<<setw(25)<<setfill(' ')<<counter;
		cout<<left<<fixed<<setprecision(10)<<setw(28)<<setfill(' ')<<(a+b)/2;
		cout<<left<<fixed<<setprecision(10)<<setw(28)<<setfill(' ')<< abs(b-a)<<max(abs((*FuncToCall)(a)),abs((*FuncToCall)(b)))<<endl;	
		//recursive call
		B_Recursive(a,b,Tol_interval,Tol_approx,counter,(*FuncToCall));
	}
};




