//
// Created by Sherif on 2/4/2017.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include <ostream>

class node {
private:
    node* nxt;
public:
    int data;
    virtual ~node();
    node(int data, node *nxt= nullptr);
    node *getNxt() const;
    int  getData() const;
    void setNxt(node *nxt);
    void setData(int data);
};

class LinkedList {
private:
    node* head;
public:
    int size;
    LinkedList();
    virtual ~LinkedList();
    node *begin() const;        //O(1)
    node *search(int myData);   //O(n)
    int addFirst(int myData);   //O(1)
    int addBack(int myData);    //O(n) //TODO add tail.
    bool popback();             //O(n)
    bool popfront();            //O(1)
    bool addAfter(int newData, node *myNode);   //O(1)
    bool addBefore(int newData, node *myNode);  //O(n)
    bool replace(int newData, node *myNode);    //O(1)
    bool replace(int newData, int myData);      //O(n) Adds first occurrence of node with data = X
    bool replaceAll(int newData, int myData);   //O(n) Replace all of nodes of data = X
    bool deleteX(int myData);           //O(n)
    bool deleteX(node *myNode);         //O(1)
    bool deleteAllX(int myData);        //O(n)
    void print();               //O(n)
};


#endif
