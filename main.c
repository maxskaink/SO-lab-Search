/**
 * @file main.c
 * @brief Busqueda de archivos
 * @author Miguel Calambas <mangelcvivas@unicauca.edu.co>
 * @copyright MIT license
 */

#include <stdio.h>
#include <stdlib.h>
#include "search.h"

/**
 * @brief Imprime la ayuda del comando
 * @param program nombre del programa ejecutable
 */
void usage(char * program);

int main(int argc, char *argv[]) {
    
    char * dir;
    char * pattern;
    
    if( argc != 3){
        usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    dir = argv[1];
    pattern = argv[2];

    printf("Buscando archivos en %s que contengan %s\n", dir, pattern);
    int total = search(dir, pattern);
    printf("Total de archivos encontrados: %d\n", total);
    exit(EXIT_SUCCESS);
}

void usage(char * program) {
    printf("Usage: %s DIR PATTERN \n"
          "\t Prints files/directories that match PATTERN from DIR\n", program);
}
