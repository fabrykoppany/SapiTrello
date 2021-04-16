//
// Created by User on 2021/04/13.
//

#include "board_menu.h"

void renameBoard(USER *user, BOARD *board) {
    char *title = (char *) malloc(255 * sizeof(char));

    if (title == NULL) {
        printf("Error allocating memory!\n");
        return;
    }

    clearScreen();

    printf("Your board is currently called:\n%s\n", board->name);
    printf("What would you like to call your board?\n");
    printf("(to leave unchanged, type \"exit\")\n");
    scanf(" %[^\n]", title);

    if (strcasecmp(title, "exit") == 0) {
        // The user would like to exit this menu.
        free(title);
        boardMenu(user, board);
        return;
    }

    title = reallocateBuffer(title);

    if (!changeBoardName(board, title)) {
        // We failed to change the board name!
        printf("Could not change board name!\n");
        getch();
        return;
    }

    boardMenu(user, board);
}

void printBoardUsers(BOARD *board) {
    // Print all users from the board.
    for (size_t i = 0; i < board->users.count; ++i) {
        USER *user = loadUserById(board->users.ids[i]);

        if (user != NULL) {
            printf("%llu. ", i + 1);
            printShortUser(user);
            printf("\n");
            freeUser(user);
        }
    }
}

void printSoughtUsers(IdEntry *head, id_t startIndex) {
    // Walk through the entire linked list and print all users.
    IdEntry *p = head;
    id_t id = startIndex;

    while (p != NULL) {
        USER *user = loadUserById(p->id);

        if (user != NULL) {
            printf("%u. ", id++);
            printShortUser(user);
            printf("\n");
            freeUser(user);
        }

        p = p->next;
    }
}

void boardUsers(USER *user, BOARD *board) {
    clearScreen();

    printf("=====================\n");
    printf("BOARD USER MANAGEMENT\n");;
    printf("=====================\n");
    printf("-- %s -- \n\n", board->name);

    printf("Users currently contributing to board:\n");
    printBoardUsers(board);

    printf("\nPress any key to go back...\n");
    getch();
    boardMenu(user, board);
}

void kickUser(USER *user, BOARD *board) {
    clearScreen();

    printf("=====================\n");
    printf("BOARD USER MANAGEMENT\n");;
    printf("=====================\n");
    printf("-- %s -- \n\n", board->name);

    printf("Which user would you like to kick from this board?\n\n");
    printf("Users currently contributing to board:\n");
    printBoardUsers(board);
    printf("0. None, head back\n");

    int choice;
    scanf("%d", &choice);

    if (choice == 0 || choice > board->users.count) {
        boardMenu(user, board);
        return;
    }

    USER *boardUser = loadUserById(board->users.ids[choice - 1]);

    if (boardUser == NULL) {
        printf("Could not load the requested user!\n");
        getch();
    } else if (!removeUserFromBoard(boardUser, board) || !removeBoardFromUser(boardUser, board)) {
        printf("Could not remove the requested user from the board.\n");
        getch();
    }

    if (isSameUser(user, boardUser)) {
        // If we've kicked ourselves...
        listBoards(user);
        return;
    }

    // Bring the user back to the kick menu
    kickUser(user, board);
}

void inviteUser(USER *user, BOARD *board) {
    clearScreen();

    printf("=====================\n");
    printf("BOARD USER MANAGEMENT\n");;
    printf("=====================\n");
    printf("-- %s -- \n\n", board->name);

    IdEntry *availableUsers = searchForUsersNotInBoard(board);

    if (availableUsers == NULL) {
        printf("There are no more users available to add to this board.\n");
        printf("Press any key to continue...\n");
        getch();
        boardMenu(user, board);
        return;
    }

    printf("Which user would you like to add to this board?\n");
    printf("Users not currently contributing to board:\n");

    // Print all users that are not in the board currently!
    printSoughtUsers(availableUsers, 1);

    printf("0. None, head back\n");

    int choice;
    scanf("%d", &choice);

    if (choice == 0) {
        freeIdEntryList(availableUsers);
        boardMenu(user, board);
        return;
    }

    id_t userId = getIdFromList(availableUsers, choice - 1);
    freeIdEntryList(availableUsers);

    if (userId == INVALID_ID) {
        boardMenu(user, board);
        return;
    }

    USER *boardUser = loadUserById(userId);

    if (boardUser == NULL) {
        // We couldn't load the user for some reason.
        printf("Could not load the requested user!\n");
        getch();
        boardMenu(user, board);
    } else if (!addUserToBoard(boardUser, board) || !addBoardToUser(boardUser, board)) {
        // We couldn't remove the user from the board for some reason.
        printf("Could not remove the requested user from the board.\n");
        getch();
        boardMenu(user, board);
    }

    // Bring the user back to the invite menu
    inviteUser(user, board);
}

void leaveBoard(USER *user, BOARD *board) {
    clearScreen();

    printf("*** WARNING!!! ***\n");
    printf("You are about to leave the following board:\n");
    printf("- %s\n", board->name);
    printf("\nThis may be a permanent decision.\nAre you sure you want to leave this board?\n\n");
    printf("|->1. Yes, leave the board\n");
    printf("|->0. No, head back\n");

    int choice;
    scanf("%d", &choice);

    if (choice != 1) {
        boardMenu(user, board);
        return;
    }

    // Attempt to remove the user from the board and vice versa.
    if (!removeUserFromBoard(user, board) || !removeBoardFromUser(user, board)) {
        printf("Could not leave board!\n");
        getch();
    }

    listBoards(user);
}

void boardMenu(USER *user, BOARD *board) {
    clearScreen();

    printf("=====\n");
    printf("BOARD\n");;
    printf("=====\n");
    printf("-- %s -- \n\n", board->name);

    printf("+-------------+\n");
    printf("Card Management\n");
    printf("+-------------+\n");
    printf("|->1. Browse all cards\n");
    printf("|->2. Browse TO DO cards\n");
    printf("|->3. Browse IN PROGRESS cards\n");
    printf("|->4. Browse COMPLETE cards\n");
    printf("|->5. Create new card\n");
    printf("\n");

    printf("+-------------+\n");
    printf("User Management\n");
    printf("+-------------+\n");
    printf("|->6. List users\n");
    printf("|->7. Rename board\n");
    printf("|->8. Invite new user\n");
    printf("|->9. Kick user from board\n");
    printf("|->10. Leave board indefinitely\n\n");
    printf("|->0. Back to board list\n");

    int choice;
    scanf("%i", &choice);

    switch (choice) {
        case 1: browseCards(user, board); return;
        case 2: browseCardsWithState(user, board, TO_DO); return;
        case 3: browseCardsWithState(user, board, DOING); return;
        case 4: browseCardsWithState(user, board, DONE); return;
        case 5: createCard(user, board); return;
        case 6: boardUsers(user, board); return;
        case 7: renameBoard(user, board); return;
        case 8: inviteUser(user, board); return;
        case 9: kickUser(user, board); return;
        case 10: leaveBoard(user, board); return;
        case 0: listBoards(user); return;
        default: printf("|->ERROR: Your choice didn't match any command. Please try again."); getch(); boardMenu(user, board); return;
    }
}