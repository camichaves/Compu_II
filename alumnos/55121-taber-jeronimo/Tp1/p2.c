#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]){

        int d,p,y,n,a,m,fdo,fdd,leido,i,b,s,opt;
        char buff1[10000],buff[200],test[10000];
	for(y=0; y< argc; y++){
	}
	while ((opt =getopt(argc, argv ,"oh::")) != 1) {
	switch (opt) {
	case 'o':
        fdd = open(argv[2],O_RDWR|O_CREAT, 0666);
	read(0,buff,2000);
	printf("%s",buff);
	b=0;
	s=0;
	m=0;
	d=0;
	p=0;
	n = sizeof(buff);
	while(s!=n){
        for (a=0;a<n;a++){
	
                if(buff[a] == '\n'){
			if(m>=10){
			a++;
			}
		//	d=d*2;
		//	if(d>p){
		//	a--;
		//	}
		//	if(d<p){
		//	a++;
		//	}
		//	d=p;
		//	p=0;
                        for (i=0;i<a;i++){
			//m=(n/sizeof(int))/(a+1);
                        test[i]=buff[b];
		//	printf("%s",test);
			b++;
		//	p++;
			//m++;
                        }
			m++;
			b++;
		//	if(d=0){
		//	d=p; 
		//	printf("%d",d);
		//	}
		//	                        printf("%d",d);

                       	break;
			break;//no seguro
                        }
        }
	printf("%s",test);
//	printf("%d",b);
	s++;
	if(y != 2){
        	fdo = open(test,O_RDONLY);
        	leido = read(fdo,buff1,10000);
        	write (fdd,buff1,leido);
		memset(buff1,0,10000);
	}
	else{
		fdo = open(test,O_RDONLY);
		leido = read(fdo,buff1,10000);
		printf("%s",buff1);
		memset(buff1,0,10000);
	}
	close(fdo);
	}
	close(fdd);
	break;
	case 'h':
		printf("Para utilizar el programa colocar: ls [nombre archivos]*| ./p2 -o [nombre archivo salida] ");
	break;
	}
	memset(buff,0,2000);
	memset(buff1,0,10000);
exit(EXIT_SUCCESS);
	}
}
