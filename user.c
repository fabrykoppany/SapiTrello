//
// Created by koppa on 2021. 03. 23..
//

#include "user.h"

bool isCorrectPassword(USER *user, char *password) {
    return strcmp(user->password, password) == 0;
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

bool addBoardToUser(USER *user, BOARD *board) {
    return addToIdArray(&(user->boards), board->id) && saveUser(user);
}

bool removeBoardFromUser(USER *user, BOARD *board) {
    return removeFromIdArray(&(user->boards), board->id) && saveUser(user);
}

bool isSameUser(USER *a, USER *b) {
    return a->id == b->id;
}

void printShortUser(USER *user) {
    printf("%s (%s %s)", user->username, user->firstName, user->secondName);
}

void freeUser(USER *user) {
    free(user->username);
    free(user->password);
    free(user->firstName);
    free(user->secondName);
    freeIdArray(user->boards);
    free(user);
}