Mètodes Numèrics i Probabilístics: Pràctica 1, "Creació d'una Llibreria d'Integració Numèrica en C".
Última Data d'Edició: 14/3/2022.
Autors: Alberto Real Quereda, Pau Blasco Roca.

Nom de la llibreria: "integracio.c"
S'inclou amb: #include "integracio.h"

La llibreria consta de quatre modes o funcionalitats:
	
	trapezis():
		INPUT:
		  *f: apuntador a una funció real qualsevol, accepta paràmetres.
		  a: nombre real que defineix l'inici de l'interval a intregrar.
		  b: nombre real que defineix el final de l'interval a intregrar.
		  n: nombre de subintervals en que dividim [a,b].
		  *params: apuntador a una llista de nombres reals, que es poden (o no) utilitzar.
		PROCÉS
		  La funció imprimirà el valor aproximat de la integral per pantalla.
		OUTPUT:
		  status: double amb el resultat de la integral. MAX_INT vol dir que hi ha hagut error.

	simpson():
		INPUT:
		  *f: apuntador a una funció real qualsevol, accepta paràmetres.
		  a: nombre real que defineix l'inici de l'interval a intregrar.
		  b: nombre real que defineix el final de l'interval a intregrar.
		  n: nombre de subintervals en que dividim [a,b]. Ha de ser parell.
		  *params: apuntador a una llista de nombres reals, que es poden (o no) utilitzar.
		PROCÉS
		  La funció imprimirà el valor aproximat de la integral per pantalla.
		OUTPUT:
		  status: double amb el resultat de la integral. MAX_INT vol dir que hi ha hagut error.

	legendre():
		INPUT:
		  *f: apuntador a una funció real qualsevol, accepta paràmetres.
		  a: nombre real que defineix l'inici de l'interval a intregrar.
		  b: nombre real que defineix el final de l'interval a intregrar.
		  n: nombre de subintervals en que dividim [a,b]. Ha de ser 2,5, o 10.
		  *params: apuntador a una llista de nombres reals, que es poden (o no) utilitzar.
		PROCÉS
		  La funció imprimirà el valor aproximat de la integral per pantalla.
		OUTPUT:
		  status: double amb el resultat de la integral. MAX_INT vol dir que hi ha hagut error.

	txevitxev():
		INPUT:
		  *f: apuntador a una funció real qualsevol, accepta paràmetres.
		  a: nombre real que defineix l'inici de l'interval a intregrar.
		  b: nombre real que defineix el final de l'interval a intregrar.
		  n: nombre de subintervals en que dividim [a,b]. 
		  *params: apuntador a una llista de nombres reals, que es poden (o no) utilitzar.
		PROCÉS
		  La funció imprimirà el valor aproximat de la integral per pantalla.
		OUTPUT:
		  status: double amb el resultat de la integral. MAX_INT vol dir que hi ha hagut error.


A més, la llibreria té una funció interna anomenada "checkvalid()" per a evitar possibles errors amb les funcions 
principals. No està pensada per a que l'usuari la faci servir directament. 



