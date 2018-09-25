#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<string.h>
int main(int argc, char *argv[]){

        int fdd,leido,opt,num;
        char fdo,of,buff[10000];
	int b,e,c,g;
        float h,a;
        h=0;
        a=0;
        b=0;
	c=0;
//	printf("%s",argv[3]);
	int y,p,z;
	for(y=0; y< argc; y++){
                   g++; 
		if(strcmp(argv[y], "-i") == 0){
                        if(y != 1){
                                printf("Se ingreso i en un lugar incorrecto");
                                exit(EXIT_FAILURE);
                        }
                }

       		if(strcmp(argv[y], "-s") == 0){
                        if(y != 3){
                                printf("Se ingreso s en un lugar incorrecto");
                                exit(EXIT_FAILURE);
                        }
 		}
		if(strcmp(argv[y], "-n") == 0){	
			if(y != 3){
        			printf("Se ingreso n en un lugar incorrecto");
        			exit(EXIT_FAILURE);
			}
		for(p=0; p< argc; p++){
			if(strcmp(argv[p], "-s") == 0){
       	 			printf("Se ingreso n y s al mismo tiempo");
				exit(EXIT_FAILURE);
			}
			}	
		}	
        	}
	if(strcmp(argv[1], "-h") != 0){
	
        char *ptr;
        long ret = strtol(argv[4], &ptr,10);
        if("%ld",ret == 0){
        printf("Se ingreso un valor no numerico  ");
        exit(EXIT_FAILURE);
        }
	}


	while ((opt =getopt(argc, argv ,"ins:oh::")) != 1) {

	switch (opt) {
	case 'i':
	
	        FILE *fp =fopen(argv[2],"r");
	             
		   while((fgetc(fp) != EOF)){
                        if (fdo == EOF) break;
        			a++;
	}

	break;

	case 'n':
        		
	num = atoi(argv[4]);
			
		b=a/num;
		//printf("%c",b);
		h=a/num;
		if(b < h){
		b++;
		}
		break;
	
	case 's':

	b = atoi(argv[4]);
                num=a/b;
		//printf("%d",num);
		h=a/b;
		//printf("%lf",h);

                if(num < h){
                num++;
	//	printf("%d",num);
                }

	break;
	case 'o':
		if(g != 6){
		while (c != b){
                	char str[10];
                	sprintf(str,"%d",c);
                	char cad3[30];
                	strcpy(cad3,argv[6]);
                	strcat(cad3,str);
                	fdd = open (cad3,O_CREAT|O_RDWR, 0666);

                	leido = read(fdo,buff,num);
                	write (fdd,buff,leido);
               	close(fdd);
                	c++;
		}
}	
	else{

	while (c != b){
		//read(1,buff,num);
                        leido = read(fdo,buff,num);	
			printf("\n %s",buff);
		//	read(1,buff,50);
                        c++;
                }

	}
                close(fdo);
		fclose(fp);
	break;
	case 'h':
	
		printf("El programa se utiliza colocando: -i [Archivo original] -n/-t [tamaño a dividir/ cantidad de archivos] -o [archivo de salida(opcional)]");
	break;
	default:
	exit(EXIT_FAILURE);
		}

	}        
	
	
exit(EXIT_SUCCESS);

}
                 
