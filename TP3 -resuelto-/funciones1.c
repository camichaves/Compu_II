
#include <stdio.h>

#include <string.h>

//extern int Contador[21];

//extern const char* PalabrasReservadas[3];

const char* PalabrasReservadas[3];
int Contador[21];
 void CerearContador(){


	for(int i=0;i<21; i++){
		Contador[i]=0;
	}
}

void Reservadas(){



	PalabrasReservadas[0]="THESE";
	PalabrasReservadas[1]="ADVENTURE";
	PalabrasReservadas[2]="WITHOUT";
	
}
