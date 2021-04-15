//
// Created by User on 2021/04/13.
//

#ifndef PROJECT_01_CARD_ARRAY_H
#define PROJECT_01_CARD_ARRAY_H

#include "types.h"
#include "card.h"
#include <stdio.h>

typedef struct card_array_t {
    size_t count;
    CARD **cards;
} card_array_t;

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool readCardArrayFromFile(FILE *file, card_array_t *array);
void writeCardArrayToFile(FILE *file, card_array_t *array);
bool addToCardArray(card_array_t *array, CARD *card);
bool removeFromCardArray(card_array_t *array, CARD *card);
bool isCardArrayEmpty(card_array_t *array);
bool cardArrayContainsElement(card_array_t *array, CARD *card);

#endif //PROJECT_01_CARD_ARRAY_H
