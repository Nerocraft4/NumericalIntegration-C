Mètodes Numèrics i Probabilístics: Pràctica 1, "Creació d'una Llibreria d'Integració Numèrica en C".
Última Data d'Edició: 8/3/2022.
Autors: Alberto Real Quereda, Pau Blasco Roca.

Nom de la llibreria: "integracio.c"

Cos de la llibreria: Consta de 4 funcionalitats:
	
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
		  status: int que indica l'estat de la funció. -1 vol dir que hi ha hagut error.

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
		  status: int que indica l'estat de la funció. -1 vol dir que hi ha hagut error.

	legendre():

	txevitxev():


