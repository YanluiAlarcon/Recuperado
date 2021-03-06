//
// Created by yanlui on 11/19/2015.
//
/*
#ifndef GAMES_REVERSI_H
#define GAMES_REVERSI_H

class mat;

class Reversi {
public:
    Reversi();
    void create_mat();
    void print(int []);


private:
    int mat[][]= 0 ;
    int row, colum;
};


#endif //GAMES_RESERSI_H

*/

#ifndef REVERSI_H
#define REVERSI_H
#include "../GridGame.h"

const int REVERSI_BOARD_SIZE = 8;

class Reversi: public GridGame {
public:
    /*
     * Move as many of these member functions as REASONABLE up
     * into common parent class
     */
    Reversi();

    Reversi(const char *playerSymbols);

    void OutputGreeting() const;

    /* Returns NULL on good move, else returns err string.
     * Note that this check is game-neutral (at least for TTT and Reversi)
     */
    char GetPlayerSymbol(int player) const;

    int GetBoardSize() const;

    const char *IsLegalMove(int player, int row, int col) const;

    void OutputBoard() const;

    void DoBasicMove(int player, int row, int col);

    bool IsDone() const;

    void DoMove(int player, int row, int col);

    void OutputResults() const;

protected:
    int m_boardSize;
    const char *m_playerSymbols;
    char **m_board;
    int boardSize;

    static bool InBounds(int row, int col, int boardSize);

    void FlipTilesInDir(char playerSym, int row, int rowIncr,
                        int col, int colIncr);
};

#endif //REVERSI_H