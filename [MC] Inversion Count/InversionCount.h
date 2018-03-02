//
// Created by Sherif on 3/12/2017.
//
#include <iostream>

using namespace std;
#ifndef UNTITLED_INVERSIONCOUNT_H
#define UNTITLED_INVERSIONCOUNT_H

int mergeAndCount(int *arr, int start, int end, int mid) {
    int cpyArr[end - start + 1];
    int i = start;
    int j = mid + 1;
    int count = 0;
    for (int k = 0; k < end - start + 1; ++k) {
        if (j > end)
            cpyArr[k] = arr[i++];
        else if (i > mid)
            cpyArr[k] = arr[j++];
        else if (arr[i] <= arr[j])
            cpyArr[k] = arr[i++];
        else {
            //Inversion found!
            count += mid + 1 - i;
            cpyArr[k] = arr[j++];
        }
    }
    //Copying back to Original Array...
    int x = start;
    for (int l = 0; l < end - start + 1; ++l) {
        arr[x++] = cpyArr[l];
    }
    return count;
}

int countInvert(int arr[], int start, int end) {

    if (end <= start)
        return 0;
    int mid = start + ((end - start) / 2);          //Avoid Overflow
    int a = countInvert(arr, start, mid);           //Right side inner inversions count
    int b = countInvert(arr, mid + 1, end);         //Left side inner inversions count
    int c = mergeAndCount(arr, start, end, mid);    //Inversions count between the two sides.
    return a + b + c;
}


int countInvertCommented(int arr[], int start, int end) {

    if (end <= start) {
        cout << endl << "------Base-Case------" << endl;
        for (int i = start; i <= end; ++i) {
            cout << arr[i] << " ";
        }

        cout << endl << "---------x---------" << endl;
        return 0;
    }

    int mid = (start + end) / 2;
    int a = countInvertCommented(arr, start, mid);
    int b = countInvertCommented(arr, mid + 1, end);

    cout << "------BEFORE-------" << endl;
    for (int i = start; i <= mid; ++i) {
        cout << arr[i] << " ";
    }
    cout << "| ";
    for (int i = mid + 1; i <= end; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Left Inv: " << a << " Right Inv: " << b << endl;

    int c = mergeAndCount(arr, start, end, mid);

    cout << "------AFTER-------" << endl;
    for (int i = start; i <= mid; ++i) {
        cout << arr[i] << " ";
    }
    cout << "| ";
    for (int i = mid + 1; i <= end; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Merge Inv: " << c << endl;
    cout << "Total: " << a + b + c << endl;
    return a + b + c;
}


#endif //UNTITLED_INVERSIONCOUNT_H
