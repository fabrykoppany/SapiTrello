//
// Created by koppa on 2021. 03. 30..
//

#ifndef PROJECT_01_FILE_H
#define PROJECT_01_FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "user.h"

char *getPrefixedFilename(const char *prefix, char *filename);
void writeStringToFile(FILE *file, char *str);
char *readStringFromFile(FILE *file);
bool readStringToField(FILE *file, char **field);
bool fileExists(char *filename);
char *unsignedIntToString(unsigned int value);

#endif //PROJECT_01_FILE_H
