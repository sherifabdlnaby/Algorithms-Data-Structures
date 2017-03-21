//
// Created by Sherif on 2/4/2017.
//

#ifndef ASFSD_LINKEDLIST_H
#define ASFSD_LINKEDLIST_H


#include <ostream>

class node {
private:
    node* nxt;
public:
    int data;
    virtual ~node();
    node(int data, node *nxt= nullptr);
    node *getNxt() const;
    void setNxt(node *nxt);
    int getData() const;
    void setData(int data);
};



class LinkedList {
private:
    node* head;
public:
    int size;
    LinkedList();
    void print();//O(n)
    node *begin() const; //O(1)
    node* search(int x);//O(n)
    int addBack(int x); //O(1)
    int addFirst(int x); //O(1)
    bool addAfter(int a, node* x); //O(1)
    bool popback();
    bool popfront();
    bool addBefore(int a, node* x); //O(n)
    bool replace(int a, node *x); //O(1)
    bool replace(int a, int x); //O(n) Adds after first occurrence of X
    bool replaceAll(int a, int x); //O(n)
    bool deleteX(node* x); //O(n)
    bool deleteX(int x); //O(n)
    bool deleteAllX(int x); //O(n)
};




#endif //ASFSD_LINKEDLIST_H
