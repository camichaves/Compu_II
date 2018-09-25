# COMPUTACION II


## TP3

Fecha de entrega: 18/09/2018


### Desafío

Realizar una aplicación que procese un archivo por estandar input o un archvio especificado con la opción -f. El 
proceso padre leerá parte del archivo y lo escribirá en un espacio de memoria compartida. El acceso a dicha 
memoria estará protegida por un semáforo. Luego de escribir en memoria, el proceso padre señalizará a los
procesos para que puedan consumir de memoria. Luego, cada proceso realizará su trabajo y mostrará el resultado 
por pantalla.

Uno de los procesos contará la cantidad de palabras de N caracteres (cant de palabras de un caracter, de dos, de
tres, etc), mientras que el otro cambiará las palabras que encuentre en el texto, de un conjunto de palabras 
reservadas, a mayúsculas.


### Requerimientos

* Utilizar make para compilar la aplicación.

* La aplicación deberá contener como mínimo 3 módulos y 5 funciones además del main.

* Utilizar getopt para el manejo de argumentos.


#### Ejemplo modo de uso

~~~~~~~~~~~~~~~~~~~
$ cat file | ./tp3
$ ./tp3 -i [archivo]
~~~~~~~~~~~~~~~~~~~


### Objetivos

* Utilizar un archivo Makefile para el proceso de compilación y testeo.

* Ejercitar multiprocesamiento con fork.

* Aprender a comunicar dos o más procesos a través de memoria compartida.

* Sincronizar el acceso a un recurso compartido a través de semáforos.


#### Tips

