//
// Created by User on 2021/04/13.
//

#ifndef PROJECT_01_CARD_ARRAY_H
#define PROJECT_01_CARD_ARRAY_H

#include "../util/types.h"
#include "../model/card.h"
#include <stdlib.h>

typedef struct card_array_t {
    size_t count;
    CARD **cards;
} card_array_t;

#include <stdbool.h>

bool readCardArrayFromFile(FILE *file, card_array_t *array);
void writeCardArrayToFile(FILE *file, card_array_t *array);
bool addToCardArray(card_array_t *array, CARD *card);
bool removeFromCardArray(card_array_t *array, CARD *card);
bool isCardArrayEmpty(card_array_t *array);
void freeCardArray(card_array_t array);

#endif //PROJECT_01_CARD_ARRAY_H
