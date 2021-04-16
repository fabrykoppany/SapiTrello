//
// Created by User on 2021/04/13.
//

#ifndef PROJECT_01_BOARD_MENU_H
#define PROJECT_01_BOARD_MENU_H

#include "user_menu.h"
#include "card_menu.h"
#include "../model/user.h"
#include "../model/board.h"
#include "../util/utils.h"
#include "../container/user_search.h"

void renameBoard(USER *user, BOARD *board);
void boardMenu(USER *user, BOARD *board);
void boardUsers(USER *user, BOARD *board);
void printBoardUsers(BOARD *board);
void printSoughtUsers(IdEntry *head, id_t startIndex);
void leaveBoard(USER *user, BOARD *board);
void kickUser(USER *user, BOARD *board);
void inviteUser(USER *user, BOARD *board);

#endif //PROJECT_01_BOARD_MENU_H
