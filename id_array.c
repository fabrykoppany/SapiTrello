//
// Created by User on 2021/04/13.
//

#include "id_array.h"

bool readIdArrayFromFile(FILE *file, id_array_t *array) {
    fread(&(array->count), sizeof(size_t), 1, file);

    if (array->count == 0) {
        // Special case: empty array.
        array->ids = NULL;
        return true;
    }

    array->ids = (id_t *) malloc(array->count * sizeof(id_t));

    if (array->ids == NULL) {
        printf("Could not allocate memory!\n");
        return false;
    }

    fread(array->ids, sizeof(id_t), array->count, file);
    return true;
}

void writeIdArrayToFile(FILE *file, id_array_t *array) {
    fwrite(&(array->count), sizeof(size_t), 1, file);

    if (array->count > 0) {
        fwrite(array->ids, sizeof(id_t), array->count, file);
    }
}