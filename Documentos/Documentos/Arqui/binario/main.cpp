#include <iostream>
#include <math.h>
#include "binario.h"

using namespace std;
void ver(int a[],int tam){
    for(int i = 0; i < tam; i++){
        cout << a[i];
    }
    cout << endl;
}
int main(){
    int a ,b, c;
    cout << "Ingrese el tamañno del bit: "; cin >> a;
    cout << "Numero Binario 1: "; cin >> b;
    cout<< "Numero Binario 2: "; cin >> c;
    binario M(a);
    ver(M.addBin(b,c));
    ver(M.subtractBin(b,c));
    ver(M.multiply(b,c));
    ver(M.multiplySing(b,c));
    ver(M.split(b,c));
    return 0;
}
