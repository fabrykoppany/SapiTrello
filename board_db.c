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
    fwrite(&(board->userCount), sizeof(unsigned int), 1, file);
    fwrite(board->userIds, sizeof(id_t), board->userCount, file);

    fclose(file);
    free(fileName);
    return true;
}

BOARD *loadBoard(id_t id) {
    BOARD *board = (BOARD *) malloc(sizeof(BOARD));

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
    fread(&(board->userCount), sizeof(unsigned int), 1, file);

    board->userIds = (id_t *) malloc(board->userCount * sizeof(id_t));

    if (board->userIds == NULL) {
        printf("Could not allocate memory!\n");
        free(board);
        return NULL;
    }

    fread(board->userIds, sizeof(id_t), board->userCount, file);
    fclose(file);
    return board;
}