//
// Created by User on 2021/04/13.
//

#include "user_menu.h"

void createBoard(USER *user) {
    char *title = (char *) malloc(255 * sizeof(char));

    if (title == NULL) {
        printf("Error allocating memory!\n");
        return;
    }

    clearScreen();

    printf("What would you like to call your new board?\n");
    scanf(" %[^\n]", title);
    title = reallocateBuffer(title);

    BOARD *board = createNewBoard(title, user);
    boardMenu(user, board);
    freeBoard(board);
}

void listBoards(USER *user) {
    clearScreen();

    if (isIdArrayEmpty(&user->boards)) {
        printf("You are not currently active in any boards.\n");
        printf("Press any key to continue...\n");

        getch();
        userMenu(user);
        return;
    }

    printf("Which board would you like to browse to?\n\n");

    // Print all boards available to the user.
    for (size_t i = 0; i < user->boards.count; ++i) {
        BOARD *board = loadBoard(user->boards.ids[i]);

        if (board != NULL) {
            printf("|->%llu. %s\n", i + 1, board->name);
            freeBoard(board);
        }
    }

    printf("|->0. Back to menu\n");

    int choice;
    scanf("%i", &choice);

    // The user would like to head back.
    if (choice == 0 || choice > user->boards.count) {
        userMenu(user);
        return;
    }

    // Load the board into memory and browse into it.
    BOARD *board = loadBoard(user->boards.ids[choice - 1]);
    boardMenu(user, board);
    freeBoard(board);
}

void userMenu(USER *user) {
    int choice;
    clearScreen();

    printf("Welcome to SapiTrello!\n\n");
    printf("============\n   BOARDS   \n============\n");
    printf("|->1. Create a brand new board!\n");
    printf("|->2. Access your personal boards.\n");
    printf("\n============\n  GENERAL   \n============\n");
    printf("|->0. exit - Logout and go back to the main menu.\n");
    printf("\n################################\n");
    printf("Please type in your choice followed by an Enter: ");

    scanf("%i", &choice);

    switch (choice) {
        case 0: mainMenu(); break;
        case 1: createBoard(user); break;
        case 2: listBoards(user); break;
        default: printf("|->ERROR: Your choice didn't match any command. Please try again."); getch(); userMenu(user);
    }
}
