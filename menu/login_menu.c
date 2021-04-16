//
// Created by koppa on 2021. 04. 05..
//

#include "login_menu.h"

char *getUsernameLogin() {
    char *username = (char *) malloc(30 * sizeof(int));

    if (username == NULL) {
        printf("Error allocating memory!\n");
        return NULL;
    }

    printf("|->Username: ");
    scanf("%s", username);

    while (!checkSpecialCharacters(username)) {
        printf("ERROR: String may not contain special characters Try another username:");
        scanf("%s", username);
    }

    return username;
}

char *getPassword() {
    char *password = (char *) malloc(16 * sizeof(char));

    if (password == NULL) {
        printf("Error allocating memory!!!\n");
        return NULL;
    }

    printf("|->Password: ");
    scanf("%s", password);

    return password;
}

void loginMenu() {
    clearScreen();

    printf("LOGIN\n\n");
    int choice;

    char *username = getUsernameLogin();

    while (!userExists(username)) {
        printf("|->ERROR: No such user. Please try again!\n");
        free(username);
        username = getUsernameLogin();
    }

    USER *user = loadUser(username);
    free(username);

    if (user == NULL) {
        printf("Something has gone wrong.\n");
        return;
    }

    char *password = getPassword();

    while (!isCorrectPassword(user, password)) {
        free(password);

        int choice = 0;
        printf("|->ERROR: Password doesn't match! Please try again.\n");
        printf("|->If you want to change your password, press 1 followed by an ENTER.\n");
        scanf("%i", &choice);

        switch (choice) {
            case 1: newPassword(user); loginMenu(); return;
            default: password = getPassword();
        }
    }

    free(password);
    printf("Well done!");
    userMenu(user);
}

void newPassword(USER *user) {
    user->password = generatePassword();

    saveUser(user);

    printf("Your new automatically generated password is: %s", user->password);
    getch();
}
