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

    USER user;

    user.username = getUsernameLogin();
    user.passowrd = getPassword();

    USER testUser = readFile(user);

    if (strcmp(user.passowrd, testUser.passowrd) != 0){
        printf("Password doesn't match!");
        return;
    }

    printf("Well done!");
}