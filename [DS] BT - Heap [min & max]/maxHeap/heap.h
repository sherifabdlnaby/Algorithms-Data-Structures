//
// Created by Sherif on 4/19/2017.
//

#ifndef HEAP_HEAP_H
#define HEAP_HEAP_H

#include <vector>
using namespace std;

class heap {
    vector<int> data;
public:
    heap(vector<int> &source);
    int size();
    int  top();
    int  parentIdx(int &i);
    bool empty();
    void heapify(int i);
    void buildHeap();
    void buildHeap(int start, int end);
    void pop();
    void insert(int newData);
};


heap::heap(vector<int> &source) {
    data = source;
    buildHeap();
}

int heap::parentIdx(int &i) { return (i % 2 ? i : i - 1) / 2; }

void heap::insert(int newData) {
    data.push_back(newData);
    int i = data.size()-1;
    int parent = parentIdx(i);
    //Bubble Upwards.
    while(data[i] > data[parent] && i)
    {
        swap(data[i],  data[parentIdx(i)]);
        i = parent;
        parent = parentIdx(i);
    }
    return;
}

int heap::top() {
    return data[0];
}

void heap::pop() {
    if(empty())
        return;
    swap(data[0],data[data.size()-1]);
    data.erase(data.end()-1);
    heapify(0);
}

void heap::buildHeap() {
    for (int i = data.size()-1; i >= 0 ; --i) {
        heapify(i);
    }
}

void heap::buildHeap(int start, int end) {
    for (int i = end; i >= start ; --i) {
        heapify(i);
    }
}

void heap::heapify(int i) {
    int left  = (i<<1)+1;
    int right = (i<<1)+2;
    int parent = i;
    if (left < data.size() && data[left] > data[parent])
        parent = left;
    if (right < data.size() && data[right] > data[parent])
        parent = right;
    if (parent != i)
    {
        swap (data[i], data[parent]);
        heapify(parent);
    }

}

int heap::size() {
    return data.size();
}

bool heap::empty() {
    return !data.size();
}

#endif //HEAP_HEAP_H
