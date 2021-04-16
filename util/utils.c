//
// Created by User on 2021/04/13.
//

#include "utils.h"

char *reallocateBuffer(char *buffer) {
    return (char *) realloc(buffer, strlen(buffer) + 1);
}

void clearScreen() {
    system("cls");
}