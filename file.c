//
// Created by koppa on 2021. 03. 30..
//

#include "file.h"
#include "user_db.h"

char* getPrefixedFilename(const char *directory, char *filename){
    int length = strlen(directory) + strlen(filename) + strlen("/.bin");
    char *fileName = (char *) malloc((length + 1) * sizeof(int));

    if (fileName == NULL){
        printf("Error allocating memory!\n");
        return NULL;
    }

    strcpy(fileName, directory);
    strcat(fileName, "/");
    strcat(fileName, filename);
    strcat(fileName, ".bin");

    return fileName;
}

inline void writeStringToFile(FILE *file, char *str) {
    size_t length = strlen(str);
    fwrite(&length, sizeof(size_t), 1, file);
    fwrite(str, sizeof(char), length, file);
}

inline char *readStringFromFile(FILE *file) {
    size_t length;
    fread(&length, sizeof(size_t), 1, file);

    char *str = (char *) malloc((length + 1) * sizeof(char));

    if (str == NULL) {
        printf("Error allocating memory!\n");
        return NULL;
    }

    fread(str, sizeof(char), length, file);
    str[length] = '\0';
    return str;
}

inline bool readStringToField(FILE *file, char **field) {
    char *str = readStringFromFile(file);

    if (str == NULL) {
        return false;
    }

    (*field) = str;
    return true;
}

bool fileExists(char *filename) {
    FILE *file;

    if ((file = fopen(filename, "rb"))) {
        fclose(file);
        return true;
    }

    return false;
}
