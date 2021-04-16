//
// Created by koppa on 2021. 03. 23..
//

#ifndef PROJECT_01_REGISTER_MENU_H
#define PROJECT_01_REGISTER_MENU_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../model/user.h"
#include "../util/file.h"
#include "../db/user_db.h"
#include "../db/global_db.h"
#include "../util/utils.h"

char *getUsername();
char *generatePassword();
USER *createNewUser();
char *getFirstName();
char *getSecondName();
void registerMenu();

#endif //PROJECT_01_REGISTER_MENU_H
