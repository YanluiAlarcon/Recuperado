#include "binario.h"
#include <iostream>
#include <math.h>

using namespace std;

binario::binario(const binario&){

}

binario::binario(int a){
    tam = a;
    listBin1[a]={}, listBin2[a]={};
    for(int i = 0 ; i < a ; ++i){
        listBin1[i]= 0;
        listBin2[i]= 0;
    }
}

int* binario::decToBin(int dec){
    if (dec < 1){
        dec = (-1)*dec;
        listBin1[0] = 1;
    }
    int i = 1;
    while(dec > 1){
        listBin1[tam-i] = dec % 2;
        dec /= 2 ;
        ++i;
    }
    listBin1[tam-i] = dec;
    return listBin1;
}

int* binario::copy(int bin){
    int i = tam - 1;
    while(bin >= 1){
        listBin1[i]= bin % 10;
        bin /= 10 ;
        i--;
    }
    return listBin1;
}

int* binario::copy2(int bin){
    int i = tam - 1;
    while(bin >= 1){
        listBin2[i]= bin % 10;
        bin /= 10 ;
        i--;
    }
    return listBin2;
}

int binario::binToDec(int bin){
    int count = 0 , i = 0;
    if (pow(10,tam-1) > bin){
        while(bin >= 1){
            if( (bin % 10) == 1)
                count += pow(2,i);
            bin /= 10 ;
            ++i;
        }
        if (bin == 1)
            count += (-1)*(pow(2,i));
    }
    else{
        while(bin > 1){
            if( (bin % 10) == 1)
                count += pow(2,i);
            bin /= 10 ;
            ++i;
        }
        if (bin == 1)
            count += (-1)*(pow(2,i));
    }
    return count;
}

int* binario::bitwise(int bin[]){
    for(int i = 0 ; i < tam ; i++){
        if (bin[i] == 0)
            bin[i] = 1;
        else
            bin[i] = 0;
    }
    return bin;
}

int* binario::changeSing(int listBin[]){
    int carry = 1;
    listBin1[tam]={};
    for(int i = tam-1; i >= 0 ; i--){
        if((listBin[i] + carry) == 0){
            listBin1[i] = 0;
            carry = 0;
        }
        else if((listBin[i] + carry) == 1){
            listBin1[i] = 1;
            carry = 0;
        }
        else if((listBin[i] + carry) == 2){
            listBin1[i] = 0;
            carry = 1;
        }
    }
    return listBin1;
}

int* binario::addBin(int a, int b){
    copy(a);
    int listBin3[tam];
    for(int i = 0 ; i< tam ; i++)
        listBin3[i] = listBin1[i];
    copy2(b);
    int listBin4[tam];
    for(int i = 0 ; i< tam ; i++)
        listBin4[i] = listBin2[i];
    for(int i = 0 ; i< tam ; i++)
        listBinRes[i] = 0;
    int carry = 0;
    for(int i = tam-1 ; i >= 0; i--)
    {
        if(listBin3[i] + listBin4[i] + carry == 0){
            cout <<"Caso 1 " << listBin3[i] << " " << listBin4[i]<<endl;
            listBinRes[i] = 0;
            carry = 0;
        }
        else if(listBin3[i] + listBin4[i] + carry == 1){
            cout << "Caso 2 " << listBin3[i] << " " << listBin4[i]<<endl;
            listBinRes[i] = 1;
            carry = 0;
        }
        else if(listBin3[i] + listBin4[i] + carry == 2){
            cout << "Caso 3 " << listBin3[i] << " " << listBin4[i]<<endl;
            listBinRes[i] = 0;
            carry = 1;
        }
        else if(listBin3[i] + listBin4[i] + carry > 2){
            cout << "Caso 4 " << listBin3[i] << " " << listBin4[i]<<endl;
            listBinRes[i] = 1;
            carry = 1;
        }
    }
    for(int i = 0; i < tam; i++){
        cout << listBinRes[i];
    }
    cout << endl;
    return listBinRes;
}

