//
// Created by User on 2021/04/15.
//

#include "user_search.h"

IdEntry *addIdToEntryList(IdEntry *tail, id_t id) {
    IdEntry *entry = (IdEntry *) malloc(sizeof(IdEntry));

    if (entry == NULL) {
        printf("Could not allocate memory!\n");
        return NULL;
    }

    entry->id = id;
    entry->next = NULL;

    if (tail != NULL) {
        tail->next = entry;
    }

    return entry;
}

void freeIdEntryList(IdEntry *head) {
    IdEntry *p = head;

    while (p != NULL) {
        IdEntry *next = p->next;

        free(p);
        p = next;
    }
}

IdEntry *searchForUsersNotInBoard(BOARD *board) {
    IdEntry *head = NULL;
    IdEntry *tail = NULL;
    id_array_t *users = &(board->users);

    for (size_t i = 0; i < globalDatabase.userCount; ++i) {
        if (!idArrayContainsElement(users, i)) {
            tail = addIdToEntryList(tail, i);

            if (head == NULL) {
                head = tail;
            }
        }
    }

    return head;
}

id_t getIdFromList(IdEntry *head, size_t index) {
    IdEntry *p = head;

    for (size_t i = 0; i < index && p != NULL; ++i) {
        p = p->next;
    }

    if (p == NULL) {
        return INVALID_ID;
    }

    return p->id;
}