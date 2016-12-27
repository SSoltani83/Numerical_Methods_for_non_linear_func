//Newton's_Meth.h 
//this file hosts the functions' prototypes for the Newton_Meth_Iteration() and Newton_Reth_Recursive
//To use these function the user must hard code the function and its derivative in the source file 
//12/21/2016

//conditional inclusion to avoid multiple inclusions
#ifndef NEWTON_METH_H
#define NEWTON_METH_H
//function prototype for Newton's method using iterative implementation
void Newton_Meth_Iteration(double,double,double,double(*FuncToCall)(double),double(*Derivative_FuncToCall)(double));

//The two function bellow will be used to create a recursive function with a header output and counting recursive calls mechanism.
//Newton_Meth_Recursive will be used for printing header and introducing the recursive call counter. To count and print each recursive call we will call N_Recursive() function.
void Newton_Meth_Recursive (double ,double,double,double(*FuncToCall)(double), double (*Derivative_FuncToCall)(double));
//Function prototype: This function is used to implemet the recursive calling
void N_Recursive (double &x_old,double &x_new,double,int &i,double(*FuncToCall)(double), double (*Derivative_FuncToCall)(double));
#endif