int* binario::subtractBin(int a, int b){
    copy(a);
    int listBin3[tam];
    for(int i = 0 ; i< tam ; i++)
        listBin3[i] = listBin1[i];
    changeSing(bitwise(copy(b)));
    int listBin4[tam];
    for(int i = 0 ; i< tam ; i++)
        listBin4[i] = listBin1[i];
    int listBinRes[tam]={};
    int carry = 0;
    for(int i = tam-1 ; i >= 0; i--)
    {
        if(listBin3[i] + listBin4[i] + carry == 0){
            listBinRes[i] = 0;
            carry = 0;
        }
        else if(listBin3[i] + listBin4[i] + carry == 1){
            listBinRes[i] = 1;
            carry = 0;
        }
        else if(listBin3[i] + listBin4[i] + carry == 2){
            listBinRes[i] = 0;
            carry = 1;
        }
        else if(listBin3[i] + listBin4[i] + carry > 2){
            listBinRes[i] = 1;
            carry = 1;
        }
    }
    for(int i = 0; i < tam; i++){
        cout << listBinRes[i];
    }
    cout << endl;
    return listBinRes;
}

int* binario::multiply(int a, int b){
    decToBin(a);
    int listQ[tam]={};
    for(int i = 0 ; i< tam ; i++)
        listQ[i] = listBin1[i];
    decToBin(b);
    int listM[tam]={};
    for(int i = 0 ; i< tam ; i++)
        listM[i] = listBin1[i];
    int listBinRes[2*tam]={}, listA[tam]={}, temp[tam]={};
    for(int i = 0 ; i < 2*tam ; i++){
        listBinRes[i] = 0;
    }
    int j = tam-1 , carry = 0;
    for(int i = 0 ; i < tam ; i++){
        if(listA[j] != 0){
            for(int i = tam-1 ; i >= 0; i--)
            {
                if(listA[i] + listM[i] + carry == 0){
                    temp[i] = 0;
                    carry = 0;
                }
                else if(listA[i] + listM[i] + carry == 1){
                    temp[i] = 1;
                    carry = 0;
                }
                else if(listA[i] + listM[i] + carry == 2){
                    temp[i] = 0;
                    carry = 1;
                }
                else if(listA[i] + listM[i] + carry > 2){
                    temp[i] = 1;
                    carry = 1;
                }
            }
            listA[0] = carry;
            for(int i = 1 ; i <= tam ; i++)
                listA[i] = temp[i-1];
            listQ[0] = temp[i];
            for(int i = 1 ; i <= tam ; i++)
                listQ[i] = listQ[i-1];
            for(int i = 0; i < tam; i++)
                cout << temp[i];
        }
        else{
            for(int i = 1 ; i <= tam ; i++)
                listA[i] = listA[i-1];
            listQ[0] = listA[i];
            for(int i = 1 ; i <= tam ; i++)
                listQ[i] = listQ[i-1];
        }
    }
    int val=0,i;
    for(i = 0 ; i< tam ; i++)
        listBinRes[i] = listA[i];
    val = i;
    for(int i = 0 ; i< tam ; i++)
        listBinRes[val+i] = listQ[i];
    return listBinRes;
}

