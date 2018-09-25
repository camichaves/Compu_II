# COMPUTACION II


## TP2

Fecha de entrega: 12/06/2018


### Desafío

Realizar una aplicación que procese un archivo por estandar input o un archvio especificado con la opción -f. El 
proceso padre leerá parte del archivo y se lo enviará a dos procesos hijos por un pipe a cada uno. Cada procsso
realizará su trabajo y mostrará el resultado por pantalla.

Uno de los procesos contará la cantidad de palabras de N caracteres (cant de palabras de un caracter, de dos, de
tres, etc), mientras que el otro cambiará las palabras que encuentre en el texto, de un conjunto de palabras 
reservadas, a mayúsculas.


### Requerimientos

* Utilizar make para compilar la aplicación.

* La aplicación deberá contener como mínimo 3 funciones incluyendo el main.

* Utilizar getopt para el manejo de argumentos.


#### Ejemplo modo de uso

~~~~~~~~~~~~~~~~~~~
$ cat file | ./tp2
$ ./tp2 -i [archivo]
~~~~~~~~~~~~~~~~~~~


### Objetivos

* Utilizar un archivo Makefile para el proceso de compilación y testeo.

* Ejercitar multiprocesamiento con fork.

* Entender las ventajas y desventajas de comunicar procesos mediante pipes.


#### Tips

* Funciones para el manejo de cadenas de caracteres en la biblioteca string.h
* Sincronización de procesos mediante pipes.

