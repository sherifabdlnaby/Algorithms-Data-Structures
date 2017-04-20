//
// Created by Sherif on 4/19/2017.
//

#ifndef HEAP_HEAP_H
#define HEAP_HEAP_H

#include <vector>
using namespace std;

void heapify(int i, int end, vector<int> &data) { //following MaxHeap criteria
    int left  = (i<<1)+1;
    int right = (i<<1)+2;
    int parent = i;
    if (left <= end && data[left] > data[parent]) //Flip > -> < to sort by Greater (we build a minHeap instead so heapSort works by greater)
        parent = left;
    if (right <= end && data[right] > data[parent])
        parent = right;
    if (parent != i)
    {
        swap (data[i], data[parent]);
        heapify(parent, end, data);
    }

}

void buildHeap(int start, int end, vector<int> &data) { //Max-Heap
    for (int i = end; i >= start ; --i) {
        heapify(i, end, data);
    }
}

void heapSort(vector<int> &data, int begin, int end)
{
    buildHeap(begin,end,data);
    for (int i = begin; i < end; ) {
        swap(data[i],data[end]);
        --end;
        heapify(begin,end,data);
    }
}


#endif //HEAP_HEAP_H
