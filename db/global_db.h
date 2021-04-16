//
// Created by User on 2021/04/13.
//

#ifndef PROJECT_01_GLOBAL_DB_H
#define PROJECT_01_GLOBAL_DB_H

#include <stdbool.h>
#include <stdio.h>

#include "../util/file.h"

#define GLOBAL_DB_FILENAME "global_db.bin"

typedef struct global_db_t {
    size_t userCount;
    size_t boardCount;
    char **userMap;
} global_db_t;

global_db_t globalDatabase;

bool loadGlobalDatabase();
bool saveGlobalDatabase();
size_t getNewUserId(char *username);
size_t getNewBoardId();
char *getUsernameFromId(id_t id);

#endif //PROJECT_01_GLOBAL_DB_H
