//
// Created by User on 2021/04/13.
//

#include "ui.h"

void clearScreen() {
    system("cls");
}

char* getUsername() {
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
