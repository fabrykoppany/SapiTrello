//
// Created by User on 2021/04/13.
//

#ifndef PROJECT_01_BOARD_H
#define PROJECT_01_BOARD_H

#include "types.h"
#include "id_array.h"
#include "card_array.h"

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
id_t getNextCardId(BOARD *board);
bool addCardToBoard(BOARD *board, CARD *card);

#endif //PROJECT_01_BOARD_H
