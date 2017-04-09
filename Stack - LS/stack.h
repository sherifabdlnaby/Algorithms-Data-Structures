//
// Created by Sherif on 4/9/2017.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

#include <iostream>
#include "node.h"

template<class T>
class stack {
private:
    node<T> *head;
public:
    int sizeX;
    stack();
    virtual ~stack();
    node<T> *begin() const;     //O(1)
    int size();
    T &top();
    void pop();                 //O(1)
    void push(T newData);       //O(1)
    void print();
};

template<class T>
stack<T>::stack() {
    sizeX = 0;
    head = new node<T>(T(), NULL); //Header value = 0(Won't use it anyway), Nxt = Null (Empty List).
}

template<class T>
stack<T>::~stack() {
    node<T> *itr = head;
    node<T> *toDelete;
    while (itr) {
        toDelete = itr;     //hold current position.
        itr = itr->getNxt();//iterate...
        delete toDelete;    //delete current position.
    }
}

template<class T>
node<T> *stack<T>::begin() const {
    return head->getNxt();
}

template<class T>
void stack<T>::push(T newData) {
    node<T> *tmp = new node<T>(newData, begin());
    head->setNxt(tmp);
    sizeX++;
    return;
}

template<class T>
void stack<T>::pop() {
    if (!begin()) //If stack is empty, (begin == NULL).
        return;
    node<T> *tmp = begin();
    head->setNxt(begin()->getNxt());
    delete (tmp);
    sizeX--;
    return;
}

template<class T>
void stack<T>::print() {
    node<T> *itr = begin();
    while (itr) {
        std::cout << itr->getData() << std::endl;
        itr = itr->getNxt();
    }
    std::cout << "---------------" << std::endl;
}

template<class T>
T &stack<T>::top() {
    return begin()->data;
}

template<class T>
int stack<T>::size() {
    return sizeX;
}


#endif //STACK_STACK_H
