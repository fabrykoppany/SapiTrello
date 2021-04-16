//
// Created by User on 2021/04/13.
//

#include "card.h"
#include "user_db.h"

CARD *readCardFromFile(FILE *file) {
    CARD *card = (CARD *) calloc(1, sizeof(CARD));

    if (card == NULL) {
        return NULL;
    }

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

CARD *createNewCard(id_t userId, char *title, char *description) {
    CARD *card = (CARD *) calloc(1, sizeof(CARD));

    if (card == NULL) {
        return NULL;
    }

    card->userId = userId;
    card->title = title;
    card->description = description;
    card->state = TO_DO;
    addToIdArray(&(card->previousUserIds), userId);
    return card;
}

void printCardUser(CARD *card) {
    if (card->userId == INVALID_ID) {
        printf("no one");
        return;
    }

    USER *user = loadUserById(card->userId);

    if (user == NULL) {
        printf("unknown user");
    } else {
        printShortUser(user);
    }

    freeUser(user);
}

void printShortCard(CARD *card) {
    printf("%s, worked on by ", card->title);
    printCardUser(card);
    printf(" [%s]", getCardProgress(card));
}

const char *cardStateAsString(enum CardState state) {
    switch (state) {
        case TO_DO:
            return "TO DO";
        case DOING:
            return "IN PROGRESS";
        case DONE:
            return "COMPLETE";
        default:
            return "UNKNOWN";
    }
}

const char *getCardProgress(CARD *card) {
    return cardStateAsString(card->state);
}

void freeCard(CARD *card) {
    free(card->title);
    free(card->description);
    freeIdArray(card->previousUserIds);
    free(card);
}

bool addPreviousCollaborator(CARD *card, id_t userId) {
    return !idArrayContainsElement(&(card->previousUserIds), userId) && addToIdArray(&(card->previousUserIds), userId);
}

void removeUserFromCard(CARD *card) {
    card->userId = INVALID_ID;
}

void setNewCardUser(CARD *card, id_t userId) {
    card->userId = userId;
    addPreviousCollaborator(card, userId);
}