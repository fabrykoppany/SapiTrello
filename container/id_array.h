//
// Created by User on 2021/04/13.
//

#ifndef PROJECT_01_ID_ARRAY_H
#define PROJECT_01_ID_ARRAY_H

#include <stdio.h>

#include "../util/types.h"

typedef struct id_array_t {
    size_t count;
    id_t *ids;
} id_array_t;

#include <stdbool.h>
#include <stdlib.h>

bool readIdArrayFromFile(FILE *file, id_array_t *array);
void writeIdArrayToFile(FILE *file, id_array_t *array);
bool addToIdArray(id_array_t *array, id_t id);
bool removeFromIdArray(id_array_t *array, id_t id);
bool isIdArrayEmpty(id_array_t *array);
bool idArrayContainsElement(id_array_t *array, id_t id);
void freeIdArray(id_array_t array);

#endif //PROJECT_01_ID_ARRAY_H
