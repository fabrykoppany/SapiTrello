//
// Created by koppa on 2021. 03. 23..
//

#ifndef PROJECT_01_USER_H
#define PROJECT_01_USER_H

#include "../util/types.h"
#include "../container/id_array.h"

typedef struct USER {
    id_t id;
    char *username, *password;
    char *firstName, *secondName;
    id_array_t boards;
} USER;

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include <dos.h>

#include "board.h"

#include "../menu/register_menu.h"
#include "../menu/login_menu.h"

bool isCorrectPassword(USER *user, char *password);
bool checkSpecialCharacters(const char *username);

bool addBoardToUser(USER *user, BOARD *board);
bool removeBoardFromUser(USER *user, BOARD *board);
bool isSameUser(USER *a, USER *b);

USER *createUser(char *username, char *password, char *firstName, char *secondName);

void printShortUser(USER *user);
void freeUser(USER *user);

#endif //PROJECT_01_USER_H
