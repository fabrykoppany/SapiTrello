//
// Created by koppa on 2021. 03. 23..
//

#include "register.h"

char* generatePassword(){
    char *password = (char *) calloc(16, sizeof(char));

    if (password == NULL){
        printf("Error allocating memory!\n");
        return NULL;
    }

    char numbers[10] = "0123456789";
    char symbols[8] = "!@#$^&*?";
    char lowerCaseLetters[26] = "abcdefghijklmnoqprstuvwyzx";
    char upperCaseLetters[26] = "ABCDEFGHIJKLMNOQPRSTUYWVZX";

    srand(time(0));

    for (int i = 0; i < 16; ++i){
        int randomChoice = rand() % 4;

        switch (randomChoice) {
            case 0: password[i] = numbers[rand() % 10]; break;
            case 1: password[i] = symbols[rand() % 8]; break;
            case 2: password[i] = lowerCaseLetters[rand() % 26]; break;
            case 3: password[i] = upperCaseLetters[rand() % 26]; break;
        }
    }

    return password;
}

USER createNewUser(){
    USER newUser;

    newUser.username = getUsername();

    while (fileExists(newUser)){
        printf("|->ERROR: This username is already taken. Please try something different.\n");
        newUser.username = getUsername();
    }

    newUser.passowrd = generatePassword();
    newUser.firstName = getFirstName();
    newUser.secondName = getSecondName();

    return newUser;
}



char *getFirstName(){
    char *firstName = (char *) malloc(30 * sizeof(char));

    if (firstName == NULL){
        printf("Error allocating memory!\n");
        return NULL;
    }

    printf("|->Your first name: ");
    scanf("%s", firstName);

    firstName[0] -= 32;

    return firstName;
}

char *getSecondName(){
    char *secondName = (char *) malloc(30 * sizeof(char));

    if (secondName == NULL){
        printf("Error allocating memory!\n");
        return NULL;
    }

    printf("|->Your second name: ");
    scanf("%s", secondName);

    return strupr(secondName);
}

void registerMenu(){
    system("cls");

    printf("REGISTER\n\n");

    USER user = createNewUser();
    printf("|->Your automatically generated password: %s\n", user.passowrd);
    writeToFile(user);
}