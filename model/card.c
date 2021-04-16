//
// Created by User on 2021/04/13.
//

#include "card.h"
#include "../db/user_db.h"

CARD *readCardFromFile(FILE *file) {
    CARD *card = (CARD *) calloc(1, sizeof(CARD));

    if (card == NULL) {
        printf("Could not allocate memory!\n");
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
        printf("Could not allocate memory!\n");
        return NULL;
    }

    // The default state of each card is TO_DO.
    // By default, the user who creates the card is the
    // owner of the card.
    card->userId = userId;
    card->title = title;
    card->description = description;
    card->state = TO_DO;
    addToIdArray(&(card->previousUserIds), userId);
    return card;
}

void printCardUser(CARD *card) {
    // Either there's no user assigned to the card....
    if (card->userId == INVALID_ID) {
        printf("no one");
        return;
    }

    USER *user = loadUserById(card->userId);

    if (user == NULL) {
        // or we don't know about this specific user...
        printf("unknown user");
    } else {
        // or we know about the exact user assigned.
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

void changeCardTitle(CARD *card, char *title) {
    free(card->title);
    card->title = title;
}

void changeCardDescription(CARD *card, char *description) {
    free(card->description);
    card->description = description;
}

void changeCardState(CARD *card, enum CardState state) {
    card->state = state;
}