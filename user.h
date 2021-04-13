//
// Created by koppa on 2021. 03. 23..
//

#ifndef PROJECT_01_USER_H
#define PROJECT_01_USER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include <dos.h>

#include "types.h"

typedef struct USER {
    id_t id;
    char *username, *password;
    char *firstName, *secondName;
} USER;

#include "register.h"
#include "login.h"

bool isCorrectPassword(USER *user, char *password);
bool checkSpecialCharacters(const char *username);
//USER allocateMemoryForUser();

#endif //PROJECT_01_USER_H
