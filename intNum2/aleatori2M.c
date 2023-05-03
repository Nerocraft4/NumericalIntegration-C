#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "aleatori2M.h"
#include "integracio.h"

struct timespec start, end;
// Funció de la distribució  normal
double myfunc(double x, double*params){
  (double*)(params);
  double s = params[1];
  double mu = params[0];
  return 1/(s*sqrt(2*M_PI))*pow(M_E,-((x-mu)*(x-mu))/(2*s*s));
}
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
// Aquesta funció també compta i escriu els resultats dels valors generats
int generaNormal(float mu, float sigma, float p)
{
    double parameters[2];
    parameters[0] = mu;
    parameters[1] = sigma;
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
    //Comprovació extra amb el parametre "p"
    if(n1<0){n1=-n1;}
    if(n2<0){n2=-n2;}
    float n1p = 2*(1-(0.5+ simpson(myfunc,mu,n1,300,parameters)));
    float n2p = 2*(1-(0.5+ simpson(myfunc,mu,n2,300,parameters)));
    int count = 0;
    if (n1p<p){
    	count+=1;
    }
    if (n2p<p){
    	count+=1;
    }
    // Escribim els reultats als fitxers
    FILE * fp;
    fp = fopen ("file.txt", "a");
    fprintf(fp, "0 1 %f\n", n1);
    fprintf(fp, "0 1 %f\n", n2);
    fclose(fp);
    return count;
}
