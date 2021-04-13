//
// Created by koppa on 2021. 04. 05..
//

#ifndef PROJECT_01_LOGIN_H
#define PROJECT_01_LOGIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "user.h"
#include "file.h"
#include "user_db.h"
#include "ui.h"

char *getPassword();
void loginMenu();
void newPassword(USER *user);

#endif //PROJECT_01_LOGIN_H
