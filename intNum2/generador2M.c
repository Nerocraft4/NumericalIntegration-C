#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "generador2M.h"

// Recollim l'imput de l'usuari i generem els nombres aleatoris
// Aquesta vegada guardem també a la variable count els resultats que tenen P(X < x) <= p
int main(int argc, char *argv[]){
   float p  = atof(argv[1]);
   double mu    = 0;
   double sigma = 1;
   FILE * fp;
   fp = fopen ("file.txt", "w");
   fprintf(fp, "Resultats\n");
   fclose(fp);
   if(p < 0){
       p =- p;
   }
   // Iterem 1000000 * 2 vegades (ja que cada crida genera dos nombres)
   int i = 0, times = 1000000, count = 0;
   for(i=0;i<times;i++){
       count += generaNormal(mu,sigma,p);	
   }
   printf("S'han generat 2x1000000 nombres, i el quocient és: %f \n", (float)count/2000000);
   return 0;
}
