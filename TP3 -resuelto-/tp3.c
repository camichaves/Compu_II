	#include <sys/types.h>
        #include <sys/stat.h>
        #include <fcntl.h>
	#include <sys/mman.h>
	#include <unistd.h>
	#include <sys/wait.h>
	#include <semaphore.h>
        #include <sys/wait.h>
        #include <ctype.h>
        #include <stdio.h>
        #include <stdlib.h>
        #include <string.h>


int Contador[21];
const char* PalabrasReservadas[3]; //cuantas??
char buff[1500];
char buffauxiliar[1500];

//funcion cererar contador
void CerearContador(){
        for(int i=0; i<21;i++){
                Contador[i]=0;
        }
}
//fin func      

//Funcion lista palabras reservadas
void Reservadas(){
PalabrasReservadas[0]="ESTADO";
PalabrasReservadas[1]="GOBIERNO";
PalabrasReservadas[2]="CIUDAD";

}


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


//Funcion Imprimir Palabra Reservada
int Resto(char* palabra, int indpal, int tam2){


        int tam=strlen(palabra);
        int ban=0;

        int i=0,j=0, aux;

        while(ban==0 && i<tam2){
                if(buffauxiliar[i]==palabra[j]){
                        aux=i;
                        while(buffauxiliar[aux]==palabra[j] && j<tam){
                                j++;
                                aux++;
                        }
                        if(tam==j) ban=1; else{ i++; j=0; }
                }
                else i++;


 }
       for(int g=0; g<i; g++){

                printf("%c",buffauxiliar[g]);
        }

        char buffaux[1500];
        strcpy(buffaux,buffauxiliar);

        memset(buffauxiliar,'\0',tam2);
        for(int g=aux;g<tam2;g++){
                buffauxiliar[g-aux]=buffaux[g];
        }
        int rta=(tam2-aux);

        printf("%s",PalabrasReservadas[indpal]);

        return rta;
}





//Funcion hijo 1 contador
int Hijo1(int leido, char ** ptr){

 

        char buf[220];
        int tamanio;
        char * lineas[256];
        char d2[]="|123456789 - 0'¿°!«#$%&/()=—?¡[]_:;,.-{+}´ \n";

        int j;


                        CerearContador();

while((leido=read(*ptr, buf, sizeof buf))>0){

        j=0;
        lineas[j]=strtok(buf,d2);
        while(lineas[j]!= NULL){
                tamanio= strlen(lineas[j]);

                Contador[tamanio-1]++;
                j++;
                lineas[j]=strtok(NULL,d2);

        }
}
        

                // Contadores listos
        for(int g=0;g<21;g++){
        printf("\n Cantidad de palabras de %d caracteres:%d",g+1,Contador[g]);
            }
        printf("\n");

        return 0;


}



//Funcion Hijo 2 conversor a mayus
int Hijo2(int leido, char ** ptr){
        

        Reservadas();
        int ban=0;
        char d2[]="|123456789 - 0'¿°!«#$%&/()=—?¡[]_:;,.-{+}´ \n";
        char * lineas[256];
        int j,k=0;
        int indpal;
        int h=0;
        int tambuff;
        while((leido=read(*ptr,buff, sizeof buff))>0){
                tambuff=leido;
                strncpy(buffauxiliar,buff,leido);


                j=0;
                lineas[j]=strtok(buff,d2);
                while(lineas[j]!=NULL){
                        indpal=Buscar(lineas[j]);
                        h++;
                        if(indpal!=-1){
                                tambuff=Resto(lineas[j],indpal,tambuff);//imprime all hasta pal
                                                j++;
                        }else {

                                j++;
                        }

                        lineas[j]=strtok(NULL,d2);
                }

                printf("%s",buffauxiliar);

                memset(buffauxiliar,'\0',tambuff);
        }

        
        return 0;

}





int main(int argc, char * const argv[]){

	sem_t *semhijo1, *sem1hijo1, *sem2hijo2, *semhijo2;
	char* ptr;

	semhijo1=(sem_t *)ptr+ sizeof semhijo1; //semaforos en  memcomp
	semhijo2=(sem_t *)ptr+ (sizeof semhijo1)*2;
	sem1hijo1= (sem_t *)ptr+ (sizeof semhijo1)*3;
	sem2hijo2= (sem_t *)ptr+ (sizeof semhijo1)*4;
	sem_init(semhijo1,1,0);	
	sem_init(semhijo2,1,0);
	sem_init(sem1hijo1,1,0);
        sem_init(sem2hijo2,1,0);

	sem_wait(semhijo1);
	sem_wait(semhijo2);

	ptr=mmap(NULL,10,PROT_READ|PROT_WRITE,MAP_ANONYMOUS|MAP_SHARED,-1,0);


        int leido;
        int flagi=0;
        char buffer[2200];
        char *program_name;
        char* opcion_i = NULL;
        int c;
        


        /* bucle para loopear por las opciones pasadas */
        while ((c=getopt(argc, argv, "i:"))>=0) {
                switch (c) {
                        case 'i':
                                opcion_i=optarg;
                                flagi++;
                                break;
                        default:
                                fprintf(stderr, "opcion invalida: %c\n", c);
                                        return 1;
        }
                }

       

    int procnum;
    int pid;

    for(procnum=1;procnum<3;procnum++){
        pid=fork();
        if(pid==0) break;
        else if(pid==-1) { perror("ERROR con fork"); break; }
    }

if(procnum==1){
sem_wait(semhijo1);
Hijo1(leido,*ptr);
sem_post(sem1hijo1);
return 0;
}

if(procnum==2){
sem_wait(semhijo2);
Hijo2(leido,*ptr);
sem_post(sem2hijo2);
return 0;
}

       

        if(flagi!=0){
                int arch= open(opcion_i, O_RDWR , 0666);

                while((leido=read(arch,&buffer,sizeof buffer))>0){
                        write(*ptr,buffer,leido);
			sem_post(semhijo1);
			sem_post(semhijo2);
			sem_wait(sem1hijo1);
			sem_wait(sem2hijo2);
                        
                }
        }else{
                while((leido=read(STDIN_FILENO,buffer,sizeof buffer))>0){
			write(*ptr,buffer, leido);
			sem_post(semhijo1);
                        sem_post(semhijo2);
                        sem_wait(sem1hijo1);
                        sem_wait(sem2hijo2);

                }
        }

               
                wait(NULL);
                return 0;
                           
}
