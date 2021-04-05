//
// Created by koppa on 2021. 03. 23..
//

#ifndef PROJECT_01_USER_H
#define PROJECT_01_USER_H

typedef struct{
    char *username, *passowrd;
    char *firstName, *secondName;
}USER;

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include "register.h"
#include "login.h"

char* getUsername();
bool checkSpecialCharacters(const char*);
void mainMenu();
//USER allocateMemoryForUser();

#endif //PROJECT_01_USER_H
