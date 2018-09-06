#include <iostream>
#include <stdlib.h>

using namespace std;

void Burbuja(int *first , int size, int (*compare)(int, int)) {
    int temp;
    for(int i = 0; i < size ; ++i){
        for(int j=0; j < size - 1 ; ++j){
            if(compare(first[j],first[j+1]) > 0){
                temp = first[j];
                first[j] = first[j+1];
                first[j+1] = temp;
            }
        }
    }
}

void Selection(int *first, int size, int (*compare)(int,int)){
    int i,j,t,menor;
    for(i = 0; i < size ; i++){
        for(j = i, menor = i ; j < size ; j++){
            if(compare(first[j] , first[menor]) < 0)
                menor = j;
        }
        t = first[i];
        first[i] = first[menor];
        first[menor] = t;
    }
}

void Insertion(int *first, int size, int (*compare) (int,int)){
    for (int i = 0; i < size - 1; i++){
        int j = i + 1;
        int tmp = first[j];
        if(compare(first[j],first[j-1]) < 0){
            while (j < 0 && tmp > first[j-1]){
                first[j] = first[j-1];
                j--;
            }
        }
        first[j] = tmp;
    }
}

void Cocktail(int *first, int size , int (*compare)(int,int)) {
    int i,j,tmp;
    for (i = 0; i < size/2; i++) {
        bool swapped = false;
        for (j = i; j < size - i - 1; j++) {
            if (compare(first[j],first[j+1]) > 0) {
                tmp = first[j];
                first[j] = first[j+1];
                first[j+1] = tmp;
                swapped = true;
            }
        }
        for (j = size - 2 - i; j > i; j--) {
            if (compare(first[j], first[j-1]) < 0) {
                tmp = first[j];
                first[j] = first[j-1];
                first[j-1] = tmp;
                swapped = true;
            }
        }
        if(!swapped) break;
    }
}

int comp_asc(int A, int B){
    return A-B;
}

int comp_desc(int A, int B){
    return B-A;
}

int comp_asc_abs(int A, int B){
    return abs(A)-abs(B);
}

int comp_desc_abs(int A, int B){
    return abs(B)-abs(A);
}

int main()
{
    int ar[6] = {-3,2,-1,6,4,5};
    int arb[6] = {-3,2,-1,6,-4,5};
    int arc[6] = {-3,2,-1,6,-4,5};
    int ard[6] = {-3,2,-1,6,-4,5};
    int i;

    cout <<endl<<'\t'<<'\t'<< "BUBBLE SORT"<<endl << endl;
    Burbuja(ar, 6,comp_asc);
    Burbuja(arb, 6,comp_desc);
    Burbuja(arc, 6,comp_asc_abs);
    Burbuja(ard, 6,comp_desc_abs);

    for(i=0;i<6;i++)
        cout<<ar[i]<<"\t";
    cout<<endl;

    for(i=0;i<6;i++)
        cout<<arb[i]<<"\t";
    cout<<endl;

    for(i=0;i<6;i++)
        cout<<arc[i]<<"\t";
    cout<<endl;

    for(i=0;i<6;i++)
        cout<<ard[i]<<"\t";
/*
    cout << endl << endl << '\t'<<'\t'<<"SELECTION SORT" <<endl<< endl;
    Selection(ar, 6,comp_asc);
    Selection(arb, 6,comp_desc);
    Selection(arc, 6,comp_asc_abs);
    Selection(ard, 6,comp_desc_abs);

    for(i=0;i<6;i++)
        cout<<ar[i]<<"\t";
    cout<<endl;

    for(i=0;i<6;i++)
        cout<<arb[i]<<"\t";
    cout<<endl;

    for(i=0;i<6;i++)
        cout<<arc[i]<<"\t";
    cout<<endl;

    for(i=0;i<6;i++)
        cout<<ard[i]<<"\t";

    cout <<endl<<endl<<'\t'<<'\t'<< "INSERTION SORT" <<endl<< endl;
    Insertion(ar, 6,comp_asc);
    Insertion(arb, 6,comp_desc);
    Insertion(arc, 6,comp_asc_abs);
    Insertion(ard, 6,comp_desc_abs);

    for(i=0;i<6;i++)
        cout<<ar[i]<<"\t";
    cout<<endl;

    for(i=0;i<6;i++)
        cout<<arb[i]<<"\t";
    cout<<endl;

    for(i=0;i<6;i++)
        cout<<arc[i]<<"\t";
    cout<<endl;

    for(i=0;i<6;i++)
        cout<<ard[i]<<"\t";

    cout <<endl<<endl<<'\t'<<'\t'<< "COCKTAIL SORT" <<endl << endl;
    Cocktail(ar, 6,comp_asc);
    Cocktail(arb, 6,comp_desc);
    Cocktail(arc, 6,comp_asc_abs);
    Cocktail(ard, 6,comp_desc_abs);

    for(i=0;i<6;i++)
        cout<<ar[i]<<"\t";
    cout<<endl;

    for(i=0;i<6;i++)
        cout<<arb[i]<<"\t";
    cout<<endl;

    for(i=0;i<6;i++)
        cout<<arc[i]<<"\t";
    cout<<endl;

    for(i=0;i<6;i++)
        cout<<ard[i]<<"\t";
    cout<<endl;*/
    return 0;
}
