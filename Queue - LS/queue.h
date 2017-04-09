//
// Created by Sherif on 4/9/2017.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

#include <iostream>
#include "node.h"

template<class T>
class queue {
private:
    node<T> *head;
    node<T> *tail;
public:
    int sizeX;
    queue();
    virtual ~queue();
    node<T> *begin() const;        //O(1)
    int size();
    T &top();
    void pop();                 //O(1)
    void push(T newData);       //O(1)
    void print();
};

template<class T>
queue<T>::queue() {
    sizeX = 0;
    head = new node<T>(T(), NULL, NULL); //Header value = 0(Won't use it anyway), Nxt = Null (Empty List).
    tail = head;
}

template<class T>
queue<T>::~queue() {
    node<T> *itr = head;
    node<T> *toDelete;
    while (itr) {
        toDelete = itr;     //hold current position.
        itr = itr->getNxt();//iterate...
        delete toDelete;    //delete current position.
    }
}

template<class T>
node<T> *queue<T>::begin() const {
    return head->getNxt();
}

template<class T>
void queue<T>::push(T newData) {
    node<T> *tmp = new node<T>(newData, NULL, tail);
    tail->setNxt(tmp);
    tail = tmp;
    sizeX++;
    return;
}

template<class T>
void queue<T>::pop() {
    if (!begin()) //If stack is empty, (begin == NULL).
        return;
    node<T>* toDelete = tail;
    tail = tail->getPrv();
    tail->setNxt(NULL);
    delete toDelete;
    sizeX--;
    return;
}

template<class T>
void queue<T>::print() {
    node<T> *itr = begin();
    while (itr) {
        std::cout << itr->getData() << std::endl;
        itr = itr->getNxt();
    }
    std::cout << "---------------" << std::endl;
}

template<class T>
T &queue<T>::top() {
    return begin()->data;
}

template<class T>
int queue<T>::size() {
    return sizeX;
}


#endif //QUEUE_QUEUE_H
