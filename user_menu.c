//
// Created by User on 2021/04/13.
//

#include "user_menu.h"

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
        case 0: mainMenu();
        case 2: registerMenu();
        case 1: loginMenu(); break;
        default: printf("|->ERROR: Your choice didn't match any command. Please try again."); getch(); userMenu(user);
    }
}
