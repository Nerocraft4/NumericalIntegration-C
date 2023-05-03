#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "aleatori.h"

struct timespec start, end;

// Funció que genera dues variables uniformes a l'interval [a,b]
void generaUniforme(float a, float b, float* r)
{
    //clock_gettime(CLOCK_REALTIME,&start);
    float u,v;
    //clock_gettime(CLOCK_REALTIME,&end);
    //srand(end.tv_nsec);
    u = (float)rand()/RAND_MAX;
    u = a+u*(b-a);
    v = (float)rand()/RAND_MAX;
    v = a+v*(b-a);
    r[0]=u; r[1]=v;
}

// Funció que genera dues variables seguint una distribució normal, amb parametres (mu, sigma)
void generaNormal(float mu, float sigma, double * p)
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
    p[0]=n1;
    p[1]=n2;
    //printf("%f \n %f \n", n1,n2);
}

void muller(double * v){
    //declarem variables inicials
    double a[2];
    double x[5];
    //guardem normals al vector x
    generaNormal(0,1,a);
    x[0]=a[0];
    x[1]=a[1];
    generaNormal(0,1,a);
    x[2]=a[0];
    x[3]=a[1];
    generaNormal(0,1,a);
    x[4]=a[0];//l'últim es desaprofita
    //calculem la norma del vector x
    double norm;
    for(int i=0; i<5; i++){
        norm+=x[i]*x[i];
    }
    norm = sqrt(norm);
    //guardem a v el vector x normalitzat
    for(int i=0; i<5; i++){
        v[i]=x[i]/norm;
    }
}
