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

bool addToIdArray(id_array_t *array, id_t id) {
    if (array->count == 0) {
        array->ids = (id_t *) malloc(sizeof(id_t));
    } else {
        array->ids = (id_t *) realloc(array->ids, (array->count + 1) * sizeof(id_t));
    }

    if (array->ids == NULL) {
        printf("Could not allocate memory!\n");
        return false;
    }

    array->ids[array->count++] = id;
    return true;
}

bool removeFromIdArray(id_array_t *array, id_t id) {
    for (size_t i = 0; i < array->count; ++i) {
        if (array->ids[i] == id) {
            --array->count;

            for (size_t j = i; j < array->count; ++j) {
                array->ids[j] = array->ids[j + 1];
            }

            if (array->count == 0) {
                // Special case: no elements left.
                free(array->ids);
                array->ids = NULL;
                return true;
            }

            array->ids = (id_t *) realloc(array->ids, array->count * sizeof(id_t));
            return array->ids != NULL;
        }
    }

    return false;
}

bool isIdArrayEmpty(id_array_t *array) {
    return array->count == 0;
}

bool idArrayContainsElement(id_array_t *array, id_t id) {
    for (size_t i = 0; i < array->count; ++i) {
        if (array->ids[i] == id) {
            return true;
        }
    }

    return false;
}

void freeIdArray(id_array_t array) {
    free(array.ids);
}