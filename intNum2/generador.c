#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "generador.h"

// Recollim l'imput de l'usuari i generem els nombres aleatoris
int main(int argc, char *argv[]){
   float mu    = atof(argv[1]);
   float sigma = atof(argv[2]);
   generaNormal(mu,sigma);
   return 0;
}
