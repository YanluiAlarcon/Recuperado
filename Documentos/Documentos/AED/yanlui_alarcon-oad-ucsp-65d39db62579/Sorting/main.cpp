#include <iostream>
#include "sort.h"

using namespace std;

int compare_asc(int A, int B) {
    return A-B;
}

int compare_desc(int A, int B) {
    return B-A;
}

int compare_asc_abs(int A, int B){
    return abs(A)-abs(B);
}

int compare_desc_abs(int A, int B) {
    return abs(B)-abs(A);
}

int main() {
    cout << "SORTING ALGORITHM!" << endl;
    int i;
    int list1[6] = {-3,2,-1,6,-4,5};
    int list2[6] = {-3,2,-1,6,-4,5};
    int list3[6] = {-3,2,-1,6,-4,5};
    int list4[6] = {-3,2,-1,6,-4,5};
    sort sort1;

    cout <<'\t'<<'\t'<< "Booble Sort" << endl;

    sort1.Bubble_sort(list1,6,compare_asc);
    sort1.Bubble_sort(list2,6,compare_desc);
    sort1.Bubble_sort(list3,6,compare_asc_abs);
    sort1.Bubble_sort(list4,6,compare_desc_abs);

    for(i = 0 ; i < 6 ; i++)
        cout << list1[i] << " ";
    cout << endl;

    for(i = 0 ; i < 6 ; i++)
        cout << list2[i] << " ";
    cout << endl;

    for(i = 0 ; i < 6 ; i++)
        cout << list3[i] << " ";
    cout << endl;

    for(i = 0 ; i < 6 ; i++)
        cout << list4[i] << " ";
/*

    cout << endl <<'\t'<<'\t'<< "Insertion Sort" << endl;

    sort1.Insertion_sort(list1,sort1.size,compare_asc);
    sort1.Insertion_sort(list2,sort1.size,compare_desc);
    sort1.Insertion_sort(list3,sort1.size,compare_asc_abs);
    sort1.Insertion_sort(list4,sort1.size,compare_desc_abs);

    for(i = 0 ; i < sort1.size ; i++)
        cout << list1[i] << " ";

    cout << endl;
    for(i = 0 ; i < sort1.size ; i++)
        cout << list2[i] << " ";

    cout << endl;
    for(i = 0 ; i < sort1.size ; i++)
        cout << list3[i] << " ";

    cout << endl;
    for(i = 0 ; i < sort1.size ; i++)
        cout << list4[i] << " ";

    cout << endl <<'\t'<<'\t'<< "Selection Sort" << endl;

    sort1.Selection_sort(list1,sort1.size,compare_asc);
    sort1.Selection_sort(list2,sort1.size,compare_desc);
    sort1.Selection_sort(list3,sort1.size,compare_asc_abs);
    sort1.Selection_sort(list4,sort1.size,compare_desc_abs);

    for(i = 0 ; i < sort1.size ; i++)
        cout << list1[i] << " ";

    cout << endl;
    for(i = 0 ; i < sort1.size ; i++)
        cout << list2[i] << " ";

    cout << endl;
    for(i = 0 ; i < sort1.size ; i++)
        cout << list3[i] << " ";

    cout << endl;
    for(i = 0 ; i < sort1.size ; i++)
        cout << list4[i] << " ";

    cout << endl <<'\t'<<'\t'<< "Cocktil Sort" << endl;

    sort1.Cocktail_sort(list1,sort1.size,compare_asc);
    sort1.Cocktail_sort(list2,sort1.size,compare_desc);
    sort1.Cocktail_sort(list3,sort1.size,compare_asc_abs);
    sort1.Cocktail_sort(list4,sort1.size,compare_desc_abs);

    for(i = 0 ; i < sort1.size ; i++)
        cout << list1[i] << " ";

    cout << endl;
    for(i = 0 ; i < sort1.size ; i++)
        cout << list2[i] << " ";

    cout << endl;
    for(i = 0 ; i < sort1.size ; i++)
        cout << list3[i] << " ";

    cout << endl;
    for(i = 0 ; i < sort1.size ; i++)
        cout << list4[i] << " ";*/

    return 0;
}