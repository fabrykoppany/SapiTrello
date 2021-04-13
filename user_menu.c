//
// Created by User on 2021/04/13.
//

#include "user_menu.h"

void createBoard(USER *user) {
    char *title = (char *) malloc(255 * sizeof(char));

    if (title == NULL){
        printf("Error allocating memory!\n");
        return;
    }

    clearScreen();

    printf("What would you like to call your new board?\n");
    scanf(" %[^\n]", title);

    BOARD *board = createNewBoard(title, user);
    userMenu(user);
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
    printf("Global database users: %u\n", globalDatabase.userCount);
    printf("Global database boards: %u\n", globalDatabase.boardCount);

    scanf("%i", &choice);

    switch (choice) {
        case 0: mainMenu(); break;
        case 1: createBoard(user); break;
        case 2: loginMenu(); break;
        default: printf("|->ERROR: Your choice didn't match any command. Please try again."); getch(); userMenu(user);
    }
}
