#include <iostream>

using namespace std;

int main()
{
    cout << "\t\t\tEUCLIDES EXTENDIDO" << endl;
    int a , b , r , q, c , d , U0 = 0 , U1 = 1, V1 = 1, V0 = 0 ;
    int listR[100]={} , listQ[100]={};
    int listU[100]={} , listV[100]={};
    int i = 0;
    cout << "Ingrese el primer factor: "; cin >> a; cout <<"Ingrese el segundo factor: "; cin >> b;
    c = a, d = b;
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
    cout << "|\t"<< " " <<"\t|" << "\t"<< " " <<"\t|";
    for (int j = 0; j < i - 1; ++j){
        cout <<"\t" << listQ[j]<< "\t|";
    }
    cout << endl<<"|";
    for (int j = 0; j < i + 1; ++j){
        cout <<"\t" << listU[j]<< "\t|";
    }
    cout << endl<<"|";
    for (int j = 0; j < i + 1; ++j){
        cout <<"\t" << listV[j]<< "\t|";
    }
    cout << endl << "|\t"<< c <<"\t|" << "\t"<< d <<"\t|";
    for (int j = 0; j < i - 1; ++j){
        cout <<"\t" << listR[j]<< "\t|";
    }

}
