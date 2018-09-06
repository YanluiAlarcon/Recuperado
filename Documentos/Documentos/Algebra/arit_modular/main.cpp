#include <iostream>
#include <math.h>
using namespace std;

int mcd(int m, int n){
    int r = 0;
    r = m % n;
    if(r == 0){
        return 0;
    }
    else {
        return mcd(n,r);
    }
}

void mult(){
    int a, b, c;
    cout << "Ingresa A: "; cin >> a; cout << "Ingresa B: "; cin >> b; cout << "Ingresa C: ";cin >> c;
    cout << "( " << a << " mod " << c << " * " << b << " mod " << c << " ) " << " mod " << c << endl;
    cout << "( " << a%c << " * " << b%c << ")" << " mod " << c << endl;
    cout << (a%c)*(b%c) << " mod " << c << endl;
    cout << (a*b)%c << endl;
}

void inver(){
    int a , b , c;
    cout << "Ingresa A: "; cin >> a; cout << "Ingresa C: ";cin >> c;
    b = 1;
    if ( (a % 2) == 0 and (c % 2) == 0){
        cout <<"No tiene inversa , ya que uno tiene que ser impar";
    }
    else if(mcd(a,c) != 0 ){
        cout <<"No tiene inversa 2";
    }
    else{
        while (((a*b)%c)!=1){
            cout<< a << " * " << b << " = " << a*b << " -> " << ((a*b)%c) << " mod " << c << endl;
            ++b;
        }
        cout<< a << " * " << b << " = " << a*b << " -> " << ((a*b)%c) << " mod " << c << endl;
    }
    cout << b << " mod " << c << endl;
}

int listBin[]={};
int listexp[]={};

int* bin(int dec){
    int i = 0 , k = 0;
    while(dec > 1){
        listBin[i] = dec % 2;
        dec /= 2 ;
        ++i;
    }
    listBin[i] = dec;
    for(int j= 0 ; j <= i ; j++){
        if (listBin[j] == 1){
            listexp[k] = pow(2,j);
            k++;
        }
    }
    return listexp;
}

void listEx(int a ,int list[],int c){
    for(int i = 0 ; i <= 7 ; i++)
        cout << list[i] << " ";
    cout << endl;
    long count = 1 , mod = 0,j = 0 , res = 1;
    mod = pow(a,list[0]);
    mod = mod % c;
    for(int i = 0 ; i < 7 ; i++){
        count = ((mod*mod) % c);
        mod = count;
        cout << mod << " ";
        if(list[j] == pow(2,i)){
            res *= 6*mod;
            j++;
        }
    }
    cout << res << "mod" << c << endl;
}

void exp1(){
    int a , b, c;
    cout << "Ingresa A: "; cin >> a; cout << "Ingresa B: "; cin >> b; cout << "Ingresa C: ";cin >> c;
    listEx(a,bin(b),c);
}

int main()
{
    cout << "Multiplicacion" << endl; mult();
    cout << "Inversa" << endl; inver();
    cout << "Exponenciacion" << endl;
    exp1();
}
