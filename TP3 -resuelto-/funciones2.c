
#include <stdio.h>
#include <ctype.h>
#include <string.h>


	const char* PalabrasReservadas[3];
//Funcion Buscar pal reservada en hijo2
int Buscar(char* palab){


        char palabra[25];
        strcpy(palabra,palab);
        int j=0;
        for(int i=0; i<strlen(palabra); i++){
                palabra[i]=toupper(palabra[i]);
        }
        int nn=1;
        while(nn!=0 && j<3){
                nn=strcmp(palabra,PalabrasReservadas[j]);
                j++;
        }
        if(nn==0) return j-1;

        else return -1;
}
