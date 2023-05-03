#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rungekuta.h"

int main(int argc, char *argv[]){
  double a, m, l, x0, y0, t0, tf;
  int n;
  a =atof(argv[1]);
  m =atof(argv[2]);
  l =atof(argv[3]);
  x0=atof(argv[4]);
  y0=atof(argv[5]);
  t0=atof(argv[6]);
  tf=atof(argv[7]);
  n =atoi(argv[8]);
  double *xf = (double *)malloc(n);
  double *yf = (double *)malloc(n);
  double *pr = (double *)malloc(3);
  pr[0] = a;
  pr[1] = m;
  pr[2] = l;
  RK4(f1,f2,xf,yf,x0,y0,t0,tf,n,pr,pr);
  printf("t x y\n");
  double df = (tf-t0)/n;
  for(int i = 0; i<n; i++){
    printf("%f %f %f\n", t0, xf[i], yf[i]);
    t0+=df;
  }
}
