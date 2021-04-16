//
// Created by User on 2021/04/13.
//

#include "board.h"

bool addUserToBoard(USER *user, BOARD *board) {
    return addToIdArray(&(board->users), user->id) && saveBoard(board);
}

bool removeUserFromBoard(USER *user, BOARD *board) {
    return removeFromIdArray(&(board->users), user->id) && saveBoard(board);
}

BOARD *createNewBoard(char *name, USER *user) {
    BOARD *board = (BOARD *) calloc(1, sizeof(BOARD));

    if (board == NULL) {
        printf("Could not allocate memory!\n");
        return NULL;
    }

    board->id = getNewBoardId();
    board->name = name;

    addUserToBoard(user, board);
    addBoardToUser(user, board);
    return board;
}

bool changeBoardName(BOARD *board, char *name) {
    free(board->name);
    board->name = name;
    return saveBoard(board);
}

bool addCardToBoard(BOARD *board, CARD *card) {
    return addToCardArray(&(board->cards), card) && saveBoard(board);
}

bool removeCardFromBoard(BOARD *board, CARD *card) {
    bool removed = removeFromCardArray(&(board->cards), card) && saveBoard(board);

    if (removed) {
        freeCard(card);
    }

    return removed;
}

void freeBoard(BOARD *board) {
    free(board->name);
    freeIdArray(board->users);
    freeCardArray(board->cards);
    free(board);
}