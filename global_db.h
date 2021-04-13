//
// Created by User on 2021/04/13.
//

#ifndef PROJECT_01_GLOBAL_DB_H
#define PROJECT_01_GLOBAL_DB_H

#include <stdbool.h>
#include <stdio.h>

#define GLOBAL_DB_FILENAME "global_db.bin"

typedef struct global_db_t {
    size_t userCount;
    size_t boardCount;
} global_db_t;

global_db_t globalDatabase;

bool loadGlobalDatabase();
bool saveGlobalDatabase();
size_t getNewUserId();
size_t getNewBoardId();

#endif //PROJECT_01_GLOBAL_DB_H
