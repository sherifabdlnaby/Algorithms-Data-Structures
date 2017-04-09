//
// Created by Sherif on 2/4/2017.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include <ostream>

template<class T>
class node {
private:
    node *nxt;
public:
    T data;
    virtual ~node();
    node(T data, node *nxt = nullptr);
    node *getNxt() const;
    T getData();
    void setNxt(node *nxt);
    void setData(T data);
};

template<class T>
node<T>::node(T data, node *nxt) : data(data), nxt(nxt) {}

template<class T>
node<T>::~node() {}

template<class T>
node<T> *node<T>::getNxt() const {
    return nxt;
}

template<class T>
void node<T>::setNxt(node *nxt) {
    node::nxt = nxt;
}

template<class T>
T node<T>::getData() {
    return data;
}

template<class T>
void node<T>::setData(T data) {
    node::data = data;
}


#endif
