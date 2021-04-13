//
// Created by User on 2021/04/13.
//

#ifndef PROJECT_01_BOARD_H
#define PROJECT_01_BOARD_H

#include "types.h"

typedef struct {
    id_t id;
    char *name;
    unsigned int userCount;
    id_t *userIds;
} BOARD;

#endif //PROJECT_01_BOARD_H
