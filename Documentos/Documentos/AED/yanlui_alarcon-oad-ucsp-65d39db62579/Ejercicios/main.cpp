#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Rand.h"

using namespace std;

void dice(int index)
{
    Rand altr(6, index);
    cout << altr(6,index);
}

void shuffle(int *pInt , int size, int index)
{
    int i , temp = index , size_temp = size;
    Rand altr(size,temp);
    int qInt[size];
    for (i = 0 ; i < size ; ++i )
    {
        temp = altr(size_temp - i , temp);
        qInt[i] = pInt[temp];
        for(int j = 0 ; j < size - temp - 1 ; ++j)
        {
            pInt[temp + j] = pInt[temp+j+1];
        }
    }

    for (i = 0; i < size ; ++i) {
        cout << qInt[i] << " ";
    }
}


void bingo(int *pInt , int size, int index)
{
    int i , temp = index , size_temp = size;
    Rand altr(size,temp);
    int qInt[size];
    for (i = 0 ; i < size ; ++i )
    {
        temp = altr(size_temp - i , temp);
        qInt[i] = pInt[temp];
        for(int j = 0 ; j < size - temp - 1 ; ++j)
        {
            pInt[temp + j] = pInt[temp+j+1];
        }
    }

    int A[5];
    int temp1 = 6;
    Rand altr1(15,temp1);
    for (int i = 0; i < 6 ; ++i) {
        temp1 =  altr(15 - i+1 , temp1);
        A[i] = qInt[temp1];
    }
    for (int i = 0; i < 5 ; ++i) {
        cout << A[i] << '\t';
    }
}


int main()
{
    cout << "Hello world!" << endl;
    /*
    // #### NUMERO ALEATORIO #####
    Rand altr(9,3);
    altr(9,3);

    Rand altr(100);
    altr(500);
    */

    /*
    // ##### DADO #####
    Rand altr(7,6);
    cout << altr(7,6);
    dice(7);
    */

    /*
    // #### LISTA DESORDENADA #####
    int lista[6] = {9,5,2,7,1,0};
    shuffle(lista,6,4);
    */

    /*
    // ##### CARTAS BARAJAR ####
    int lista[52]={};
    int i , j , k = 0;
    for(i = 0 ; i < 4 ; ++i )
    {
        for (j = 0; j < 13; ++j)
        {
            lista[k] = j + 1;
            ++k;
        }
    }
    shuffle(lista,52,54);
    */

    /*
    // #####  BINGO ####
    int lista1[15];
    int lista2[15];
    int lista3[15];
    int lista4[15];
    int lista5[15];
    int val = 0;
    for (int j = 0; j < 15; ++j)
    {
        lista1[j] = val + 1;
        val++;
    }
    for (int j = 0; j < 15; ++j)
    {
        lista2[j] = val + 1;
        val++;
    }
    for (int j = 0; j < 15; ++j)
    {
        lista3[j] = val + 1;
        val++;
    }
    for (int j = 0; j < 15; ++j)
    {
        lista4[j] = val + 1;
        val++;
    }
    for (int j = 0; j < 15; ++j)
    {
        lista5[j] = val + 1;
        val++;
    }

    char a[5] = {'B','I','N','G','O'};
    cout << a[0] << '\t' <<a[1]<<'\t' <<a[2]<<'\t' <<a[3] <<'\t' <<a[4]<<endl;

    bingo(lista1,15,48);cout << endl;
    bingo(lista2,15,35);cout << endl;
    bingo(lista3,15,135);cout << endl;
    bingo(lista4,15,38);cout << endl;
    bingo(lista5,15,13);cout << endl;
    /*
    bingo(lista1,15,6);cout << endl;
    bingo(lista2,15,2);cout << endl;
    bingo(lista3,15,8);cout << endl;
    bingo(lista4,15,28);cout << endl;
    bingo(lista5,15,103);cout << endl;
    */
    return 0;
}

