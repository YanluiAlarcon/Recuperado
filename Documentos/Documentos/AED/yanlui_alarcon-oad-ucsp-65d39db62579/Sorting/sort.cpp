//
// Created by yanlu on 11/16/2015.
//

#include "sort.h"
#include "iostream"

using namespace std;

void sort::Bubble_sort(int *first , int size, int (*compare) (int,int)) {
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

void sort::Selection_sort(int *first, int size, int (*compare)(int, int)) {
    int i, j, temp, min;
    for(i = 0; i < size ; i++){
        for(j = i, min = i ; j < size ; j++){
            if(compare(first[j] , first[min]) < 0)
                min = j;
        }
        temp = first[i];
        first[i] = first[min];
        first[min] = temp;
    }
}

void sort::Insertion_sort(int *first, int size, int (*compare) (int, int)) {
    for (int i = 0; i < size - 1; i++){
        int j = i + 1;
        int temp = first[j];
        if(compare(first[j], first[j - 1]) < 0){
            while (j < 0 && temp > first[j - 1]){
                first[j] = first[j - 1];
                j--;
            }
        }
        first[j] = temp;
    }
}

void sort::Cocktail_sort(int *first, int size, int (*compare)(int, int)) {
    int i,j,tmp;
    for (i = 0; i < size/2; i++) {
        bool swapped = false;
        for (j = i; j < size - i - 1; j++) {
            if (compare(first[j],first[j+1])>0) {
                tmp = first[j];
                first[j] = first[j+1];
                first[j+1] = tmp;
                swapped = true;
            }
        }
        for (j = size - 2 - i; j > i; j--) {
            if (compare(first[j], first[j-1])<0) {
                tmp = first[j];
                first[j] = first[j-1];
                first[j-1] = tmp;
                swapped = true;
            }
        }
        if(!swapped) break;
    }
}
