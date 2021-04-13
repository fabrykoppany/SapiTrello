//
// Created by User on 2021/04/13.
//

#ifndef PROJECT_01_BOARD_H
#define PROJECT_01_BOARD_H

#include "types.h"
#include "id_array.h"

typedef struct {
    id_t id;
    char *name;
    id_array_t users;
} BOARD;

#endif //PROJECT_01_BOARD_H
