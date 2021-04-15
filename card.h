//
// Created by User on 2021/04/13.
//

#ifndef PROJECT_01_CARD_H
#define PROJECT_01_CARD_H

#include "types.h"
#include "id_array.h"

enum CardState {
    TO_DO,
    DOING,
    DONE
};

typedef struct {
    id_t id;
    char *title;
    char *description;
    enum CardState state;
    id_t userId;
    id_array_t previousUserIds;
} CARD;

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "file.h"

CARD *readCardFromFile(FILE *file, id_t id);
void writeCardToFile(FILE *file, CARD *card);
CARD *createNewCard(id_t id, id_t userId, char *title, char *description);
void printShortCard(CARD *card);

#endif //PROJECT_01_CARD_H
