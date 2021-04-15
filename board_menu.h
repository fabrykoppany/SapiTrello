//
// Created by User on 2021/04/13.
//

#ifndef PROJECT_01_BOARD_MENU_H
#define PROJECT_01_BOARD_MENU_H

#include "user.h"
#include "board.h"
#include "user_menu.h"
#include "ui.h"
#include "user_search.h"

void renameBoard(USER *user, BOARD *board);
void boardMenu(USER *user, BOARD *board);
void boardUsers(USER *user, BOARD *board);
void printBoardUsers(BOARD *board);
void printSoughtUsers(IdEntry *head);
void leaveBoard(USER *user, BOARD *board);
void kickUser(USER *user, BOARD *board);
void inviteUser(USER *user, BOARD *board);
void browseCards(USER *user, BOARD *board);
void createCard(USER *user, BOARD *board);

#endif //PROJECT_01_BOARD_MENU_H
