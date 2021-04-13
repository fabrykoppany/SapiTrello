//
// Created by User on 2021/04/13.
//

#ifndef PROJECT_01_USER_DB_H
#define PROJECT_01_USER_DB_H

#include "user.h"
#include "file.h"

char *getUserFilename(char *username);
bool userExists(char *username);
bool saveUser(USER *user);
USER *loadUser(char *username);
USER *loadUserById(id_t id);

#endif //PROJECT_01_USER_DB_H
