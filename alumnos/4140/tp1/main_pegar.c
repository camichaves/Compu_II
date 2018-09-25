/** Cintia Ossandón - 2018 **/
/** Computacion 2 - Trabajo Practico N°1 **/

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int opt;
    int nreads;
    char *file_name = NULL;
    char buff[100];

    /* h: NO espera parametro, o: espera parametro */
    while ((opt = getopt(argc, argv, "ho:")) != -1) {
        switch (opt) {
            case 'h':
                printf("Modo de uso: \n ls part-* | ./pegar -o [archivo_salida]\n");
                return 0;
            case 'o':
                file_name = optarg;
                break;
	    default:
                printf("Modo de uso: \n ls part-* | ./pegar -o [archivo_salida]\n");
                return 0;
        }
    }

    while ((nreads = read(STDIN_FILENO, buff, sizeof buff)) > 0) {
        processBuff(buff, file_name);
    }

    return 0;
}
