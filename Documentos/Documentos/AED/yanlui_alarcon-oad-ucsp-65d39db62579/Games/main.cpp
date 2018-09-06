/*#include <iostream>

using namespace std;

int mat(int colum, int fil){
    int lista [8][8] = {};
    for(int i = 0 ; i < colum ; ++i){
        for(int j = 0 ; j < fil ; ++j){
            lista[i][j] = 1;
        }
    }
}

int main() {
    cout << "Hello, World!" << endl;

    for(int i = 0 ; i < 8 ; ++i){
        for(int j = 0 ; j < 8 ; ++j){
            cout << lista[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}*/


#include <iostream>
#include <cstdlib>
#include "Reversi/Reversi.h"
#include "Reversi/GridGame.h"
#include "Reversi/obj/Proj4Aux.h"

using namespace std;


int main(int argc, char *argv[]) {
    GridGame *game;
    Reversi table;

    if ((game = SetupGame(argc, argv)) == NULL) {
        exit(1);
    }

    for (int player = 0; !GameSpecificIsDone(game); player = 1 - player) {
        DoOnePlayer(game, player);

    }
    GameSpecificOutputResults(game);
}