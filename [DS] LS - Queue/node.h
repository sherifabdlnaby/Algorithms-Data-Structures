//
// Created by Sherif on 2/4/2017.
//

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

template<class T>
class node {
private:
    node *nxt;
    node *prv;
public:
    T data;
    virtual ~node();
    node(T data, node *nxt, node *prv);
    node *getNxt() const;
    node *getPrv() const;
    T getData();
    void setNxt(node *nxt);
    void setData(T data);
};

template<class T>
node<T>::node(T data, node *nxt, node *prv) : data(data), nxt(nxt), prv(prv) {}

template<class T>
node<T>::~node() {}

template<class T>
node<T> *node<T>::getNxt() const {
    return nxt;
}

template<class T>
node<T> *node<T>::getPrv() const {
    return prv;
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
