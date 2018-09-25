#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<ctype.h>
#include<string.h>
#include <fcntl.h>
#include <stdlib.h>



int main (int argc, char *argv[]){
        int pah[2];//variables pipes
        int hap[2];
        int hap2[2];
        int pah2[2];
       	int pas[2];
	//int pan[2];
	char buffer[1000000];//buffer para ingreso datos toupper
        //char buffer2[100];
        char buffer1[100000];//buffer para ingreso datos contador
        long count[10000];//buffer datos contador
        char str[100000];//buffer para concatenar texto
        char test[1];//buffer para concatenar texto 2
        char fdo,fda;//variable de open
        memset(&count[0],0,sizeof(count));//todas las partes del array a 0
        int pid,opt,pad,leido,leido2,i,a;
        a=0;

while ((opt =getopt(argc, argv ,"f:")) != 1) {
switch (opt){
case 'f'://case de ./beta -f texto

        pipe(pah);//padre escribe a hijo
        pipe(hap);//hijo escribe a padre
pid = fork();
if(pid == 0){
	
                close(pah[1]);//cierra para no escribir el el pipe padre a hijo
                close(hap[0]);//cierra para no leer en el pipe hijo a padre
                int z;
               while ((leido = read(pah[0], buffer, sizeof buffer)) > 0){// recibe los datos del padre por el pipe
		       for(i=0;i<leido;i++){ //contador para los datos del pipe

                if(isalnum(buffer[i])){ //verifica si el elemento del array es alfanumerico
                    a=a+1;//si es alfanmerico suma 1 a a
                }
                else{//cuando se encentra un valor que no es alfanumerico se fija si es parte de los caracteres reservados de c
                int l;
                l=i-a;//variable para determinar cuantas letras tiene la palabra
                test[0]=buffer[l];//copia 1 caracter del buffer a un rray temporal
                strcpy(str,&test[0]);//ingresa el caracter del array temporal para concatenar
                for(l=l+1;l<i;l++){//ingresa el resto de los caracteres de la palabra y los concatena
                test[0]=buffer[l];
                strcat(str,&test[0]);
                        }
		//se fija si la palabra ingresada pertenece a los resevados de c
                if(strcmp(str, "auto") == 0 ||strcmp(str, "break") == 0 || strcmp(str, "case") == 0 || strcmp(str, "char") == 0 || strcmp(str, "const") == 0 || strcmp(str, "continue") == 0 || strcmp(str, "default") == 0 || strcmp(str, "do") == 0 || strcmp(str, "int") == 0 ||strcmp(str, "long") == 0 || strcmp(str, "register") == 0 || strcmp(str, "return") == 0 || strcmp(str, "short") == 0 || strcmp(str, "signed") == 0 || strcmp(str, "sizeof") == 0 || strcmp(str, "static") == 0 ||strcmp(str, "struct") == 0 ||strcmp(str, "switch") == 0 || strcmp(str, "typedef") == 0 || strcmp(str, "union") == 0 || strcmp(str, "unsigned") == 0 || strcmp(str, "void") == 0 || strcmp(str, "volatile") == 0 || strcmp(str, "while") == 0 ||strcmp(str, "double") == 0 ||strcmp(str, "else") == 0 || strcmp(str, "enum") == 0 || strcmp(str, "extern") == 0 || strcmp(str, "float") == 0 || strcmp(str, "for") == 0 || strcmp(str, "goto") == 0 || strcmp(str, "if") == 0 ){
                        for(z=i-a;z<i;z++){
                        buffer[z] = toupper(buffer[z]);
			//si pertenece se los convierte a mayuscula

                }
                }
                    a=0;//se vuelve el contador de 0 (el que cuenta el tamaño de la palabra)

                        }
}

                        write(hap[1],buffer,leido);//se envia el buffer al padre
}
close(pah[0]);//cierra pipe
close(hap[1]);//cierra pipe

return 0;

}

////// termina el hijo1

close(pah[0]);
close(hap[1]);
fdo = open(argv[2],O_RDONLY);//se abre archio especificado por argv
        while ((leido = read(fdo, buffer, sizeof buffer)) > 0){//se cargan en el buffer los caracteres del archivo
               	write(pah[1], buffer,leido);//se envia el buffer al hijo
}
close(pah[1]);//cierra pipe

     while ((leido = read(hap[0], buffer, sizeof buffer)) > 0){//se recibe el bbuffer del hijo

                write(1,buffer,leido);//se muestra el buffer en pantalla


}
close(hap[0]);// cierra pipe
// close(fdo);
//termina llamada hijo 1


        pipe(pah2);//crea pipe del segudo hijo
        pipe(hap2);//crea pipe del segundo hijo
        pad = fork();//crea fork para segundo hijo


//hijo 2
if(pad == 0){//si se creo 2 hijo

                close(pah2[1]);//cierra para no escribir en el pipe padre a hijo
                close(hap2[0]);//cierra para no leer en el pipe hijo a padre
               while ((leido2 = read(pah2[0], buffer1, sizeof buffer1)) > 0){
                        for(i=0;i<leido2;i++){
                if(isalnum(buffer1[i])){


                    a=a+1;
                }
                else{//cuando termina la palabra se suma 1 a un contador en un numero especifico ej palabra de 3 letras se suma 1 a count[3]


                     count[a]=count[a] + 1;

                    a=0;
                }
                }

 write(hap2[1],count,leido2);//se envia el array del contador al padre

close(pah2[0]);
                close(hap2[1]);
}


return 0;

}
//termina hijo 2

close(pah2[0]);
close(hap2[1]);

fda = open(argv[2],O_RDONLY); // se abre el archivo de vuelta(error cuando intentaba abrirlo una sola vez)

        while ((leido2  = read(fda, buffer1, sizeof buffer1)) > 0){
                write(pah2[1],buffer1,leido2);


}
close(pah2[1]);


        while ((leido2 = read(hap2[0], count, sizeof count)) > 0){//se recibe el contador del padre
                for (int x=1 ; x<101; x++){//se muestra en pantalla l cantidad de palabras con letras determinadas
                        if(count[x] != 0){
                        printf("Letras %d: ", x);
                        printf(" %ld", count[x]);
                        printf("\n");
                        }

                }
}
 // hasta aca

close(hap2[0]);

//termina llamada a hijo 2
 close(fda);
//exit(EXIT_FAILURE);
break;




//case default (datos ingresador por cat)
//es igual al anterior solo que se agrega un pipe extra para poder mandar los datos del primmer read del padre al seguno read del padre






default:
//	printf("adsas");
        pipe(pah);//padre escribe a hijo
        pipe(hap);//hijo escribe a padre
	pid = fork();
	if(pid == 0){
	
                close(pah[1]);//cierra para no escribir el el pipe padre a hijo
                close(hap[0]);//cierra para no leer en el pipe hijo a padre
                int z;
               while ((leido = read(pah[0], buffer, sizeof buffer)) > 0){
		       for(i=0;i<leido;i++){

                if(isalnum(buffer[i])){
                    a=a+1;
                }
                else{
                int l;
                l=i-a;
                test[0]=buffer[l];
                strcpy(str,&test[0]);
                for(l=l+1;l<i;l++){
                test[0]=buffer[l];
                strcat(str,&test[0]);
                        }
                if(strcmp(str, "auto") == 0 ||strcmp(str, "break") == 0 || strcmp(str, "case") == 0 || strcmp(str, "char") == 0 || strcmp(str, "const") == 0 || strcmp(str, "continue") == 0 || strcmp(str, "default") == 0 || strcmp(str, "do") == 0 || strcmp(str, "int") == 0 ||strcmp(str, "long") == 0 || strcmp(str, "register") == 0 || strcmp(str, "return") == 0 || strcmp(str, "short") == 0 || strcmp(str, "signed") == 0 || strcmp(str, "sizeof") == 0 || strcmp(str, "static") == 0 ||strcmp(str, "struct") == 0 ||strcmp(str, "switch") == 0 || strcmp(str, "typedef") == 0 || strcmp(str, "union") == 0 || strcmp(str, "unsigned") == 0 || strcmp(str, "void") == 0 || strcmp(str, "volatile") == 0 || strcmp(str, "while") == 0 ||strcmp(str, "double") == 0 ||strcmp(str, "else") == 0 || strcmp(str, "enum") == 0 || strcmp(str, "extern") == 0 || strcmp(str, "float") == 0 || strcmp(str, "for") == 0 || strcmp(str, "goto") == 0 || strcmp(str, "if") == 0 ){
                        for(z=i-a;z<i;z++){
                        buffer[z] = toupper(buffer[z]);


                }
                }
                    a=0;

                        }
}

                        write(hap[1],buffer,leido);
}
close(pah[0]);
close(hap[1]);

return 0;

}
//char buff[200000];
//int numero;
//read(0, buff,sizeof buff);
//numero = strlen(buff);
//printf("%d", numero);
//write(1,buff, sizeof buff);
////// termina el hijo1
//leido = read(0, buffer, sizeof buffer);
close(pah[0]);
close(hap[1]);
pipe(pas);

//fdo = open(argv[2],O_RDONLY);
        while ((leido = read(0, buffer, sizeof buffer)) > 0){
		
               	write(pah[1], buffer,leido);
		write(pas[1], buffer,leido);//diferencia con el anterior se crea otro pipe para mandar los datos del bash
}
close(pah[1]);
close(pas[1]);
     while ((leido = read(hap[0], buffer, sizeof buffer)) > 0){

                write(1,buffer,leido);
		

}

   
close(hap[0]);
// close(fdo);
//termina llamada hijo 1


        pipe(pah2);
        pipe(hap2);
        pad = fork();


//hijo 2i

if(pad == 0){

		close(pah2[1]);//cierra para no escribir en el pipe padre a hijo
                close(hap2[0]);//cierra para no leer en el pipe hijo a padre
               while ((leido2 = read(pah2[0], buffer1, sizeof buffer1)) > 0){
               
		for(i=0;i<leido2;i++){
               
		 if(isalnum(buffer1[i])){


                    a=a+1;
                }
                else{


                     count[a]=count[a] + 1;

                    a=0;
                }
                }

 	write(hap2[1],count,leido2);

	close(pah2[0]);
	close(hap2[1]);
}


return 0;

}
//termina hijo 2
close(pah2[0]);
close(hap2[1]);

//fda = open(argv[2],O_RDONLY);

        while ((leido2  = read(pas[0], buffer1, sizeof buffer1)) > 0){//recibe los datos del while anterior(pas)
                write(pah2[1],buffer1,leido2);
		

}
close(pah2[1]);
close(pas[0]);

        while ((leido2 = read(hap2[0], count, sizeof count)) > 0){
			
	//	 write(1,buffer1,leido2);

                for (int x=1 ; x<101; x++){
                        if(count[x] != 0){
                        printf("Letras %d: ", x);
                        printf(" %ld", count[x]);
                        printf("\n");
                        }

                }
}
 // hasta aca

close(hap2[0]);

//termina llamada a hijo 2
 close(fda);
  exit(EXIT_SUCCESS);


}

}
//}
return 0;
}
