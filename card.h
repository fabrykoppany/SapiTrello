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

CARD *readCardFromFile(FILE *file);
void writeCardToFile(FILE *file, CARD *card);

CARD *createNewCard(id_t userId, char *title, char *description);

void printCardUser(CARD *card);
void printShortCard(CARD *card);

const char *cardStateAsString(enum CardState state);
const char *getCardProgress(CARD *card);

void freeCard(CARD *card);

bool addPreviousCollaborator(CARD *card, id_t userId);
void removeUserFromCard(CARD *card);

void setNewCardUser(CARD *card, id_t userId);
void changeCardTitle(CARD *card, char *title);
void changeCardDescription(CARD *card, char *description);
void changeCardState(CARD *card, enum CardState state);

#endif //PROJECT_01_CARD_H
