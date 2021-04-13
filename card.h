//
// Created by User on 2021/04/13.
//

#ifndef PROJECT_01_CARD_H
#define PROJECT_01_CARD_H

enum CardState {
    TO_DO,
    DOING,
    DONE
};

typedef struct {
    unsigned int id;
    unsigned int boardId;
    char *title;
    char *description;
    enum CardState state;
    unsigned int userId;
} CARD;

#endif //PROJECT_01_CARD_H
