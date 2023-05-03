#include <math.h>
#include <stdio.h>
void RK4(double (*f1)(double, double, double, double*),
          double (*f2)(double, double, double, double*),
          double *xf, double *yf, double x0, double y0,
          double t0, double tf, int n, double *prm1, double *prm2);
double f1(double t, double x, double y, double *params);
double f2(double t, double x, double y, double *params);
