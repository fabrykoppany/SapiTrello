//
// Created by koppa on 2021. 03. 30..
//

#include "file.h"

char* getFileName(USER user){
    int length = strlen(user.username) + 1;

    char *fileName = (char *) malloc((length + 10) * sizeof(int));

    if (fileName == NULL){
        printf("Error allocating memory!\n");
        return NULL;
    }

    strcpy(fileName, "Users/");
    strcat(fileName, user.username);
    strcat(fileName, ".bin");

    return fileName;
}

/*void createFileForWriting(USER user){
    char *fileName = getFileName(user);

    FILE *file = fopen(fileName, "wb");

    if (file == NULL){
        printf("Error opening file!");
        return;
    }

    int length = strlen(user.username), *pointer = &length;

    fwrite(pointer, sizeof(int), 1, file);
    fwrite(user.username, sizeof(char *), strlen(user.username), file);

    fclose(file);
}*/

void writeToFile(USER user){
    char *fileName = getFileName(user);

    FILE *file = fopen(fileName, "wb");

    if (file == NULL){
        printf("Error opening file!");
        return;
    }

    int length = strlen(user.username) + strlen(user.passowrd) + strlen(user.firstName) + strlen(user.secondName) + 3, *pointer = &length;
    char *userDetails = (char *) calloc(length + 3, sizeof(char));

    strcpy(userDetails, user.username);
    strcat(userDetails, " ");
    strcat(userDetails, user.passowrd);
    strcat(userDetails, " ");
    strcat(userDetails, user.firstName);
    strcat(userDetails, " ");
    strcat(userDetails, user.secondName);

    fwrite(pointer, sizeof(int), 1, file);
    fwrite(userDetails, sizeof(char *), length, file);

    /*fwrite(pointer, sizeof(int), 1, file);
    fwrite(user.username, sizeof(char *), strlen(user.username), file);

    length = strlen(user.passowrd);

    fwrite(pointer, sizeof(int), 1, file);
    fwrite(user.passowrd, sizeof(char *), strlen(user.passowrd), file);

    length = strlen(user.firstName);

    fwrite(pointer, sizeof(int), 1, file);
    fwrite(user.firstName, sizeof(char *), strlen(user.firstName), file);

    length = strlen(user.secondName);

    fwrite(pointer, sizeof(int), 1, file);
    fwrite(user.secondName, sizeof(char *), strlen(user.secondName), file);*/

    fclose(file);
}

USER readFile(const char* fileName){
    FILE *fin = fopen(fileName, "rb");

    if (fileName == NULL){
        printf("ERROR: There is no such user.");
    }

    int length;

    fread(&length, sizeof(int), 1, fin);

    char *userDetails = (char *) calloc(length, sizeof(char));

    fread(userDetails, sizeof(char), length, fin);

    /*char *username = (char *) malloc((length) * sizeof(char));
    fread(username, sizeof(char), length, fin);

    fread(&length, sizeof(int), 1, fin);
    char *password = (char *) malloc((length) * sizeof(char));
    fread(password, sizeof(char), length, fin);

    fread(&length, sizeof(int), 1, fin);
    char *firstName = (char *) malloc((length) * sizeof(char));
    fread(firstName, sizeof(char), length, fin);

    fread(&length, sizeof(int), 1, fin);
    char *secondName = (char *) malloc((length) * sizeof(char));
    fread(secondName, sizeof(char), length, fin);*/

    fclose(fin);

    USER user;
    char *readString;

    readString = strtok(userDetails, " ");
    user.username = (char *) calloc(strlen(readString), sizeof(char));
    strcpy(user.username, readString);

    readString = strtok(NULL, " ");
    user.passowrd = (char *) calloc(strlen(readString), sizeof(char));
    strcpy(user.passowrd, readString);

    readString = strtok(NULL, " ");
    user.firstName = (char *) calloc(strlen(readString), sizeof(char));
    strcpy(user.firstName, readString);

    readString = strtok(NULL, " ");
    user.secondName = (char *) calloc(strlen(readString), sizeof(char));
    strcpy(user.secondName, readString);

    //printf("%s", userDetails);

    //printf("%s %s %s %s", username, password, firstName, secondName);

    return user;
}