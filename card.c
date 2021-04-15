//
// Created by User on 2021/04/13.
//

#include "card.h"

CARD *readCardFromFile(FILE *file, id_t id) {
    CARD *card = (CARD *) calloc(1, sizeof(CARD));

    if (card == NULL) {
        return NULL;
    }

    card->id = id;
    readStringToField(file, &(card->title));
    readStringToField(file, &(card->description));
    fread(&(card->state), sizeof(enum CardState), 1, file);
    fread(&(card->userId), sizeof(id_t), 1, file);
    readIdArrayFromFile(file, &(card->previousUserIds));
    return card;
}

void writeCardToFile(FILE *file, CARD *card) {
    writeStringToFile(file, card->title);
    writeStringToFile(file, card->description);
    fwrite(&(card->state), sizeof(enum CardState), 1, file);
    fwrite(&(card->userId), sizeof(id_t), 1, file);
    writeIdArrayToFile(file, &(card->previousUserIds));
}

CARD *createNewCard(id_t id, id_t userId, char *title, char *description) {
    CARD *card = (CARD *) calloc(1, sizeof(CARD));

    if (card == NULL) {
        return NULL;
    }

    card->id = id;
    card->userId = userId;
    card->title = title;
    card->description = description;
    card->state = TO_DO;
    addToIdArray(&(card->previousUserIds), userId);
    return card;
}