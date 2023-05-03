#include <math.h>
#include <stdio.h>
void RK4 (double (*f1)(double, double, double, double*),
          double (*f2)(double, double, double, double*),
          double *xf, double *yf, double x0, double y0,
          double t0, double tf, int n, double *prm1, double *prm2){
  double x = x0, y = y0, t=t0;
  xf[0]=x;
  yf[0]=y;
  printf("%f %f %f\n",t0, xf[0],yf[0]);
  double k1x, k2x, k3x, k4x, k1y, k2y, k3y, k4y;
  double h = (tf-t0)/n;
  for(int i = 1; i<n; i++){
    //RK4 per la X i Y
    k1x = f1(t,x,y,prm1);
    k1y = f2(t,x,y,prm2);
    k2x = f1(t+h/2, x+h/2*k1x, y+h/2*k1y, prm1);
    k2y = f2(t+h/2, x+h/2*k1x, y+h/2*k1y, prm2);
    k3x = f1(t+h/2, x+h/2*k2x, y+h/2*k2y, prm1);
    k3y = f2(t+h/2, x+h/2*k2x, y+h/2*k2y, prm2);
    k4x = f1(t+h, x+h*k3x, y+h*k3y, prm1);
    k4y = f2(t+h, x+h*k3x, y+h*k3y, prm2);
    //Actualitzem variables
    x += h*(k1x+2*k2x+2*k3x+k4x)/6;
    y += h*(k1y+2*k2y+2*k3y+k4y)/6;
    t += h;
    //Guardem variables
    xf[i]=x;
    yf[i]=y;
    printf("%f %f %f\n", t, xf[i], yf[i]);
  }
}

double f1(double t, double x, double y, double *params){
  return y;
}
double f2(double t, double x, double y, double *params){
  double a = params[0];
  double m = params[1];
  double l = params[2];
  return -a*y-m*sin(x)/l;
}