int* binario::multiplySing(int a, int b){
    decToBin(a);
    int listQ[tam]={};
    for(int i = 0 ; i< tam ; i++)
        listQ[i] = listBin1[i];
    decToBin(b);
    int listM[tam]={};
    for(int i = 0 ; i< tam ; i++)
        listM[i] = listBin1[i];
    int listBinRes[2*tam]={}, listA[tam]={}, temp[tam]={},Q1 = 0;
    for(int i = 0 ; i < 2*tam ; i++){
        listBinRes[i] = 0;
    }
    int j = tam-1 , carry = 0;
    for(int i = 0 ; i < tam ; i++){
        if(listQ[j] == 1 and Q1 == 0){
            changeSing(bitwise(listM));
            for(int i = 0 ; i< tam ; i++)
                listM[i] = listBin1[i];
            for(int i = tam-1 ; i >= 0; i--)
            {
                if(listA[i] + listM[i] + carry == 0){
                    temp[i] = 0;
                    carry = 0;
                }
                else if(listA[i] + listM[i] + carry == 1){
                    temp[i] = 1;
                    carry = 0;
                }
                else if(listA[i] + listM[i] + carry == 2){
                    temp[i] = 0;
                    carry = 1;
                }
                else if(listA[i] + listM[i] + carry > 2){
                    temp[i] = 1;
                    carry = 1;
                }
            }
            for(int i = 1 ; i <= tam ; i++)
                listA[i] = temp[i-1];
            listQ[0] = temp[i];
            for(int i = 1 ; i <= tam ; i++)
                listQ[i] = listQ[i-1];
            Q1=listQ[i];
            for(int i = 0; i < tam; i++)
                cout << temp[i];
        }
        else if(listQ[j] == 0 and Q1 == 1){
            for(int i = tam-1 ; i >= 0; i--)
            {
                if(listA[i] + listM[i] + carry == 0){

                    temp[i] = 0;
                    carry = 0;
                }
                else if(listA[i] + listM[i] + carry == 1){
                    temp[i] = 1;
                    carry = 0;
                }
                else if(listA[i] + listM[i] + carry == 2){
                    temp[i] = 0;
                    carry = 1;
                }
                else if(listA[i] + listM[i] + carry > 2){
                    temp[i] = 1;
                    carry = 1;
                }
            }
            for(int i = 1 ; i <= tam ; i++)
                listA[i] = temp[i-1];
            listQ[0] = temp[i];
            for(int i = 1 ; i <= tam ; i++)
                listQ[i] = listQ[i-1];
            Q1=listQ[i];
            for(int i = 0; i < tam; i++)
                cout << temp[i];
        }
        else if(listQ[j] == Q1){
            for(int i = 1 ; i <= tam ; i++)
                listA[i] = listA[i-1];
            listQ[0] = listA[i];
            for(int i = 1 ; i <= tam ; i++)
                listQ[i] = listQ[i-1];
            Q1=listQ[i];
        }
    }
    int val=0,i;
    for(i = 0 ; i< tam ; i++)
        listBinRes[i] = listA[i];
    val = i;
    for(int i = 0 ; i< tam ; i++)
        listBinRes[val+i] = listQ[i];
    return listBinRes;
}

int* binario::split(int a, int b){
    decToBin(a);
    int listQ[tam]={};
    for(int i = 0 ; i< tam ; i++)
        listQ[i] = listBin1[i];
    decToBin(b);
    int listM[tam]={};
    for(int i = 0 ; i< tam ; i++)
        listM[i] = listBin1[i];
    int listBinRes[2*tam]={}, listA[tam]={}, temp[tam]={},Q1 = 0,i;
    for(int k = 0 ; k < tam ; k++){
        for(i = 0 ; i < tam ; i++)
            listA[i] = listA[i+1];
        listA[i] = listQ[0];
        for(int i = 0 ; i < tam ; i++)
            listQ[i] = listQ[i+1];
        int *inver[tam] = bitwise(listM);
        int listBinRes[tam]={};
        int carry = 0;
        for(int i = tam-1 ; i >= 0; i--)
        {
            if(listA[i] + inver[i] + carry == 0){
                listBinRes[i] = 0;
                carry = 0;
            }
            else if(listA[i] + inver[i] + carry == 1){
                listBinRes[i] = 1;
                carry = 0;
            }
            else if(listA[i] + inver[i] + carry == 2){
                listBinRes[i] = 0;
                carry = 1;
            }
            else if(listA[i] + inver[i] + carry > 2){
                listBinRes[i] = 1;
                carry = 1;
            }
        }
        changeSing(listBinRes);
        int count = 0 , j = 0;
        for(int i = tam-1; i < tam; i--){
            if(listBin1[i] == 1)
                count += pow(2,j);
            j++;
        }
        if(count > 0)
            listQ[tam-1] = 1;
        else{
            listQ[tam-1] = 0;
            for(int i = tam-1 ; i >= 0; i--){
                if(listBin1[i] + listM[i] + carry == 0){
                    listA[i] = 0;
                    carry = 0;
                }
                else if(listA[i] + listM[i] + carry == 1){
                    listA[i] = 1;
                    carry = 0;
                }
                else if(listA[i] + listM[i] + carry == 2){
                    listA[i] = 0;
                    carry = 1;
                }
                else if(listA[i] + listM[i] + carry > 2){
                    listA[i] = 1;
                    carry = 1;
                }
            }
        }
    }
}
