cmake_minimum_required(VERSION 3.3)
project(Games)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Reversi/obj/Reversi.cpp Reversi/obj/Reversi.h Reversi/obj/Proj4Aux.cpp Reversi/obj/Proj4Aux.h Reversi/GameType.cpp Reversi/GameType.h Reversi/TicTacToe.cpp Reversi/TicTacToe.h Reversi/GridGame.cpp Reversi/GridGame.h)
add_executable(Games ${SOURCE_FILES} Reversi/obj/Reversi.cpp Reversi/obj/Reversi.h Reversi/obj/Proj4Aux.cpp Reversi/obj/Proj4Aux.h)