//
// Created by User on 2021/04/13.
//

#include "board_menu.h"

void renameBoard(USER *user, BOARD *board) {
    char *title = (char *) malloc(255 * sizeof(char));

    if (title == NULL){
        printf("Error allocating memory!\n");
        return;
    }

    clearScreen();

    printf("Your board is currently called:\n%s\n", board->name);
    printf("What would you like to call your board?\n");
    printf("(to leave unchanged, type \"exit\")\n");
    scanf(" %[^\n]", title);

    if (strcasecmp(title, "exit") == 0) {
        free(title);
        boardMenu(user, board);
        return;
    }

    title = reallocateBuffer(title);

    if (!changeBoardName(board, title)) {
        printf("Could not change board name!\n");
        getch();
        return;
    }

    boardMenu(user, board);
}

void printBoardUsers(BOARD *board) {
    for (size_t i = 0; i < board->users.count; ++i) {
        USER *user = loadUserById(board->users.ids[i]);

        if (user != NULL) {
            printf("%llu. %s\n", i + 1, user->username);
            free(user);
        }
    }
}

void boardUsers(USER *user, BOARD *board) {
    clearScreen();

    printf("=====================\n");
    printf("BOARD USER MANAGEMENT\n");;
    printf("=====================\n");
    printf("-- %s -- \n\n", board->name);

    printf("Users currently contributing to board:\n");
    printBoardUsers(board);

    printf("\nPress any key to go back...\n");
    getch();
    boardMenu(user, board);
}

void kickUser(USER *user, BOARD *board) {
    clearScreen();

    printf("=====================\n");
    printf("BOARD USER MANAGEMENT\n");;
    printf("=====================\n");
    printf("-- %s -- \n\n", board->name);

    printf("Which user would you like to kick from this board?\n\n");
    printf("Users currently contributing to board:\n");
    printBoardUsers(board);
    printf("0. None, head back\n");

    int choice;
    scanf("%d", &choice);

    if (choice == 0 || choice > board->users.count) {
        boardMenu(user, board);
        return;
    }

    USER *boardUser = loadUserById(board->users.ids[choice - 1]);

    if (boardUser == NULL) {
        printf("Could not load the requested user!\n");
        getch();
    } else if (!removeUserFromBoard(user, board) || !removeBoardFromUser(user, board)) {
        printf("Could not remove the requested user from the board.\n");
        getch();
    }

    if (isSameUser(user, boardUser)) {
        // If we've kicked ourselves...
        listBoards(user);
        return;
    }

    // Bring the user back to the kick menu
    kickUser(user, board);
}

void leaveBoard(USER *user, BOARD *board) {
    clearScreen();

    printf("*** WARNING!!! ***\n");
    printf("You are about to leave the following board:\n");
    printf("- %s\n", board->name);
    printf("\nThis may be a permanent decision.\nAre you sure you want to leave this board?\n\n");
    printf("1. Yes, leave the group\n");
    printf("0. No, head back\n");

    int choice;
    scanf("%d", &choice);

    if (choice != 1) {
        boardMenu(user, board);
        return;
    }

    if (!removeUserFromBoard(user, board) || !removeBoardFromUser(user, board)) {
        printf("Could not leave board!\n");
        getch();
    }

    listBoards(user);
}

void boardMenu(USER *user, BOARD *board) {
    clearScreen();

    printf("=====\n");
    printf("BOARD\n");;
    printf("=====\n");
    printf("-- %s -- \n\n", board->name);

    printf("1. Rename board\n");
    printf("2. List users\n");
    printf("3. Kick user from board\n");
    printf("4. Leave board indefinitely\n");
    printf("0. Back to board list\n");

    int choice;
    scanf("%i", &choice);

    switch (choice) {
        case 1: renameBoard(user, board); return;
        case 2: boardUsers(user, board); return;
        case 3: kickUser(user, board); return;
        case 4: leaveBoard(user, board); return;
        case 0: listBoards(user); return;
        default: boardMenu(user, board); return;
    }
}