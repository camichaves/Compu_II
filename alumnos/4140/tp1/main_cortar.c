/** Cintia Ossandón - 2018 **/
/** Computacion 2 - Trabajo Practico N°1 **/

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int opt;
    int tam=-1;
    int cant=-1;
    char *output_name = NULL;
    char *input_name = NULL;

    /* h: NO espera parametro, osni: espera parametro */
    while ((opt = getopt(argc, argv, "ho:s:n:i:")) != -1) {
        switch (opt) {
            case 'h':
                printf("Modo de uso: \n ./cortar -s 400 -i [archivo_entrada] -o [archivo_salida]\n");
                return 0;
            case 'o':
                output_name = optarg;
                break;
            case 's':
                tam = atoi(optarg);
                break;
            case 'n':
                cant = atoi(optarg);
                break;
            case 'i':
                input_name = optarg;
                break;
            default:
                printf("Modo de uso: \n ./cortar -s 400 -i [archivo_entrada] -o [archivo_salida]\n");
                return 0;
        }
    }

    /* Chequeamos campos obligatorios. PD: no encontre forma de hacerlo con getopt() */
    if (input_name == NULL) {
        printf("debe indicar un archivo de entrada (-i)\n");
        return 0;
    }
    if (tam == -1 && cant == -1) {
        printf("debe indicar tamanio (-n) o cantidad (-s)\n");
        return 0;
    }
    /* ------------------------------ */

    if (tam) {
        splitFileBySize(input_name, output_name, tam);
    } else {
        splitFileByParts(input_name, output_name, cant);
    }

    return 0;
}
