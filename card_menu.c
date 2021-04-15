//
// Created by User on 2021/04/15.
//

#include "card_menu.h"

void browseCards(USER *user, BOARD *board) {

}

void createCard(USER *user, BOARD *board) {
    char *title = (char *) malloc(255 * sizeof(char));

    if (title == NULL) {
        printf("Error allocating memory!\n");
        return;
    }

    char *description = (char *) malloc(2000 * sizeof(char));

    if (description == NULL) {
        printf("Error allocating memory!\n");
        return;
    }

    clearScreen();

    printf("What would you like to call this card?\n");
    scanf(" %[^\n]", title);
    title = reallocateBuffer(title);

    printf("Please provide a short description! (2000 characters or less)\n");
    scanf(" %[^\n]", description);
    description = reallocateBuffer(description);

    CARD *card = createNewCard(getNextCardId(board), user->id, title, description);
    printf("card descrption %s\n", card->description);
    addCardToBoard(board, card);
    cardMenu(user, board, card);
}

void cardMenu(USER *user, BOARD *board, CARD *card) {

}