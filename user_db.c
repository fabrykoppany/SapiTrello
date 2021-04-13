//
// Created by User on 2021/04/13.
//

#include "user_db.h"

char *getUserFilename(char *username) {
    return getPrefixedFilename("Users", username);
}

bool userExists(char *username) {
    char *filename = getUserFilename(username);
    bool result = fileExists(filename);

    free(filename);
    return result;
}

bool saveUser(USER *user) {
    char *fileName = getUserFilename(user->username);

    FILE *file = fopen(fileName, "wb");

    if (file == NULL) {
        printf("Error opening file!");
        free(fileName);
        return false;
    }

    fwrite(&(user->id), sizeof(unsigned int), 1, file);
    writeStringToFile(file, user->username);
    writeStringToFile(file, user->password);
    writeStringToFile(file, user->firstName);
    writeStringToFile(file, user->secondName);

    fclose(file);
    free(fileName);
    return true;
}

USER *loadUser(char *username) {
    USER *user = (USER *) malloc(sizeof(USER));

    if (user == NULL) {
        printf("Could not allocate memory!\n");
        return NULL;
    }

    char *fileName = getUserFilename(username);
    FILE *file = fopen(fileName, "rb");

    if (file == NULL) {
        printf("Error opening file!");
        free(fileName);
        free(user);
        return NULL;
    }

    fread(&(user->id), sizeof(unsigned int), 1, file);
    readStringToField(file, &(user->username));
    readStringToField(file, &(user->password));
    readStringToField(file, &(user->firstName));
    readStringToField(file, &(user->secondName));
    fclose(file);
    return user;
}