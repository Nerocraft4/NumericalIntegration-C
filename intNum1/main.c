#include <stdio.h>
#include <stdlib.h>
#include "integracio.h"
#include "function.c"

int main(int argc, char *argv[]){
  double a, b, n;
  int status;
  a=atof(argv[1]);
  b=atof(argv[2]);
  n=atoi(argv[3]);
  printf("\n a=%f, b=%f, c=%f\n",a,b,n);
  double *parameters;
  status = simpson(myfunc, a, b, n, parameters);
  printf("La rutina ha acabat amb un estat %d\n", status);
  return 0;
}
