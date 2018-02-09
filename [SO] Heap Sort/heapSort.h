//
// Created by Sherif on 4/19/2017.
//

#ifndef HEAP_HEAP_H
#define HEAP_HEAP_H

#include <vector>

using namespace std;

template<class T>
bool cmpDefault(T x, T y) {
    return x < y;
}

template<class T>
void heapify(vector<T> &data, int start, int end, bool (*cmp)(T, T)) {
    int parent = start;
    int left = (start << 1) + 1;
    int right = (start << 1) + 2;

    // note that Cmp is negated here for heapsort!
    if (left < end && !cmp(data[left], data[parent]))
        parent = left;
    if (right < end && !cmp(data[right], data[parent]))
        parent = right;
    if (parent != start) {
        swap(data[start], data[parent]);
        heapify(data, parent, end, cmp);
    }
}

template<class T>
void buildHeap(vector<T> &data, int start, int end, bool (*cmp)(T, T)) {
    for (int i = (end / 2) - 1; i >= start; --i) {
        heapify(data, i, end, cmp);
    }
}

template<class T>
void heapSort(vector<T> &data, int start, int end, bool (*cmp)(T, T) = cmpDefault) {
    //Build heap O(N)
    buildHeap(data, start, end, cmp);

    //Sort O(N log N)
    for (int i = end - 1; i >= start; --i) {
        // Move current root to end
        swap(data[0], data[i]);

        // call heapify on the reduced heap
        heapify(data, start, i, cmp);
    }
}

#endif //HEAP_HEAP_H
