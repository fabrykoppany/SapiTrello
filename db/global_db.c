//
// Created by User on 2021/04/13.
//

#include "global_db.h"

bool loadGlobalDatabase() {
    FILE *file = fopen(GLOBAL_DB_FILENAME, "rb");

    if (file == NULL) {
        // Database does not exist, let's create it.
        globalDatabase.userCount = 0;
        globalDatabase.boardCount = 0;
        return saveGlobalDatabase() && loadGlobalDatabase();
    }

    fread(&(globalDatabase.userCount), sizeof(size_t), 1, file);
    fread(&(globalDatabase.boardCount), sizeof(size_t), 1, file);

    if (globalDatabase.userCount == 0) {
        globalDatabase.userMap = NULL;
        fclose(file);
        return true;
    }

    globalDatabase.userMap = (char **) malloc(globalDatabase.userCount * sizeof(char *));

    if (globalDatabase.userMap == NULL) {
        printf("Could not allocate memory!\n");
        return false;
    }

    for (size_t i = 0; i < globalDatabase.userCount; ++i) {
        if (!readStringToField(file, &globalDatabase.userMap[i])) {
            return false;
        }
    }

    fclose(file);
    return true;
}

bool saveGlobalDatabase() {
    FILE *file = fopen(GLOBAL_DB_FILENAME, "wb");

    if (file == NULL) {
        printf("Could not open global database for writing!\n");
        return false;
    }

    fwrite(&(globalDatabase.userCount), sizeof(size_t), 1, file);
    fwrite(&(globalDatabase.boardCount), sizeof(size_t), 1, file);

    for (size_t i = 0; i < globalDatabase.userCount; ++i) {
        writeStringToFile(file, globalDatabase.userMap[i]);
    }

    fclose(file);
    return true;
}

bool addUserToMap(char *username) {
    if (globalDatabase.userCount == 0) {
        globalDatabase.userMap = (char **) malloc(sizeof(char *));
    } else {
        globalDatabase.userMap = (char **) realloc(globalDatabase.userMap, (globalDatabase.userCount + 1) * sizeof(char *));
    }

    if (globalDatabase.userMap == NULL) {
        printf("Could not allocate memory!\n");
        return false;
    }

    globalDatabase.userMap[globalDatabase.userCount] = username;
    return true;
}

size_t getNewUserId(char *username) {
    addUserToMap(username);
    size_t value = (globalDatabase.userCount++);

    saveGlobalDatabase();
    return value;
}

size_t getNewBoardId() {
    size_t value = (globalDatabase.boardCount++);

    saveGlobalDatabase();
    return value;
}

char *getUsernameFromId(id_t id) {
    if (id >= globalDatabase.userCount) {
        // This user is not available in the global database.
        return NULL;
    }

    return globalDatabase.userMap[id];
}