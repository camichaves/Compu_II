/** Headers **/

/* Pegar */

void processBuff(char *buff, char *output_file);
void joinFiles(char *part_file, char *output_file);

/* Cortar */

void splitFileBySize(char *input_name, char *output_name, int tam);
void splitFileByParts(char *input_name, char *output_name, int cant);
