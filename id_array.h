//
// Created by User on 2021/04/13.
//

#ifndef PROJECT_01_ID_ARRAY_H
#define PROJECT_01_ID_ARRAY_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "types.h"

typedef struct id_array_t {
    size_t count;
    id_t *ids;
} id_array_t;

bool readIdArrayFromFile(FILE *file, id_array_t *array);
void writeIdArrayToFile(FILE *file, id_array_t *array);

#endif //PROJECT_01_ID_ARRAY_H
