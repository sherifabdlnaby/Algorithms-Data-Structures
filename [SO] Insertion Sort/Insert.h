//
// Created by Sherif on 3/3/2017.
//

#ifndef INSERTIONSORT_INSERT_H
#define INSERTIONSORT_INSERT_H


void insertionSort(int *arr, int start, int end) {
    for (int i = start+1; i <= end; ++i)
        if( arr[i] < arr[i-1] ) {
            int found = arr[i];
            int j = 0;
            for (j = i-1; j >= 0; --j) {
                if (arr[j] > found)
                    arr[j + 1] = arr[j];
                else
                    break;
            }
            arr[j+1] = found;
        }
}

void insertionSortSwap(int *arr, int start, int end) {
    for (int i = start+1; i <= end; ++i)
        if( arr[i] < arr[i-1] )
            for(int j=i-1; j >= 0; j--)
                if(arr[j] < arr[j+1])
                    break;
                else
                    std::swap(arr[j+1],arr[j]);
}


void printArr(int arr[], int sz) {
    for (int i = 0; i < sz; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

#endif //INSERTIONSORT_INSERT_H
