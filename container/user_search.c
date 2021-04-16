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
            // Add a new element to our linked list.
            tail = addIdToEntryList(tail, i);

            if (head == NULL) {
                // This is our first element, so let's make sure to set the head.
                head = tail;
            }
        }
    }

    return head;
}

IdEntry *searchForDifferentUsers(BOARD *board, id_t ownId) {
    IdEntry *head = NULL;
    IdEntry *tail = NULL;

    for (size_t i = 0; i < board->users.count; ++i) {
        if (i != ownId) {
            // Add a new element to our linked list.
            tail = addIdToEntryList(tail, i);

            if (head == NULL) {
                // This is our first element, so let's make sure to set the head.
                head = tail;
            }
        }
    }

    return head;
}

id_t getIdFromList(IdEntry *head, size_t index) {
    // Head to the given index.
    IdEntry *p = head;

    for (size_t i = 0; i < index && p != NULL; ++i) {
        p = p->next;
    }

    if (p == NULL) {
        // If p is NULL, then this index does not exist.
        return INVALID_ID;
    }

    return p->id;
}