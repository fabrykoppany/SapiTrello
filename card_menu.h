//
// Created by User on 2021/04/15.
//

#ifndef PROJECT_01_CARD_MENU_H
#define PROJECT_01_CARD_MENU_H

#include "user.h"
#include "board.h"
#include "card.h"

void browseCards(USER *user, BOARD *board);
void createCard(USER *user, BOARD *board);
void cardMenu(USER *user, BOARD *board, CARD *card);
void renameCard(USER *user, BOARD *board, CARD *card);
void changeTitle(char *title, USER *user, BOARD *board, CARD *card);
void changeCardStatus(USER *user, BOARD *board, CARD *card);
void changeStatus(int status, USER *user, BOARD *board, CARD *card);
void changeDescription(USER *user, BOARD *board, CARD *card);
void changeText(char *text, USER *user, BOARD *board, CARD *card);
void deleteCard(USER *user, BOARD *board, CARD *card);
void printPreviousUsers(CARD *card);
void listPreviousUsers(USER *user, BOARD *board, CARD *card);
void transferCard(USER *user, BOARD *board, CARD *card);
void abandonCard(USER *user, BOARD *board, CARD *card);
void takeCardOver(USER *user, BOARD *board, CARD *card);

#endif //PROJECT_01_CARD_MENU_H
