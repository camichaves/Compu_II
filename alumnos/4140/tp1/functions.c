/** Functions **/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/*
 * Lee el contenido de 'part_file' y lo copia en 'output_file'
 */
void joinFiles(char *part_file, char *output_file) {

    int fd_in;
    int fd_out;
    int cant;
    char buff[100];

    if (output_file != NULL) {

        if (fd_out = open(output_file, O_CREAT | O_RDWR | O_APPEND, 0777)) {

            if (fd_in = open(part_file, O_RDONLY)) {

                while ((cant = read(fd_in, buff, sizeof buff)) > 0) {
                    write(fd_out, buff, cant);
                }

            } else {
                perror("open part file");
                exit(EXIT_FAILURE);
            }

        } else {
            perror("open output file");
            exit(EXIT_FAILURE);
        }

        close(fd_in);
        close(fd_out);

    } else {

        /* SALIDA POR PANTALLA */
        if (fd_in = open(part_file, O_RDONLY)) {

            while ((cant = read(fd_in, buff, sizeof buff)) > 0) {
                write(STDOUT_FILENO, buff, cant);
            }

        } else {
            perror("open part file");
            exit(EXIT_FAILURE);
        }

        close(fd_in);

    }
}

/*
 * Dividivos el buff en palabras
 */
void processBuff(char* buff, char *output_file) {

    char *name;
    char delim[] = " \n";

    /* TODO: ordenar archivos para ser leidos correctamente */

    name = strtok(buff, delim);

    while (name != NULL) {
        joinFiles(name, output_file);
        name = strtok(NULL, delim);
    }
}

/*
 * Dividivos 'input_name' por 'tam' generando 'output_name'
 */
void splitFileBySize(char *input_name, char *output_name, int tam) {

    int fd_in;
    int fd_out;
    int i;
    int nread;
    int cant;
    char buff[1000];
    char *name;
    struct stat buf;

    stat(input_name, &buf);
    cant = buf.st_size/tam+1;

    if (output_name != NULL) {

        strcat(output_name, "-");

        if (fd_in = open(input_name, O_RDONLY)) {

            for (i=0; i<cant; i++) {

                sprintf(name, "%s%d", output_name, i);

                if (fd_out = open(name, O_CREAT | O_RDWR, 0777)) {

                    nread = read(fd_in, buff, tam);
                    write(fd_out, buff, nread);

                } else {
                    perror("open output file");
                    exit(EXIT_FAILURE);
                }
            }

        } else {
            perror("open input file");
            exit(EXIT_FAILURE);
        }

        close(fd_in);
        close(fd_out);

    } else {
        /* SALIDA POR PANTALLA */

        if (fd_in = open(input_name, O_RDONLY)) {

            for (i=0; i<cant; i++) {

                nread = read(fd_in, buff, tam);
                write(STDOUT_FILENO, buff, nread);
            }

        } else {
            perror("open input file");
            exit(EXIT_FAILURE);
        }

        close(fd_in);

    }

}

/*
 * Dividivos 'input_name' por 'cant' generando 'output_name'
 */
void splitFileByParts(char *input_name, char *output_name, int cant) {

    int fd_in;
    int fd_out;
    int i;
    int nread;
    int max_size;
    char *name;
    char buff[1000];
    struct stat buf;

    stat(input_name, &buf);
    max_size = buf.st_size/cant;

    if (output_name != NULL) {

        strcat(output_name, "-");

        if (fd_in = open(input_name, O_RDONLY)) {

            for (i=0; i<cant; i++) {

                sprintf(name, "%s%d", output_name, i);

                if (fd_out = open(name, O_CREAT | O_RDWR, 0777)) {

                    nread = read(fd_in, buff, max_size);
                    write(fd_out, buff, nread);

                } else {
                    perror("open output file");
                    exit(EXIT_FAILURE);
                }
            }

        } else {
            perror("open input file");
            exit(EXIT_FAILURE);
        }

        close(fd_in);
        close(fd_out);

    } else {
        /* SALIDA POR PANTALLA */

        if (fd_in = open(input_name, O_RDONLY)) {

            for (i=0; i<cant; i++) {

                nread = read(fd_in, buff, max_size);
                write(STDOUT_FILENO, buff, nread);
            }

        } else {
            perror("open input file");
            exit(EXIT_FAILURE);
        }

        close(fd_in);
    }

}
