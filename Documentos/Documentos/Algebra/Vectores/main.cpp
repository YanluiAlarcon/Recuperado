#include <iostream>
#include <math.h>

using namespace std;

float matrix[3][1] = {1,2,3}; float matrix2[1][3] = {-1,3,2}; float matrix3[1][3] = {5,6,7};

float w1[3][1] = {1,2,3}; float w2[3][1]; float w3[3][1];

void suma(){
    for(int i = 0 ; i < 3 ; i++){
        cout << w1[0][i] <<"\t";
    }
    cout <<"\n";
    float sum = 0 , m = 0;
    for(int i = 0 ; i < 3 ; i++){
        sum += matrix2[0][i]* w1[0][i];
    }
    for(int i = 0 ; i < 3 ; i++){
        m += pow(2,w1[0][i]);
    }
    float res = (sum/m);
    for(int i = 0 ; i < 3 ; i++){
        w2[0][i] = (w1[0][i]) * res;
    }
    for(int i = 0 ; i < 3 ; i++){
        w2[0][i] = matrix2[0][i]- w2[0][i];
    }
    for(int i = 0 ; i < 3 ; i++){
        //cout << w2[0][i] <<"\t\n";
        printf("%.2f",w2[0][i]);
        cout << "\t";
    }
    cout << "\n";

    float sum2 = 0 , m2 = 0;
    for(int i = 0 ; i < 3 ; i++){
        sum2 += matrix3[0][i]* w2[0][i];
    }
    for(int i = 0 ; i < 3 ; i++){
        m2 += pow(2,w2[0][i]);
    }
    float res2 = float(sum2)/float(m2)
            ;
    for(int i = 0 ; i < 3 ; i++){
        w3[0][i] = w1[0][i]*res - w1[0][i]*res2 ;
    }
    for(int i = 0 ; i < 3 ; i++){
        w3[0][i] = matrix3[0][i]- w3[0][i];
    }
    for(int i = 0 ; i < 3 ; i++){
        printf("%.2f",w3[0][i]);
        cout << "\t";
    }
    cout << endl;
}

int main()
{
    suma();
    return 0;
}
