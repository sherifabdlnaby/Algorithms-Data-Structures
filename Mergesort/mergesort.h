//
// Created by Sherif on 3/3/2017.
//

#include <iostream>
using namespace std;
#ifndef MERGESORT_MERGE_H
#define MERGESORT_MERGE_H


void insertionSort(int arr[], int start, int end);

void mergeArrays(int arr[], int start, int end, int mid) {
    int n = end - start + 1;
    int idx1 = start;
    int idx2 = mid + 1;
    int *cpyArr = new int[n];
    for (int i = 0; i < n; ++i) {
        if (idx1 > mid)
            cpyArr[i] = arr[idx2++];
        else if (idx2 > end)
            cpyArr[i] = arr[idx1++];
        else if (arr[idx1] < arr[idx2])
            cpyArr[i] = arr[idx1++];
        else
            cpyArr[i] = arr[idx2++];
    }
    int j = 0;
    for (int i = start; i <= end; i++)
        arr[i] = cpyArr[j++];

    return;
}

void mergeSort(int arr[], int start, int end) {
    if (end <= start)
        return;
    else {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        mergeArrays(arr, start, end, mid);
    }
    return;
}

void mergeSortOpt(int arr[], int start, int end) {
    if (end <= start)
        return;
    else if (end - start < 41)
        insertionSort(arr, start, end);
    else {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        mergeArrays(arr, start, end, mid);
    }
    return;
}


void mergeSortCommented(int arr[], int start, int end) {

    if (end <= start) {
        cout << endl << "-----base case-----" << endl;

        for (int i = start; i <= end; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl << "---------x---------" << endl;
        return;
    }
    int mid = (start + end) / 2;
    mergeSortCommented(arr, start, mid);
    mergeSortCommented(arr, mid + 1, end);
    cout << endl << "-------two arrays before sort--------" << endl;
    for (int i = start; i <= mid; ++i) {
        cout << arr[i] << " ";
    }
    cout << "| ";
    for (int j = mid + 1; j <= end; ++j) {
        cout << arr[j] << " ";
    }
    cout << endl << "------------------------------------" << endl;
    mergeArrays(arr, start, end, mid);
    cout << endl << "-------two arrays after sort--------" << endl;
    for (int i = start; i <= mid; ++i) {
        cout << arr[i] << " ";
    }
    cout << "| ";
    for (int j = mid + 1; j <= end; ++j) {
        cout << arr[j] << " ";
    }
    cout << endl << "------------------------------------" << endl;
    return;
}


void insertionSort(int arr[], int start, int end) {
    int found, j;
    for (int i = start + 1; i <= end; ++i) {
        if (arr[i] < arr[i - 1]) {
            found = arr[i];
            j = 0;
            for (j = i - 1; j >= start; --j) {
                if (arr[j] > found)
                    arr[j + 1] = arr[j];
                else break;
            }
            arr[j + 1] = found;
        }
    }
}

#endif //MERGESORT_MERGE_H
