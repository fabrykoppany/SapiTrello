//
// Created by koppa on 2021. 04. 05..
//

#include "login.h"

char* getUsernameLogin(){
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

char *getPassword(){
    char *password = (char *) malloc(16 * sizeof(char));

    if (password == NULL){
        printf("Error allocating memory!!!\n");
        return NULL;
    }

    printf("|->Password: ");
    scanf("%s", password);

    return password;
}

void loginMenu(){
    system("cls");

    printf("LOGIN\n\n");

    USER user;
    int choice;

    user.username = getUsernameLogin();

    while (!fileExists(user)){
        printf("|->ERROR: No such user. Please try again!\n");
        user.username = getUsernameLogin();
    }

    user.passowrd = getPassword();

    USER testUser = readFile(user);

    while (strcmp(user.passowrd, testUser.passowrd) != 0){
        choice = 0;
        printf("|->ERROR: Password doesn't match! Please try again.\n");
        printf("|->If you want to change your password, press 1 followed by an ENTER.\n");
        scanf("%i", &choice);

        switch (choice) {
            case 1: newPassword(&testUser); testUser = readFile(user); loginMenu(); break;
            default: user.passowrd = getPassword();
        }
    }

    printf("Well done!");
}

void newPassword(USER *user){
    user->passowrd = generatePassword();

    writeToFile(*user);

    printf("Your new automatically generated password is: %s", user->passowrd);
    getch();
}