//
// Created by koppa on 2021. 04. 05..
//

#ifndef PROJECT_01_LOGIN_MENU_H
#define PROJECT_01_LOGIN_MENU_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../model/user.h"
#include "../util/file.h"
#include "../db/user_db.h"
#include "../util/utils.h"
#include "user_menu.h"

char *getUsernameLogin();
char *getPassword();
void loginMenu();
void newPassword(USER *user);

#endif //PROJECT_01_LOGIN_MENU_H
