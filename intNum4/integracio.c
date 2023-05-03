#include<stdio.h>
#include<math.h>
#include "integracio.h"
#include<limits.h>

//Author: Alberto Real Quereda, Pau Blasco Roca
//NIUS: 1544112, 1600959

int checkvalid(double a, double b, int n, int mode){
  int flag = 1;
  //comprovem que no ens hagin donat l'interval del revés.
  if(a>b){
    printf("Advertencia: Cal introduir b>a\n");
    flag = 0;
  }
  //comprovem que n sigui major que zero
  if(n<1){
    printf("No es pot calcular la integral amb n<1\n");
    flag = 0;
  }
  //comprovem que, per a simson, n%2==0, si no, el mètode falla
  if(mode==1 && n%2!=0){
    printf("Per al Metode de Simpson, cal fer servir un nombre d'intervals parell\n");
    flag = 0;
  }

  // Lege (mode == 2)
    // codigo

  // Tx (mode == 3)
    // codigo

  if(flag!=1){
    return -1;
  }
  return 1;
}

double trapezis(double(*f)(double, double*), double a, double b, int n, double* params){
  if(checkvalid(a,b,n,0)==-1){
      printf("Els parametres introduits no son valids. Tancant programa.\n");
      return INT_MAX;
  }
  double apx = (*f)(a, params)/2;
  double dx=(b-a)/n;
  for(int i = 1; i<n; i++){
    apx+=(*f)(a+i*dx,params);
  }
  apx+=(*f)(b, params)/2;
  apx*=dx;
  //printf("\nTenim n=%d intervals, el resultat es %.10f\n",n, apx);
  return apx;
}

double simpson(double(*f)(double, double*), double a, double b, int n, double* params){
  if(checkvalid(a,b,n,1)==-1){
      printf("Els parametres introduits no son valids. Tancant programa.\n");
      return INT_MAX;
  }
  double apx = (*f)(a, params);
  double dx=(b-a)/n;
  for(int i = 1; i<n; i++){
    if(i%2!=0){
      apx+=4*(*f)(a+i*dx,params);
    }else{
      apx+=2*(*f)(a+i*dx,params);
    }
  }
  apx+=(*f)(b, params);
  apx*=dx/3;
  //printf("\nTenim n=%d intervals, el resultat es %.10f\n",n, apx);
  return apx;
}

double legendre(double(*f)(double, double*), double a, double b, int n, double* params){
  if(checkvalid(a,b,n,2)==-1){
      printf("Els parametres introduits no son valids. Tancant programa.\n");
      return INT_MAX;
  }
  double* positions, weights;
  double positio2[2] = {-0.57735027,0.57735027};
  double weights2[2] = {1,1};
  double positio5[5] = {-0.90617985,-0.53846931,0,0.53846931,0.90617985};
  double weights5[5] = {0.23692689,0.47862867,0.56888889,0.47862867,0.23692689};
  double positio10[10] = {-0.9739065285,-0.8650633667,-0.679409568,-0.4333953941,-0.148874339,0.148874339,0.4333953941,0.6794095683,0.8650633667,0.9739065285};
  double weights10[10] = {0.06667134431,0.1494513492,0.219086363,0.2692667193,0.2955242247,0.2955242247,0.2692667193,0.219086363,0.1494513492,0.06667134431};
  //example case
  //translacion del intervalo y las posiciones
  double ex = (b-a)/2;
  double res = 0;
  if(n==2){
    for(int i = 0; i<n; i++){
      res+=ex*(weights2[i]*(*f)(ex*positio2[i]+(b+a)/2,params));
    }
  }if(n==5){
    for(int i = 0; i<n; i++){
      res+=ex*(weights5[i]*(*f)(ex*positio5[i]+(b+a)/2,params));
    }
  }if(n==10){
    for(int i = 0; i<n; i++){
      res+=ex*(weights10[i]*(*f)(ex*positio10[i]+(b+a)/2,params));
    }
  }
  //printf("\nTenim n=%d intervals, el resultat es %.10f\n",n, res);
  return res;
}


double txebixev(double(*f)(double, double*), double a, double b, int n, double* params){

  double PI = M_PI;

  if(checkvalid(a,b,n,3)==-1){
      printf("Els parametres introduits no son valids. Tancant programa.\n");
      return INT_MAX;
  }

  int k;
  double weight, alpha, z0, res=0, fi;
  weight = PI/(n+1);
  double ex = (b-a)/2;
  double xi;

  for(k=0; k<=n; k++){
    xi = cos((2*k-1)*PI/(2*(n+1)));
    z0 = ex*xi+(b+a)/2;
    res += (*f)(z0,params)*sqrt(1-xi*xi);
  }
  res*=weight*ex;
  //printf("\nTenim n=%d intervals, el resultat es %.10f\n",n, res);
  return res;
}
