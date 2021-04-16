//
// Created by koppa on 2021. 03. 30..
//

#include "file.h"

/**
 * Returns a relative file path comprised of a directory and a filename.
 *
 * @param directory - The relative directory of the file.
 * @param filename - The relative filename of the file.
 * @return A file path containing both the directory name and the filename.
 */
char* getPrefixedFilename(const char *directory, char *filename) {
    // Allocate enough space for the new filename
    int length = strlen(directory) + strlen(filename) + strlen("/.bin");
    char *fileName = (char *) malloc((length + 1) * sizeof(int));

    if (fileName == NULL) {
        printf("Error allocating memory!\n");
        return NULL;
    }

    // Format: [directory]/[filename].bin
    strcpy(fileName, directory);
    strcat(fileName, "/");
    strcat(fileName, filename);
    strcat(fileName, ".bin");

    return fileName;
}

/**
 * Writes a string to a file. This string can later be read
 * using the readStringFromFile method.
 *
 * @param file - An open file handle to write to.
 * @param str - The string you would like to write to the file.
 */
void writeStringToFile(FILE *file, char *str) {
    // Strings are written to files in an interesting way:
    // First, we store the actual length of the string.
    // Afterwards, we store the string itself in the file.
    size_t length = strlen(str);

    fwrite(&length, sizeof(size_t), 1, file);
    fwrite(str, sizeof(char), length, file);
}

/**
 * Reads a string from a file. This string must have been
 * written to the file using the writeStringToFile method.
 *
 * @param file - An open file handle to read from.
 * @return The string found at the current position of the file.
 */
char *readStringFromFile(FILE *file) {
    // First, read the actual length of the string.
    size_t length;
    fread(&length, sizeof(size_t), 1, file);

    // Allocate enough characters, plus one for the null terminator.
    char *str = (char *) malloc((length + 1) * sizeof(char));

    if (str == NULL) {
        printf("Error allocating memory!\n");
        return NULL;
    }

    // Read the actual string.
    fread(str, sizeof(char), length, file);

    // Add the required null-terminator.
    str[length] = '\0';
    return str;
}

/**
 * Reads a string from a file, and then populates a given
 * field inside a structure. This string must have been
 * written to the file using the writeStringToFile method.
 *
 * @param file - An open file handle to read from.
 * @param field - A pointer pointing to the variable to be filled.
 * @return A boolean representing the success state of the method.
 */
bool readStringToField(FILE *file, char **field) {
    // First, read the string from the file...
    char *str = readStringFromFile(file);

    if (str == NULL) {
        // Memory could not be allocated.
        return false;
    }

    // Set the field now!
    (*field) = str;
    return true;
}

/**
 * Converts an unsigned integer to a string.
 *
 * @param value - The unsigned integer to convert.
 * @return A string representing the unsigned integer in decimal form.
 */
char *unsignedIntToString(unsigned int value) {
    // First, figure out the length of the string...
    int length = snprintf(NULL, 0, "%u", value);

    // Next, allocate enough characters for the string...
    char *str = (char *) malloc((length + 1) * sizeof(char));

    if (str == NULL) {
        printf("Could not allocate memory!\n");
        return NULL;
    }

    // Finally, add the unsigned integer to the string.
    // This automatically null terminates the string.
    snprintf(str, length + 1, "%d", value);
    return str;
}

/**
 * Checks if the given file exists on the file system.
 *
 * @param filename - The filename to check.
 * @return A boolean, true if the file exists, false if it does not.
 */
bool fileExists(char *filename) {
    FILE *file;

    // Try to open the file. If we can open it, it exists.
    if ((file = fopen(filename, "rb"))) {
        fclose(file);
        return true;
    }

    // We couldn't open the file, it does not exist.
    return false;
}
