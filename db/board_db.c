//
// Created by User on 2021/04/13.
//

#include "board_db.h"

char *getBoardFilename(id_t id) {
    char *strId = unsignedIntToString(id);
    char *filename = getPrefixedFilename("Boards", strId);

    free(strId);
    return filename;
}

bool boardExists(id_t id) {
    // Our board exists if the file exists.
    char *filename = getBoardFilename(id);
    bool result = fileExists(filename);

    free(filename);
    return result;
}

bool saveBoard(BOARD *board) {
    char *fileName = getBoardFilename(board->id);

    FILE *file = fopen(fileName, "wb");

    if (file == NULL) {
        printf("Error opening file!");
        free(fileName);
        return false;
    }

    fwrite(&(board->id), sizeof(id_t), 1, file);
    writeStringToFile(file, board->name);
    writeIdArrayToFile(file, &(board->users));
    writeCardArrayToFile(file, &(board->cards));

    fclose(file);
    free(fileName);
    return true;
}

BOARD *loadBoard(id_t id) {
    BOARD *board = (BOARD *) calloc(1, sizeof(BOARD));

    if (board == NULL) {
        printf("Could not allocate memory!\n");
        return NULL;
    }

    char *fileName = getBoardFilename(id);
    FILE *file = fopen(fileName, "rb");

    if (file == NULL) {
        printf("Error opening file!");
        free(fileName);
        free(board);
        return NULL;
    }

    fread(&(board->id), sizeof(id_t), 1, file);
    readStringToField(file, &(board->name));

    if (!readIdArrayFromFile(file, &(board->users)) || !readCardArrayFromFile(file, &(board->cards))) {
        fclose(file);
        free(board);
        return NULL;
    }

    fclose(file);
    return board;
}