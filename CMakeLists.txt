cmake_minimum_required(VERSION 3.17)
project(project_01 C)

set(CMAKE_C_STANDARD 11)

add_executable(project_01 main.c main.h menu/register_menu.c menu/register_menu.h model/user.c model/user.h util/file.c util/file.h menu/login_menu.c menu/login_menu.h model/board.c model/board.h model/card.c model/card.h db/user_db.c db/user_db.h util/types.h db/board_db.c db/board_db.h menu/user_menu.c menu/user_menu.h container/id_array.c container/id_array.h db/global_db.c db/global_db.h util/utils.c util/utils.h menu/board_menu.c menu/board_menu.h container/user_search.c container/user_search.h container/card_array.c container/card_array.h menu/card_menu.c menu/card_menu.h)