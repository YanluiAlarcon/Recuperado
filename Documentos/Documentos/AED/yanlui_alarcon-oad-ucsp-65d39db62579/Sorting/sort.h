//
// Created by yanlu on 11/16/2015.
//

#ifndef SORTING_SORT_H
#define SORTING_SORT_H
#include <stdlib.h>

class sort {
public:
    void Bubble_sort(int *, int, int(*compare)(int, int));
    void Selection_sort(int *, int, int (*compare)(int, int));
    void Insertion_sort(int *, int, int (*compare)(int,int));
    void Cocktail_sort(int *, int, int (*compare)(int,int));
private:
};


#endif //SORTING_SORT_H
