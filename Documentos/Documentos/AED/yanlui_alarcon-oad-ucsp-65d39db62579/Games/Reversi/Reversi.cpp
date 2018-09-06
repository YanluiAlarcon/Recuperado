#include "Reversi.h"
#include <iostream>

using namespace std;

Reversi::Reversi(){
    pInt = new int*[8];
    for (int i = 0; i < 8; i++){
        pInt[i] = new int[8];
        for(int j = 0; j < 8; j++){
            pInt[i][j] = false;
        }
    }
}

Reversi::~Reversi(){
    for (int i = 0; i < 8; i++)
        delete pInt[i];
    delete pInt;
}

void Reversi::display()
{
    for(int i = 0 ; i < 8; ++i){
        cout << endl;
        for(int j = 0 ; j < 8 ; ++j){
            cout << pInt[i][j] << " ";
        }
        cout << endl;
    }
}
