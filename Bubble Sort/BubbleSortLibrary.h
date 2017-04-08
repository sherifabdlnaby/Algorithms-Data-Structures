//
// Created by Sherif on 3/12/2017.
//
#include <iostream>
#ifndef BUBBLE_SORT_BUBBLESORTLIBRARY_H
#define BUBBLE_SORT_BUBBLESORTLIBRARY_H


void BubbleSort(int data[], int start, int end)
{
    for (int i = 0; i < end-1; ++i){
        for (int j = 0; j < end-1; ++j) {
            if(data[j] > data[j+1]) {
                std::swap(data[j], data[j+1]);
            }
        }
    }
}


#endif //BUBBLE_SORT_BUBBLESORTLIBRARY_H
