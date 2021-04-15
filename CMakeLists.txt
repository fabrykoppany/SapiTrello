cmake_minimum_required(VERSION 3.17)
project(project_01 C)

set(CMAKE_C_STANDARD 11)

add_executable(project_01 main.c main.h register.c register.h user.c user.h file.c file.h login.c login.h board.c board.h card.c card.h user_db.c user_db.h ui.c ui.h types.h board_db.c board_db.h user_menu.c user_menu.h id_array.c id_array.h global_db.c global_db.h utils.c utils.h board_menu.c board_menu.h user_search.c user_search.h)