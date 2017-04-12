//
// Created by Sherif on 2/4/2017.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>

class node {
private:
    node* nxt;
    node* prv;
public:
    int data;
    virtual ~node();
    node(int data, node *nxt, node* prv);
    node *getNxt() const;
    node *getPrv() const;
    int  getData() const;
    void setNxt(node *nxt);
    void setPrv(node *prv);
    void setData(int data);
};

class LinkedList {
private:
    node* head;
    node* tail;
public:
    int size;
    LinkedList();
    virtual ~LinkedList();
    node *begin() const;          //O(1)
    node *end()   const;          //O(1)
    node *search(int myData);     //O(n)
    int push_front(int myData);   //O(1)
    int push_back(int myData);    //O(1)
    bool pop_back();              //O(1)
    bool pop_front();             //O(1)
    bool insert_after(int newData, node *myNode);   //O(1)
    bool insert(int newData, node *myNode);         //O(1)
    bool replace(node *myNode, int newData);    //O(1)
    bool replace(int myData, int newData);      //O(n) replace first occurrence with data = myData -> newData
    bool replaceAll(int myData, int newData);   //O(n) Replace all of nodes of data = X
    bool deleteX(int myData);     //O(n)
    bool deleteX(node *myNode);   //O(1)
    bool deleteAllX(int myData);  //O(n)
    void print();                 //O(n)
};

#endif
