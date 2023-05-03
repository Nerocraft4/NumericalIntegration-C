#include <stdio.h>
#include <stdlib.h>
#include "aleatori.h"
#include <time.h>

struct timespec start, end;

main(int argc, char *argv[ ], char *envp[ ] ){
    //double a = atof(argv[1]);
    clock_gettime(CLOCK_REALTIME,&start);
    srand(start.tv_nsec);
    double p[5];
    double P,Q,R,S,T,U,D;
    int c0=0, c2=0, c4=0;
    for(int i = 0; i<7000000; i++){
    	muller(p);
    	double a=p[0], b=p[1], c=p[2], d=p[3], e=p[4];
    	P=a*e-4*b*d+3*c*c;//dependant
    	Q=(b*b-a*c)*e+a*d*d+(c*c-2*b*d)*c;//dependant
    	D=27*Q*Q-P*P*P;
    	R=b*b-a*c;
    	S=12*R*R-a*a*P;
    	if(D<0){
            if(R>0 && S>0){
	        //printf("Returned 4 \n");
	        //return 4;//Cas 1
	        c4++;
            }else{
	        //printf("Returned 0 \n");
	        //return 0; //Casos 9,10
	        c0++;
            }
        }else{
            //printf("Returned 2 \n");
            //return 2;//Cas 3
            c2++;
        }
    }
    printf("c0: %f, c2: %f, c4: %f\n", c0/7000000.0,c2/7000000.0,c4/7000000.0);
}
