//Bisection_Method.h
//host the functions prototypes for the bisection method with two implementation Recursive and Iterative
//12/21/2016
//Conditional inclusion to avoid multiple inclusions (Safety mechanism)

#ifndef BISECTION_METH_H
#define BISECTION_METH_H

//Function prototype for bisectionMethod using Iterations . Returns a void and takes in 5 arguments: 4 doubles and a function pointer
void Bisection_Meth_Iteration(double,double,double,double,double (*FuncToCall) (double));

//The two function bellow will be used to create a recursive function with a header output and counting recursive calls mechanism.
//Bisection_Meth_Recursive used for printing header and introducing the recursive call counter. To count and print each recursive call we will call B_Recursive() function.
//Function prototype for bisection method using recursive calls. Returns a void and takes in 5 arguments: 4doubles and a function pointer
void Bisection_Meth_Recursive(double a,double b,double,double,double (*FuncToCall)(double));
//Function prototype:This function is used to implement the recursive calling.It is a void function that takes in 6 arguments 
void B_Recursive(double &a,double &b,double,double,int &i,double (*FuncToCall)(double));

#endif