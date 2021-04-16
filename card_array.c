//
// Created by User on 2021/04/13.
//

#include "card_array.h"

bool readCardArrayFromFile(FILE *file, card_array_t *array) {
    fread(&(array->count), sizeof(size_t), 1, file);

    if (array->count == 0) {
        // Special case: empty array.
        array->cards = NULL;
        return true;
    }

    array->cards = (CARD **) malloc(array->count * sizeof(CARD *));

    if (array->cards == NULL) {
        printf("Could not allocate memory!\n");
        return false;
    }

    for (size_t i = 0; i < array->count; ++i) {
        CARD *card = readCardFromFile(file);

        if (card != NULL) {
            array->cards[i] = card;
        }
    }

    return true;
}

void writeCardArrayToFile(FILE *file, card_array_t *array) {
    fwrite(&(array->count), sizeof(size_t), 1, file);

    for (size_t i = 0; i < array->count; ++i) {
        writeCardToFile(file, array->cards[i]);
    }
}

bool addToCardArray(card_array_t *array, CARD *card) {
    if (array->count == 0) {
        array->cards = (CARD **) malloc(sizeof(CARD *));
    } else {
        array->cards = (CARD **) realloc(array->cards, (array->count + 1) * sizeof(CARD *));
    }

    if (array->cards == NULL) {
        printf("Could not allocate memory!\n");
        return false;
    }

    array->cards[array->count++] = card;
    return true;
}

bool removeFromCardArray(card_array_t *array, CARD *card) {
    for (size_t i = 0; i < array->count; ++i) {
        if (array->cards[i] == card) {
            --array->count;

            for (size_t j = i; j < array->count; ++j) {
                array->cards[j] = array->cards[j + 1];
            }

            if (array->count == 0) {
                // Special case: no elements left.
                free(array->cards);
                array->cards = NULL;
                return true;
            }

            array->cards = (CARD **) realloc(array->cards, array->count * sizeof(CARD *));
            return array->cards != NULL;
        }
    }

    return false;
}

bool isCardArrayEmpty(card_array_t *array) {
    return array->count == 0;
}

bool cardArrayContainsElement(card_array_t *array, CARD *card) {
    for (size_t i = 0; i < array->count; ++i) {
        if (array->cards[i] == card) {
            return true;
        }
    }

    return false;
}

void freeCardArray(card_array_t array) {
    for (size_t i = 0; i < array.count; ++i) {
        freeCard(array.cards[i]);
    }

    free(array.cards);
}