#include <iostream>

using namespace std;

int main()
{
    cout << "\t\tECUCLIDES" << endl;
    int a , b , r , q ;
    int i=0;
    cout << "Ingrese el primer factor: "; cin >> a; cout <<"Ingrese el segundo factor: "; cin >> b;
    while (r != 0){
        q = a/b;
        r = -1*((b*q)- a);
        //cout << a << " = " << b << "." << q << " + " << r << endl;;
        a = b;
        b = r;
        i++;
    }
    cout << "El M.C.D. es: " << a << endl;
}
