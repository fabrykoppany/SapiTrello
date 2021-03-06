//
// Created by User on 2021/04/15.
//

#ifndef PROJECT_01_CARD_MENU_H
#define PROJECT_01_CARD_MENU_H

#include "../model/user.h"
#include "../model/board.h"
#include "../model/card.h"

void browseCardsWithState(USER *user, BOARD *board, enum CardState state);
void browseCards(USER *user, BOARD *board);
void createCard(USER *user, BOARD *board);
void cardMenu(USER *user, BOARD *board, CARD *card);
void renameCard(USER *user, BOARD *board, CARD *card);
void changeCardStatus(USER *user, BOARD *board, CARD *card);
void changeDescription(USER *user, BOARD *board, CARD *card);
void deleteCard(USER *user, BOARD *board, CARD *card);
void printPreviousUsers(CARD *card);
void listPreviousUsers(USER *user, BOARD *board, CARD *card);
void transferCard(USER *user, BOARD *board, CARD *card);
void abandonCard(USER *user, BOARD *board, CARD *card);
void takeCardOver(USER *user, BOARD *board, CARD *card);

#endif //PROJECT_01_CARD_MENU_H
