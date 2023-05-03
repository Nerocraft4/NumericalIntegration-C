#include<stdio.h>
#include<math.h>
double myfunc(double x, double*params){
  (double*)(params);
  return(pow(2.718,-x*x));
}
