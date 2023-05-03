#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "integracio.h"
#include "function.c"
#include <limits.h>

int main(int argc, char *argv[]){
  double a, b;
  int n;
  double status;
  char *name = argv[1];
  a=atof(argv[2]);
  b=atof(argv[3]);
  n=atoi(argv[4]);

  printf("\n name=%s, a=%f, b=%f, n=%d\n",name,a,b,n);
  double *parameters;
  if(strcmp(name,"trapezis")==0){
    status = trapezis(myfunc, a, b, n, parameters);
  }else if(strcmp(name,"simpson")==0){
    status = simpson(myfunc, a, b, n, parameters);
  }else if(strcmp(name,"legendre")==0){
    status = legendre(myfunc, a, b, n, parameters);
  }else if(strcmp(name,"txebixev")==0){
    status = txebixev(myfunc, a, b, n, parameters);
  }
  if(status==INT_MAX){
      printf("La rutina ha acabat amb un estat %d\n", status);
  }else{
      printf("El resultat es %.10f",status);
  }
  return 0;
}
