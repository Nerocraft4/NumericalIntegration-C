#!/bin/bash

#Llegim el parametre d'entrada "p"
p=$(echo $1)
count=0
#Resetegem el fitxer
echo `rm out.txt`
j=1000000
for i in {1..1000000}
do
	#Cridem al generador
	ss=$(echo `./generador 0 1`)
	sp=($ss)
	a=${sp[0]}
	#Cridem al llibreria d'integració
	pa=$(echo `./gauss 0 1 $a`)
	#Comprivacions amb la "p"
	if [ 1 -eq $(echo "$pa < $p" | bc) ];then
		let count+=1
	fi
	b=${sp[1]}
	pb=$(echo `./gauss 0 1 $b`)
	if [ 1 -eq $(echo "$pb < $p" | bc) ];then
		let count+=1
	fi
	#Escribim els resultats al fitxer
	echo "0 1 $a">>out.txt
	echo "0 1 $b">>out.txt
done
let j*=2
k=$(echo "scale=3; $count / $j" | bc) 
echo "Counted $count over $j. Result: $k"
