//
// Created by User on 2021/04/15.
//

#include "card_menu.h"

void browseCards(USER *user, BOARD *board) {
    clearScreen();

    if (isCardArrayEmpty(&board->cards)) {
        printf("This board does not have any cards.\n");
        printf("Press any key to continue...\n");

        getch();
        boardMenu(user, board);
        return;
    }

    printf("Which card would you like to open?\n\n");

    for (size_t i = 0; i < board->cards.count; ++i) {
        CARD *card = board->cards.cards[i];

        printf("%llu. ", i + 1);
        printShortCard(card);
        printf("\n");
    }

    printf("0. Back to menu\n");

    int choice;
    scanf("%i", &choice);

    if (choice == 0 || choice > board->cards.count) {
        boardMenu(user, board);
        return;
    }

    CARD *card = board->cards.cards[choice - 1];
    cardMenu(user, board, card);
}

void createCard(USER *user, BOARD *board) {
    char *title = (char *) malloc(255 * sizeof(char));

    if (title == NULL) {
        printf("Error allocating memory!\n");
        return;
    }

    char *description = (char *) malloc(2000 * sizeof(char));

    if (description == NULL) {
        printf("Error allocating memory!\n");
        return;
    }

    clearScreen();

    printf("What would you like to call this card?\n");
    scanf(" %[^\n]", title);
    title = reallocateBuffer(title);

    printf("Please provide a short description! (2000 characters or less)\n");
    scanf(" %[^\n]", description);
    description = reallocateBuffer(description);

    CARD *card = createNewCard(getNextCardId(board), user->id, title, description);
    addCardToBoard(board, card);
    cardMenu(user, board, card);
}

void renameCard(USER *user, BOARD *board, CARD *card) {
    // KOPPANY
}

void changeCardStatus(USER *user, BOARD *board, CARD *card) {
    // KOPPANY
}

void changeDescription(USER *user, BOARD *board, CARD *card) {
    // KOPPANY
}

void deleteCard(USER *user, BOARD *board, CARD *card) {
    // DANIEL
}

void listPreviousUsers(USER *user, BOARD *board, CARD *card) {
    // DANIEL
}

void transferCard(USER *user, BOARD *board, CARD *card) {
    // DANIEL
}

void abandonCard(USER *user, BOARD *board, CARD *card) {
    // KOPPANY
    // Ask user if he wants to abandon the card
    // If yes, card->userId = INVALID_ID (that's all)
}

void takeCardOver(USER *user, BOARD *board, CARD *card) {
    // DANIEL
}

void decideJoinOrLeave(USER *user, BOARD *board, CARD *card) {
    if (card->userId == user->id) {
        abandonCard(user, board, card);
    } else if (card->userId != INVALID_ID) {
        takeCardOver(user, board, card);
    }
}

void cardMenu(USER *user, BOARD *board, CARD *card) {
    clearScreen();

    printf("====\n");
    printf("CARD\n");;
    printf("====\n");
    printf("-- %s -- \n", card->title);
    printf("-- %s --\n\n", getCardProgress(card));
    printf("Owned by: ");
    printCardUser(card);
    printf("\n");

    printf("+-+ Short description: +-+\n");
    printf("%s\n\n", card->description);

    printf("+-------------+\n");
    printf("Card Management\n");
    printf("+-------------+\n");
    printf("1. Rename card\n");
    printf("2. Change card status\n");
    printf("3. Change description\n");
    printf("4. Delete card\n");
    printf("\n");

    printf("+-------------+\n");
    printf("User Management\n");
    printf("+-------------+\n");
    printf("5. List all collaborators until now\n");
    printf("6. Transfer card to user\n");

    if (card->userId == user->id) {
        printf("7. Abandon card\n");
    } else if (card->userId != INVALID_ID) {
        printf("7. Take card over\n");
    }

    printf("0. Back to board\n");

    int choice;
    scanf("%i", &choice);

    switch (choice) {
        case 1: renameCard(user, board, card); return;
        case 2: changeCardStatus(user, board, card); return;
        case 3: changeDescription(user, board, card); return;
        case 4: deleteCard(user, board, card); return;
        case 5: listPreviousUsers(user, board, card); return;
        case 6: transferCard(user, board, card); return;
        case 7: decideJoinOrLeave(user, board, card); return;
        case 0: boardMenu(user, board); return;
        default: boardMenu(user, board); return;
    }
}