//
// Created by koppa on 2021. 03. 23..
//

#ifndef PROJECT_01_REGISTER_H
#define PROJECT_01_REGISTER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "user.h"
#include "file.h"

char* generatePassword();
USER *createNewUser();
char* getFirstName();
char* getSecondName();
void registerMenu();

#endif //PROJECT_01_REGISTER_H
