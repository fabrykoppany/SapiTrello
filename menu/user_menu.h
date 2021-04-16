//
// Created by User on 2021/04/13.
//

#ifndef PROJECT_01_USER_MENU_H
#define PROJECT_01_USER_MENU_H

#include "board_menu.h"
#include "../model/user.h"
#include "../util/utils.h"
#include "../db/board_db.h"
#include "../main.h"

void createBoard(USER *user);
void listBoards(USER *user);
void userMenu(USER *user);

#endif //PROJECT_01_USER_MENU_H
