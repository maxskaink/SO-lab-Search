/**
 * @file search.h
 * @brief Rutinas para busqueda de archivos
 * @author Miguel Calambas
 * @copyright MIT license
 */

#ifndef SEARCH_H
#define SEARCH_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * @brief Checks if path is drectory
 * @param path Path to check
 * @return 1 if path is directory, 0 otherwise
 */
int is_dir(char * path);

/**
 * @brief Recursively search files/forlders containing pattern
 * @param dir Directory to search
 * @param pattern Pattern(text) inside file/folder name to match
 * @return Number of matches
 */
int search(char * dir, char * pattern);

#endif