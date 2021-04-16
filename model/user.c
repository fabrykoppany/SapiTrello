//
// Created by koppa on 2021. 03. 23..
//

#include "user.h"

bool isCorrectPassword(USER *user, char *password) {
    // If the passwords are the same, they are correct.
    // Could use a hashing algorithm here, but since
    // passwords are randomly generated, there's not much point.
    return strcmp(user->password, password) == 0;
}

bool checkSpecialCharacters(const char* username) {
    // Usernames must not contain special characters.
    // This is because they're saved onto the disk using their username.
    char specialCharacters[11] = {92, 47, 58, 42, 63, 34, 60, 62, 124, 46};

    for (int i = 0; i < strlen(username); ++i) {
        char compareCharacter = username[i];

        for (int j = 0; j < 10; ++j) {
            if (compareCharacter == specialCharacters[j]) {
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

USER *createUser(char *username, char *password, char *firstName, char *secondName) {
    USER *newUser = (USER *) calloc(1, sizeof(USER));

    if (newUser == NULL) {
        printf("Could not allocate memory!\n");
        return NULL;
    }

    newUser->id = getNewUserId(username);
    newUser->username = username;
    newUser->password = password;
    newUser->firstName = firstName;
    newUser->secondName = secondName;

    saveUser(newUser);
    return newUser;
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