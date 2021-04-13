//
// Created by User on 2021/04/13.
//

#ifndef PROJECT_01_BOARD_DB_H
#define PROJECT_01_BOARD_DB_H

#include "board.h"
#include "file.h"
#include "id_array.h"

char *getBoardFilename(id_t id);
bool boardExists(id_t id);
bool saveBoard(BOARD *board);
BOARD *loadBoard(id_t id);

#endif //PROJECT_01_BOARD_DB_H
