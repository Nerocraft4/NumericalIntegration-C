#include<stdio.h>
#include<math.h>
double myfunc(double x, double*params){
  (double*)(params);
   return(pow(M_E,-x*x));
  // return x*x*x;
  //double s = params[1];
  //double mu = params[0];
  //return 1/(s*sqrt(2*M_PI))*pow(M_E,-((x-mu)*(x-mu))/(2*s*s));
}
