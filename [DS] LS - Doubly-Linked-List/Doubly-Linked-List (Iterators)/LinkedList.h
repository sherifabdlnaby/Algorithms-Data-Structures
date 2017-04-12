//
// Created by Sherif on 2/4/2017.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

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
    LinkedList(int myData, int size);
    virtual ~LinkedList();
    class iterator
    {
    private:
        node* ptr;
    public:
        iterator(node* rhs){ptr = rhs;} //Allow return endNode() beginNode() Directly
        iterator(const iterator& rhs){ ptr = rhs.ptr; }
        iterator operator++(int flag) { iterator ret = *this; ptr=ptr->getNxt(); return ret; }
        iterator operator--(int flag) { iterator ret = *this; ptr=ptr->getPrv(); return ret; }
        iterator operator++() {  ptr=ptr->getNxt(); return *this; }
        iterator operator--() {  ptr=ptr->getPrv(); return *this; }
        const int& operator*()  { return ptr->data;  }
        node* operator->() const { return ptr; }
        node* address(){ return ptr;}
        iterator& operator=(const iterator& rhs) { ptr = rhs.ptr; return *this; }
        iterator& operator=(node* rhs) {  ptr = rhs; return *this; }
        bool operator==(const iterator& rhs) { return ptr == rhs.ptr; }
        bool operator!=(const iterator& rhs) { return ptr != rhs.ptr; }
        /*bool operator==(node* rhs) { return ptr == ptr; }
        bool operator!=(node* rhs) { return ptr != ptr; }*/ //TODO better than creating constructor->copy->etc ?
    };
    iterator begin();
    iterator end();
    iterator search(int myData);  //O(n)
    iterator erase(iterator myNode);   //O(1)
    int push_front(int myData);   //O(1)
    int push_back(int myData);    //O(1)
    bool pop_back();              //O(1)
    bool pop_front();             //O(1)
    bool insert(int newData, iterator myNode);      //O(1)
    bool insert_after(int newData, iterator myNode);//O(1)
    bool deleteX(iterator myNode); //Erase bool ret //O(1)
    bool replace(iterator myNode, int newData);     //O(1)
    bool replace(int myData, int newData);      //O(n) replace first occurrence with data = myData -> newData
    bool replaceAll(int myData, int newData);   //O(n) Replace all of nodes of data = X
    bool deleteX(int myData);     //O(n)
    bool deleteAllX(int myData);  //O(n)
    void print();                 //O(n)
    ///BEFORE ITERATOR FUNCTIONS
    node* searchN(int myData);     //O(n)
    node* beginNode() const;          //O(1)
    node* endNode()   const;          //O(1)
    bool insert_afterN(int newData, node *myNode);   //O(1)
    bool insertN(int newData, node *myNode);         //O(1)
    bool replaceN(node *myNode, int newData);    //O(1)
    bool deleteN(node *myNode);   //O(1)
};

#endif
