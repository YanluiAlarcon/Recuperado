//
// Created by yanlu on 12/3/2015.
//

#include <iostream>
#include <cstdlib>
#include <cstring>
#include "GridGame.h"

using namespace std;


GridGame::GridGame() {
    m_type = GAME_UNKNOWN;
    m_gameName = "Unknown";
}

GridGame::GridGame(enum GameType type, const char *gameName) {
    m_type = type;
    m_gameName = gameName;
}