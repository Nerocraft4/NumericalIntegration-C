#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "aleatori.h"

struct timespec start, end;

// Funció que genera dues variables uniformes a l'interval [a,b]
void generaUniforme(float a, float b, float* r)
{
    clock_gettime(CLOCK_REALTIME,&start);
    float u,v;
    clock_gettime(CLOCK_REALTIME,&end);
    srand(end.tv_nsec);
    u = (float)rand()/RAND_MAX;
    u = a+u*(b-a);
    v = (float)rand()/RAND_MAX;
    v = a+v*(b-a);
    r[0]=u; r[1]=v;
}

// Funció que genera dues variables seguint una distribució normal, amb parametres (mu, sigma)
void generaNormal(float mu, float sigma)
{
    clock_gettime(CLOCK_REALTIME,&start);
    float u,v,n1,n2,s;
    float r[2];
    do
    {
        generaUniforme(-1,1,r);
        u = r[0];
        v = r[1];
	s = u*u+v*v;
    } while(s > 1);
    n1 = u*sqrt(-2*log(s)/s);
    n2 = v*sqrt(-2*log(s)/s);
    n1 = n1*sigma+mu;
    n2 = n2*sigma+mu;
    printf("%f \n %f \n", n1,n2);
}
