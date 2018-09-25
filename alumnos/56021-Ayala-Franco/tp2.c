#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <sys/wait.h>

#define BUFFER_SIZE 100
#define MAX_PALABRA 21

void proc_uno(int fd);
void proc_dos(int fd);

int main(int argc, char ** argv) {
	getopt(argc, argv, "f:");   
	int fd = open(optarg, O_RDONLY);
	if (fd == -1) {
		perror("open");
		return EXIT_FAILURE;
	}

	int pipe_uno[2];
	pipe(pipe_uno);
	if(fork() == 0) {
		close(pipe_uno[1]);
		proc_uno(pipe_uno[0]);
		return 0;
	}
	close(pipe_uno[0]);

	int pipe_dos[2];
	pipe(pipe_dos);
	if(fork() == 0) {
		close(pipe_dos[1]);
		close(pipe_uno[1]);
		proc_dos(pipe_dos[0]);
		return 0;
	}
	close(pipe_dos[0]);

	char buffer[BUFFER_SIZE] = "";
	int n;
	while((n = read(fd, buffer, BUFFER_SIZE)) > 0) {
		write(pipe_uno[1], buffer, n); 
		write(pipe_dos[1], buffer, n);
	}   

	close(pipe_uno[1]);
	close(pipe_dos[1]);
	//wait(NULL);
	//wait(NULL);
	return 0;
}

void proc_uno(int fd) {
	int palabras[MAX_PALABRA] = {0};
	char buffer[BUFFER_SIZE] = "";
	int letras = 0;
	int n;
	while((n = read(fd, buffer, BUFFER_SIZE)) > 0) {
		for(int e = 0; e < n; e++) {
			if(isalpha(buffer[e]))
				letras++;
			else {
				if(letras <= MAX_PALABRA) 
					palabras[letras - 1]++;
				letras = 0;
			}
		}
	}
	for(int e = 0; e < MAX_PALABRA; e++)
		if(palabras[e] != 0)
			printf("%d. %d\n", e+1, palabras[e]);
}

void uppercase(char *palabra) {
	if(strcmp(palabra, "al")  == 0 || strcmp(palabra, "los") == 0 || strcmp(palabra, "rey") == 0 || strcmp(palabra, "industrializados") == 0 || strcmp(palabra, "independencia") == 0 || strcmp(palabra, "militar") == 0)
		for(int x = 0; x < strlen(palabra); x++)
			palabra[x] = toupper(palabra[x]);
}

void proc_dos(int fd) {
	char buffer[BUFFER_SIZE] = "";
	char palabra[MAX_PALABRA+1] = ""; 
	int k = 0;
	int n;
	while((n = read(fd, buffer, BUFFER_SIZE)) > 0) {
		for(int e = 0; e < n; e++) {
			if(isalpha(buffer[e])) {
				if (k <= MAX_PALABRA)
					palabra[k++] = buffer[e];
			}
			else {
				palabra[k] = '\0';
				uppercase(palabra);
				printf("%s%c", palabra, buffer[e]);
				k = 0;
			}
		}
	}
	palabra[k] = '\0';
	uppercase(palabra);
	printf("%s", palabra);
}
