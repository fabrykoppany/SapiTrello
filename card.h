//
// Created by User on 2021/04/13.
//

#ifndef PROJECT_01_CARD_H
#define PROJECT_01_CARD_H

#include "types.h"

enum CardState {
    TO_DO,
    DOING,
    DONE
};

typedef struct {
    id_t id;
    id_t boardId;
    char *title;
    char *description;
    enum CardState state;
    id_t userId;
} CARD;

#endif //PROJECT_01_CARD_H
