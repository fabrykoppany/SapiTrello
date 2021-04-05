//
// Created by koppa on 2021. 03. 23..
//

#include "user.h"

char* getUsername(){
    char *username = (char *) malloc(30 * sizeof(int));

    if (username == NULL){
        printf("Error allocating memory!\n");
        return NULL;
    }

    printf("|->Username: ");
    scanf("%s", username);

    while (!checkSpecialCharacters(username)){
        printf("ERROR: String may not contain special characters Try another username:");
        scanf("%s", username);
    }

    return username;
}

bool checkSpecialCharacters(const char* username){
    char specialCharacters[11] = {92, 47, 58, 42, 63, 34, 60, 62, 124, 46};

    for (int i = 0; i < strlen(username); ++i){
        char compareCharacter = username[i];

        for (int j = 0; j < 10; ++j){
            if (compareCharacter == specialCharacters[j]){
                return false;
            }
        }
    }

    return true;
}

void mainMenu(){
    int choice;

    system("cls");

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

/*USER allocateMemoryForUser(){
    char *username = ()

    return
}*/

/*
void *registerUser(const char* fileName){
    char *userNameToRegister = (char *) malloc(30 * sizeof(int));

    if (userNameToRegister == NULL){
        printf("Error allocating memory!");
        return;
    }


}*/
