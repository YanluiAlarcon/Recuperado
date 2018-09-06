#include <iostream>

using namespace std;

int main()
{
    cout << "\t\tECUANCION DIOFANTICA" << endl;
    int a , b , c , d , e , r , q , U0 = 0 , U1 = 1, V1 = 1, V0 = 0 ;
    int listR[100]={} , listQ[100]={};
    int listU[100]={} , listV[100]={};
    int i = 0;
    cout << "Ingrese el primer factor: "; cin >> a; cout <<"Ingrese el segundo factor: "; cin >> b;cout << "Ingrese el resultante: "; cin >> c;
    cout << "La ecuacion es: " << a <<"x " << "+ " << b << "y = " << c << endl;
    d = a, e = b;
    if(a and b == 0)
        cout << "Valores incorrectos."<<endl;
    while (r != 0){
        q = a/b;
        r = (-1)*((b*q)- a);
        //cout << a << " = " << b << "." << q << " + " << r << endl;;
        listQ[i] = q;
        listR[i] = r;
        a = b;
        b = r;
        i++;
    }
    //cout << "El M.C.D. es : " << a << endl;
    listU[0] = 1; listU[1] = 0;
    listV[0] = 0; listV[1] = 1;
    for (int j = 0; j < i - 1; ++j ){
        listU[j+2]= U1 - listQ[j]*U0;
        U1 = listU[j+1];
        U0 = listU[j+2];
    }
    for (int j = 0; j < i - 1; ++j ){
        listV[j+2]= V0 - listQ[j]*V1;
        V0 = listV[j+1];
        V1 = listV[j+2];
    }
    // cout << d << "*(" << listU[i] << ") + " << e << "*(" << listV[i] << ") = " << a<< endl;
    int X0 , Y0 ;
    X0 = (c/a)*listU[i];
    Y0 = (c/a)*listV[i];
    cout << "X = " << X0 << " + "<< e/a << "t" << endl;
    cout << "y = " << Y0 << " - "<< d/a << "t" << endl;
}
