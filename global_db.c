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
    fclose(file);
    return true;
}

size_t getNewUserId() {
    size_t value = (globalDatabase.userCount++);

    saveGlobalDatabase();
    return value;
}