//
// Created by User on 2021/04/13.
//

#include "utils.h"

/**
 * Reallocates a large buffer string.
 * For example, if you have a 2000 length buffer which holds a 50 length string,
 * this function will reallocate the string as to only take 50 bytes.
 *
 * @param buffer - The buffer to be reallocated.
 * @return A pointer to the reallocated string.
 */
char *reallocateBuffer(char *buffer) {
    return (char *) realloc(buffer, strlen(buffer) + 1);
}

/**
 * Clears the screen.
 * This does not work on IntelliJ's console, unfortunately.
 * IntellIJ does not implement the clear screen function in its Java console.
 */
void clearScreen() {
    system("cls");
}