# COMPUTACION II


## TP1

Fecha de entrega: 8/05/2018


### Problema

Realizar una aplicación que sirva para unir partes de archivos en un solo archivo, y otra para dividir un archivo en una cantidad de partes iguales.

La cantidad de partes a cortar del archivo se puede indicar con la opcion -n [cantidad] o con la opcion -s [tamaño] (ambas son excluyentes).

Tanto la aplicacion cortar como dividir deben soportar la opcion -o [archivo_de_salida]. Si no se especifica nada, la salida se envía a stdout.

Si se invocan ambas aplicaciones con la opcion -h, muestran la ayuda y terminan.

Pegar y cortar reciben los datos de stdin. Cortar adicionalmente tiene la opcion -i.


### Requerimientos

* Las aplicaciones deberán ser compiladas con make.
* Cada aplicación deberá contener como mínimo 2 funciones.


#### Ejemplo modo de uso

~~~~~~~~~~~~~~~~~~~
$ ls part-* | ./pegar -o [archivo_salida]
$ ./cortar -s 400 -i [archivo_entrada] -o [archivo_salida]
~~~~~~~~~~~~~~~~~~~


### Objetivos

* Aprender a utilizar la redirección de la entrada y salida.

* Manejo de archivos (apertura, escritura y cierre).

* Utilizar un archivo Makefile para el proceso de compilación y testeo.



#### Tips

* Funciones para el manejo de cadenas de caracteres en la biblioteca string.h
* read()
* write()
* open()
* close()
* getopt()
