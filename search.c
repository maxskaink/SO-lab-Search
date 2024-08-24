/**
 * @file search.c
 * @brief Implementacion de las rutinas para busqueda de archivos
 * @author Miguel Calambas
 * @copyright MIT License
 */


#include "search.h"


int is_dir(char * path) {
    //Usar la funcion stat para obtener la informacion de la ruta
    struct stat st;
    int result = stat(path, &st);

    if (result < 0) {
        perror("stat");
        return 0;
    }

    //Usar el macro S_ISDIR sobre el atributo st_mode de la estructura
    //para verificar si es un directorio

    if(S_ISDIR(st.st_mode))
        return 1;
    else 
        return 0;
}

int search(char * dir, char * pattern) {
    int total = 0;

    //Abrir directorio con opendir
    DIR * dirp = opendir(dir);

    //Validamos si se pudo abrir el directorio
    if(dirp == NULL){
        perror("opendir");
        return 0;
    }

    //Leemos el directorio con readdir
    struct dirent * entry; 
    while( ( entry = readdir(dirp)) != NULL){

        //Contruimos la ruta completa  directorio/ent->d_name
        char * fullpath = malloc(strlen(dir) + strlen(entry->d_name) + 2);
        sprintf(fullpath, "%s/%s", dir, entry->d_name);

        //Verificamos si la entrada contiene el patron de busqueda
        if(strstr(entry->d_name, pattern) != NULL){
            printf("%s\n", fullpath);
            total++;
        }
        //Si la entrada es un directorio, llamamos recursivamente a search
        //Se debe descartar los directorios . y ..

        if(is_dir(fullpath) && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0){
            total += search(fullpath, pattern);
        }

    }
    closedir(dirp);
    return total;
}