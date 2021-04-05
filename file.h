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

char* getFileName(USER user);
//void createFileForWriting(USER user);
void writeToFile(USER user);
USER readFile(USER user);

#endif //PROJECT_01_FILE_H
