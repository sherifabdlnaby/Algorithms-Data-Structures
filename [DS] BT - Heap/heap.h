//
// Created by Sherif on 4/19/2017.
//

#ifndef HEAP_HEAP_H
#define HEAP_HEAP_H

#include <vector>
using namespace std;

template <class T>
class heap {
private:
    vector<T> data;
    int  parentIdx(int &i);
    void heapify(int i);
    void buildHeap();
    bool (*cmp)(T A, T B);
    static bool cmpDefault(T x, T y);
public:
    heap(bool (*cmp)(T,T) = cmpDefault);
    heap(vector<T> &source, bool (*cmp)(T,T) = cmpDefault);
    int size();
    int  top();
    bool empty();
    void pop();
    void insert(int newData);
};

template<class T>
heap<T>::heap(vector<T> &source, bool (*cmp)(T,T) ) {
    //Set Cmp
    heap::cmp = cmp;

    //Set Data Vector
    data = source;

    //Build Heap
    buildHeap();
}

template<class T>
heap<T>::heap(bool (*cmp)(T,T)) {
    //Set Cmp
    heap::cmp = cmp;

    //Initialize Data Vector
    data = new vector<T>();
}

template<class T>
int heap<T>::parentIdx(int &i) { return (i - 1) / 2; }

template<class T>
void heap<T>::insert(int newData) {
    data.push_back(newData);

    int i = data.size()-1;
    int parent = parentIdx(i);

    //Bubble Upwards.
    while(cmp(data[i] , data[parent]) && i)
    {
        swap(data[i],  data[parentIdx(i)]);
        i = parent;
        parent = parentIdx(i);
    }

    return;
}

template<class T>
int heap<T>::top() {
    return data[0];
}

template<class T>
void heap<T>::pop() {
    if (empty())
        return;
    swap(data[0], data[data.size() - 1]);
    data.erase(data.end() - 1);
    heapify(0);
}

template<class T>
void heap<T>::buildHeap() {
    for (int i = (data.size() / 2) - 1; i >= 0; --i) {
        heapify(i);
    }
}

template<class T>
void heap<T>::heapify(int i) {
    int parent = i;
    int left = (i << 1) + 1;
    int right = (i << 1) + 2;
    if (cmp(data[left] , data[parent]) && left < data.size())
        parent = left;
    if (cmp(data[right] , data[parent]) && right < data.size())
        parent = right;
    if (parent != i) {
        swap(data[i], data[parent]);
        heapify(parent);
    }
}

template<class T>
int heap<T>::size() {
    return data.size();
}

template<class T>
bool heap<T>::empty() {
    return !data.size();
}

template<class T>
bool heap<T>::cmpDefault(T x, T y) {
    return x < y;
}

#endif //HEAP_HEAP_H
