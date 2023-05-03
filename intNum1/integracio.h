#include<stdio.h>
int checkvalid(double a, double b, int n, int mode);
int trapezis(double(*f)(double, double*), double a, double b, int n, double* params);
int simpson(double(*f)(double, double*), double a, double b, int n, double* params);
