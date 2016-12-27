/*This file hosts the functions' prototype Secant_Meth_Iteration and Secant_Meth_Recursive*/
//To use these function the user must hard code the function and its derivative in the source file 
//12/25/2016
#ifndef SECANT_METH_H
#define SECANT_METH_H

//Function prototype for Secant_Meth_Iteration() It is a void function that takes in 5 arguments: 5 doubles and 1 function pointer
//Initial guess x_old, x_oldest, Tol_conces,TolApprox and the function of which we approximate a solution
void Secant_Meth_Iteration(double,double,double,double,double(*FuncToCall)(double));
//The two function bellow will be used to create a recursive function with a header output and counting recursive call mechanism.
//Secant_Meth_Recursive will be used for printing header and introducing the recursive call counter. To count and print each recursive call we will call N_Recursive() function.
void Secant_Meth_Recursive(double,double,double,double,double(*FuncToCall)(double));
//Function prototype: This function is used to implemet the recursive calling
void S_Recursive(double &x_new,double &x_old, double &x_oldest,int &counter, double,double,double(*FuncToCall)(double)); 






#endif