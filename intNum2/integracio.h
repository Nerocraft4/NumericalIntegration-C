#include<stdio.h>
int checkvalid(double a, double b, int n, int mode);
double trapezis(double(*f)(double, double*), double a, double b, int n, double* params);
double simpson(double(*f)(double, double*), double a, double b, int n, double* params);
double legendre(double(*f)(double, double*), double a, double b, int n, double* params);
double txebixev(double(*f)(double, double*), double a, double b, int n, double* params);
