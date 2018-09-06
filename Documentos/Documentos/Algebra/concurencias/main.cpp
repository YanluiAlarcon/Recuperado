#include <iostream>

using namespace std;


int invert(int a, int b){
    //cout << "\t\t\tEUCLIDES EXTENDIDO" << endl;
    int r , q, c , d , U0 = 0 , U1 = 1, V1 = 1, V0 = 0 ;
    int listR[100]={} , listQ[100]={};
    int listU[100]={} , listV[100]={};
    int i = 0;
    //cout << "Ingrese el primer factor: "; cin >> a; cout <<"Ingrese el segundo factor: "; cin >> b;
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
    /*cout << "|\t"<< " " <<"\t|" << "\t"<< " " <<"\t|";
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
    }*/
    int res;
    if(listU[i] < 0){
        res = listU[i] + d;
        return res;
    }
    return listU[i];
}

void congruencia(int a, int b, int c , int inv){
    cout << a << "x = " << b << "mod "<< c <<endl;
    //cout << inv << " es la inversa de "<< a <<endl;
    cout /*<< inv << " * "*/ << a << "x = " << inv << " * " << b << "mod " << c << endl;
    int res = 0 ,  res2 = 0;
    res = (a*inv) % c;
    res2 = (b*inv) % c;
    //cout << res << endl;
    //cout << res2 << endl;
    //cout << ((-1)*(b*inv)) % c << " x = " << ((-1)*(a*inv))%c << " mod " << c <<endl;
    /*for(int x = 0 ; x < 8; x++){
        cout << res << " ";
        res += c ;
    }
    for(int x = 0 ; x < 8; x++){
        cout << res2 << " ";
        res2 -= c ;
    }*/
}


int main()
{
    int a , b, c , d , e , f , h , i ,mul , M1 , M2, M3, M4, Y1 , Y2 , Y3 , Y4;
    cin >> a >> b >> c >> d >> e >> f >> h >> i;
    mul = b * d * f *i;
    M1 = mul/b ;
    M2 = mul/d ;
    M3 = mul/f ;
    M4 = mul/h ;
    Y1 = invert(M1,b);
    Y2 = invert(M2,d);
    Y3 = invert(M3,f);
    Y4 = invert(M3,f);
    congruencia(M1,1,b,Y1);
    congruencia(M2,1,d,Y2);
    congruencia(M3,1,f,Y3);
    congruencia(M4,1,f,Y4);

    int res = M1* a * Y1 + M2 * c * Y2 + M3 * e * Y3 + M4 * h *Y4;
    cout << res << " = "<< res % mul << " ( mod " << mul << " )"<< endl;
    return 0;
}
