//
// Created by User on 2021/04/15.
//

#ifndef PROJECT_01_USER_SEARCH_H
#define PROJECT_01_USER_SEARCH_H

#include "types.h"

typedef struct IdEntry {
    id_t id;
    struct IdEntry *next;
} IdEntry;

#include "board.h"
#include <stdlib.h>
#include <stdio.h>

IdEntry *addIdToEntryList(IdEntry *tail, id_t id);
void freeIdEntryList(IdEntry *head);
IdEntry *searchForUsersNotInBoard(BOARD *board);
id_t getIdFromList(IdEntry *head, size_t index);

#endif //PROJECT_01_USER_SEARCH_H
