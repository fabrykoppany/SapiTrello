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

    CARD *card = createNewCard(user->id, title, description);
    addCardToBoard(board, card);
    cardMenu(user, board, card);
}

void changeTitle(char *title, USER *user, BOARD *board, CARD *card){
    free(card->title);
    card->title = title;
    saveBoard(board);
}

void renameCard(USER *user, BOARD *board, CARD *card) {
    // KOPPANY
    char *card_name = (char *) malloc(255 * sizeof(char));

    if (card_name == NULL){
        printf("Error allocating memory!!!\n");
        return;
    }

    printf("What would you like to rename %s card to: ", card->title);
    scanf(" %[^\n]", card_name); card_name = reallocateBuffer(card_name);

    changeTitle(card_name, user, board, card);

    cardMenu(user, board, card);
}

void changeText(char *text, USER *user, BOARD *board, CARD *card){
    free(card->description); card->description = text;

    saveBoard(board);
}

void changeStatus(int status, USER *user, BOARD *board, CARD *card){
    card->state = status;

    saveBoard(board);

    cardMenu(user, board, card);
}

void changeCardStatus(USER *user, BOARD *board, CARD *card) {
    // KOPPANY
    int choice;

    printf("The previous status was: %s\n", getCardProgress(card));

    printf("New status can be: \n");
    for (int i = 0; i < 3; ++i){
        if (i != card->state){
            printf("%i. %s\n", i + 1, cardStateAsString(i));
        }
    }

    printf("Please choose the card's new status: ");
    scanf("%i", &choice); --choice;

    while (choice == card->state){
        printf("This is the card's current state! Please try again: ");
        scanf("%i", &choice);
    }

    cardMenu(user, board, card);
}

void changeDescription(USER *user, BOARD *board, CARD *card) {
    // KOPPANY
    char *card_description = (char *) malloc(2000 * sizeof(char));

    if (card_description == NULL){
        printf("Error allocating memory!!!\n");
        return;
    }

    printf("The previous description was: \n%s\n", card->description);

    printf("New description: ");
    scanf(" %[^\n]", card_description); card_description = reallocateBuffer(card_description);

    changeText(card_description, user, board, card);

    cardMenu(user, board, card);
}

void deleteCard(USER *user, BOARD *board, CARD *card) {
    clearScreen();
    printf("Are you sure you would like to delete this card?\n");
    printf("This decision is IRREVERSIBLE and cannot be changed!\n\n");
    printf("1. Yes, delete this card forever!\n");
    printf("0. No, let me work on it, please.\n");
    printf("Please type in your choice followed by an Enter: ");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        if (!removeCardFromBoard(board, card)) {
            printf("Could not remove board!\n");
            printf("Press any key to continue...");
            getch();
        }

        browseCards(user, board);
        return;
    }

    cardMenu(user, board, card);
}

void printPreviousUsers(CARD *card) {
    for (size_t i = 0; i < card->previousUserIds.count; ++i) {
        USER *user = loadUserById(card->previousUserIds.ids[i]);

        if (user != NULL) {
            printf("%llu. ", i + 1);
            printShortUser(user);
            printf("\n");
            freeUser(user);
        }
    }
}

void listPreviousUsers(USER *user, BOARD *board, CARD *card) {
    clearScreen();
    printf("The following users have helped with this task:\n");

    printPreviousUsers(card);

    printf("\nPress any key to go back...\n");
    getch();
    cardMenu(user, board, card);
}

void transferCard(USER *user, BOARD *board, CARD *card) {
    clearScreen();
    IdEntry *head = searchForDifferentUsers(board, card->userId);

    if (head == NULL) {
        printf("Sorry, but there's nobody you could transfer ownership to.\n");
        printf("\nPress any key to go back...\n");
        getch();
        cardMenu(user, board, card);
        return;
    }

    printf("Which user would you like to transfer this card to?\n\n");

    printSoughtUsers(head, 2);

    printf("1. Nobody. I want this card to be orphaned.\n");
    printf("0. Nobody, I don't want to change anything.\n");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        removeUserFromCard(card);
    } else if (choice != 0) {
        id_t userId = getIdFromList(head, choice - 2);

        if (userId != INVALID_ID) {
            setNewCardUser(card, userId);
            saveBoard(board);
        }
    }

    freeIdEntryList(head);
    cardMenu(user, board, card);
}

void abandonCard(USER *user, BOARD *board, CARD *card) {
    // KOPPANY
    // Ask user if he wants to abandon the card
    // If yes, card->userId = INVALID_ID (that's all)
    int choice;

    printf("Would you like to leave?\n|->1. Yes.\n|->2. No\n.");
    scanf("%i", &choice);

    while (choice != 1 && choice != 2){
        printf("Error! This choice is not possible. Try again: ");
        scanf("%i", &choice);
    }

    if (choice == 1){
        card->userId = INVALID_ID;
        saveBoard(board);
        boardMenu(user, board);
    } else{
        cardMenu(user, board, card);
    }
}

void takeCardOver(USER *user, BOARD *board, CARD *card) {
    printf("Would you like to transfer ownership of this card over to yourself?\n\n");
    printf("1. Yes!\n");
    printf("0. No.\n");
    printf("Please type in your choice followed by an Enter: ");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        setNewCardUser(card, user->id);
        saveBoard(board);
    }

    cardMenu(user, board, card);
}

void decideJoinOrLeave(USER *user, BOARD *board, CARD *card) {
    if (card->userId == user->id) {
        abandonCard(user, board, card);
    } else if (card->userId == INVALID_ID) {
        takeCardOver(user, board, card);
    } else {
        boardMenu(user, board);
    }
}

void cardMenu(USER *user, BOARD *board, CARD *card) {
    clearScreen();

    printf("====\n");
    printf("CARD\n");
    printf("====\n");
    printf("-- %s -- \n", card->title);
    printf("-- %s --\n", getCardProgress(card));
    printf("Owned by: ");
    printCardUser(card);
    printf("\n\n");

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
    } else if (card->userId == INVALID_ID) {
        printf("7. Take card over\n");
    }

    printf("0. Back to board\n");
    printf("Please type in your choice followed by an Enter: ");

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