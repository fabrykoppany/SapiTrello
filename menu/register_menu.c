//
// Created by koppa on 2021. 03. 23..
//

#include "register_menu.h"

char *getUsername() {
    char *username = (char *) malloc(30 * sizeof(int));

    if (username == NULL) {
        printf("Error allocating memory!\n");
        return NULL;
    }

    printf("|->Username: ");
    scanf("%s", username);

    while (!checkSpecialCharacters(username)) {
        printf("ERROR: String may not contain special characters. Try another username:");
        scanf("%s", username);
    }

    return username;
}

char *generatePassword() {
    // We'll generate a random 16 character long password.
    char *password = (char *) calloc(17, sizeof(char));

    if (password == NULL) {
        printf("Error allocating memory!\n");
        return NULL;
    }

    char numbers[10] = "0123456789";
    char symbols[8] = "!@#$^&*?";
    char lowerCaseLetters[26] = "abcdefghijklmnoqprstuvwyzx";
    char upperCaseLetters[26] = "ABCDEFGHIJKLMNOQPRSTUYWVZX";

    // Seed our randmo generator...
    srand(time(0));

    for (int i = 0; i < 16; ++i) {
        int randomChoice = rand() % 4;

        switch (randomChoice) {
            case 0: password[i] = numbers[rand() % 10]; break;
            case 1: password[i] = symbols[rand() % 8]; break;
            case 2: password[i] = lowerCaseLetters[rand() % 26]; break;
            case 3: password[i] = upperCaseLetters[rand() % 26]; break;
        }
    }

    password[16] = '\0';
    return password;
}

USER *createNewUser() {
    char *username = getUsername();

    while (userExists(username)) {
        printf("|->ERROR: This username is already taken. Please try something different.\n");
        free(username);
        username = getUsername();
    }

    return createUser(username, generatePassword(), getFirstName(), getSecondName());
}

char *getFirstName() {
    char *firstName = (char *) malloc(30 * sizeof(char));

    if (firstName == NULL) {
        printf("Error allocating memory!\n");
        return NULL;
    }

    printf("|->Your first name: ");
    scanf("%s", firstName);

    return firstName;
}

char *getSecondName() {
    char *secondName = (char *) malloc(30 * sizeof(char));

    if (secondName == NULL) {
        printf("Error allocating memory!\n");
        return NULL;
    }

    printf("|->Your second name: ");
    scanf("%s", secondName);

    return secondName;
}

void registerMenu() {
    clearScreen();

    printf("REGISTER\n\n");

    USER *user = createNewUser();
    printf("|->Your automatically generated password: %s\n", user->password);
    getch();
    userMenu(user);
}
