#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "integracio.h"
// #include "function.c"
#include <limits.h>

//funció de la normal
double myfunc(double x, double*params){
  (double*)(params);
  double s = params[1];
  double mu = params[0];
  return 1/(s*sqrt(2*M_PI))*pow(M_E,-((x-mu)*(x-mu))/(2*s*s));
}

int main(int argc, char *argv[]){
  //declarem els paràmetres de la normal
  double mu, sigma, x;
  //agafem l'input de l'usuari
  mu=atof(argv[1]);
  sigma=atof(argv[2]);
  x=atof(argv[3]);
  //guardem l'input a l'apuntador de paràmetres que demana myfunc
  double parameters[2];
  parameters[0]=mu;
  parameters[1]=sigma;
  //calculem les integrals amb els 4 mètodes diferents
  double status1 = 2*(1-(0.5+trapezis(myfunc,mu,x,50,parameters)));
  double status2 = 2*(1-(0.5+ simpson(myfunc,mu,x,50,parameters)));
  double status3 = 2*(1-(0.5+legendre(myfunc,mu,x,10,parameters)));
  double status4 = 2*(1-(0.5+txebixev(myfunc,mu,x,50,parameters)));
  //mirem que no hi hagi hagut errors durant el càlcul
  if(status1==INT_MAX || status2==INT_MAX || status3==INT_MAX || status4==INT_MAX){
    printf("Hi ha hagut un error amb els parametres donats\n");
  }else{
    //mostrem el resultat per pantalla
    printf("Metode      |    Trapezis    |    Simpsone    |    Legendre    |    Txebixev\n");
    printf("n Intervals |      n=50      |      n=50      |      n=10      |      n=50   \n");
    printf("Resultat    | %.12f | %.12f | %.12f | %.12f",status1,status2,status3,status4);
  }
}
