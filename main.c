#include "main.h"

void mainMenu() {
    int choice;

    clearScreen();

    printf("Welcome to SapiTrello!\n\n");
    printf("|->1. login - Log in to an existing user account.\n|->2. register - Register a new user account.\n");
    printf("|->0. exit - Exit SapiTrello.\n");
    printf("################################\n");
    printf("Please type in your choice followed by an Enter: ");
    scanf("%i", &choice);

    switch (choice) {
        case 0: exit(0);
        case 2: registerMenu();
        case 1: loginMenu(); break;
        default: printf("|->ERROR: Your choice didn't match any command. Please try again."); getch(); mainMenu();
    }
}

int main() {
    if (!loadGlobalDatabase()) {
        return;
    }

    mkdir("Users");
    mkdir("Boards");
    mainMenu();
    return 0;
}
