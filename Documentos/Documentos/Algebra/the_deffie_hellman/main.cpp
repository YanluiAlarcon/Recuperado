#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int a=0, i, p = 47, g = 12 , PrivA, PrivB , PubA, PubB, ZZ1, ZZ2;
    p = 1 + rand()%50;
    cout << p << '\n';
    for(i = 1 ; i < (p+1) ; i++){
        if(p % i == 0)
            a++;
    }
    if(a != 2)
      cout << "No es Primo" << '\n';
    else{
        cout << "Si es Primo" << '\n';
        g = 1 + rand()%50;
        if (g < (p-1)){
            cout << "Si es menor" << '\n';
            PrivA = 1 + rand()%10;
            PrivB = 1 + rand()%10;
            PubA = pow(g,PrivA);
            PubA %= p;
            PubB = pow(g,PrivB);
            PubB %= p;
            ZZ1 = pow(PubB,PrivA);
            ZZ1 %= p;
            ZZ2 = pow(PubA,PrivB);
            ZZ2 %= p;
            cout << ZZ1 << " "<< ZZ2<< endl;
        }
        else
            cout<< "No es menor" << '\n';

    }
    return 0;
}
