# Numerical_Methods_for_nonlinear_func
Numerical Methods for Nonlinear Function
This is a test C++ program that demonstrates how some nonlinear solver work with respect to Iterative and recursive implementations. 
Bisection, Newton’s and Secant methods are covered. The tolerance errors are defined as macros in the main source file.  
To approximate a solution using the Bisection or Secant methods, the user must hard code the nonlinear equation in the main source file.  
To use Newton’s Method, the user must also provide the derivative of the function to solve.    

Reminder: 

Bisection method converges as long as the user provides an interval [a,b] such that f(a)*f(b)<0
(This interval must host at least one solution) also, the function f(x) must be continuous over interval [a,b].

Newton’s method does not always converge to a solution. A good estimate of the first guess x_0 must be provided.

Secant method being derived from Newton’s method also does not always converge to a solution. 
To optimize the result two good estimates x_0 and x_1 must be provided.

