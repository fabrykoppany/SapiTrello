//
// Created by User on 2021/04/13.
//

#ifndef PROJECT_01_BOARD_H
#define PROJECT_01_BOARD_H

#include "../util/types.h"
#include "../container/id_array.h"
#include "../container/card_array.h"

typedef struct BOARD {
    id_t id;
    char *name;
    id_array_t users;
    card_array_t cards;
} BOARD;

#include "user.h"

bool addUserToBoard(USER *user, BOARD *board);
bool removeUserFromBoard(USER *user, BOARD *board);
BOARD *createNewBoard(char *name, USER *user);
bool changeBoardName(BOARD *board, char *name);
bool addCardToBoard(BOARD *board, CARD *card);
bool removeCardFromBoard(BOARD *board, CARD *card);
void freeBoard(BOARD *board);

#endif //PROJECT_01_BOARD_H
