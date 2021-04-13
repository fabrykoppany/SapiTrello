//
// Created by User on 2021/04/13.
//

#include "board.h"

bool addUserToBoard(USER *user, BOARD *board) {
    return addToIdArray(&(board->users), user->id) && saveBoard(board);
}

BOARD *createNewBoard(char *name, USER *user) {
    BOARD *board = (BOARD *) malloc(sizeof(BOARD));

    if (board == NULL) {
        printf("Could not allocate memory!\n");
        return NULL;
    }

    board->id = getNewBoardId();
    board->name = name;
    board->users.count = 0;
    board->users.ids = NULL;

    addUserToBoard(user, board);
    addBoardToUser(user, board);
    return board;
}