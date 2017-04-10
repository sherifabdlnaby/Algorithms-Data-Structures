//
// Created by Sherif on 2/4/2017.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;
template <class T>
class node {
private:
    node* nxt;
    node* prv;
public:
    T data;
    virtual ~node();
    node(T data, node *nxt, node* prv);
    node *getNxt() const;
    node *getPrv() const;
    T  getData() const;
    void setNxt(node *nxt);
    void setPrv(node *prv);
    void setData(T data);
};

template <class T>
class LinkedList {
private:
    node<T>* head;
    node<T>* tail;
public:
    int size;
    LinkedList();
    LinkedList(T myData, int size);
    virtual ~LinkedList();
    class iterator
    {
    private:
        node<T>* ptr;
    public:
        iterator(node<T>* rhs){ptr = rhs;} //Allow return endNode() beginNode() Directly
        iterator(const iterator& rhs){ ptr = rhs.ptr; }
        iterator operator++(int flag) { iterator ret = *this; ptr=ptr->getNxt(); return ret; }
        iterator operator--(int flag) { iterator ret = *this; ptr=ptr->getPrv(); return ret; }
        iterator operator++() {  ptr=ptr->getNxt(); return *this; }
        iterator operator--() {  ptr=ptr->getPrv(); return *this; }
        const T& operator*()  { return ptr->data;  }
        node<T>* operator->() const { return ptr; }//TODO eshta ?
        node<T>* address(){ return ptr;} 
        iterator& operator=(const iterator& rhs) { ptr = rhs.ptr; return *this; }
        iterator& operator=(node<T>* rhs) {  ptr = rhs; return *this; }
        bool operator==(const iterator& rhs) { return ptr == rhs.ptr; }
        bool operator!=(const iterator& rhs) { return ptr != rhs.ptr; }
        /*bool operator==(node* rhs) { return ptr == ptr; }
        bool operator!=(node* rhs) { return ptr != ptr; }*/ 
    };
    iterator begin();
    iterator end();
    iterator search(T myData);         //O(n)
    iterator erase(iterator myNode);   //O(1)	//Return next iterator after deletion
    void push_front(T myData);   //O(1)
    void push_back(T myData);    //O(1)
    bool pop_back();             //O(1)
    bool pop_front();            //O(1)
    bool insert(T newData, iterator myNode);      //O(1)
    bool insert_after(T newData, iterator myNode);//O(1)
    bool deleteX(iterator myNode); //Erase bool   //O(1)
    bool replace(iterator myNode, T newData);     //O(1)
    bool replace(T myData, T newData);      //O(n) replace first occurrence with data = myData -> newData
    bool replaceAll(T myData, T newData);   //O(n) Replace all of nodes of data = X
    bool deleteX(T myData);     //O(n)
    bool deleteAllX(T myData);  //O(n)
    void print();               //O(n)
    ///BEFORE ITERATOR FUNCTIONS
    node<T>* searchN(T myData);     //O(n)
    node<T>* beginNode() const;     //O(1)
    node<T>* endNode()   const;     //O(1)
    bool insert_afterN(T newData, node<T> *myNode);   //O(1)
    bool insertN(T newData, node<T> *myNode);         //O(1)
    bool replaceN(node<T> *myNode, T newData);        //O(1)
    bool deleteN(node<T> *myNode);  //O(1)
};
template <class T>
node<T>::node(T data, node<T> *nxt, node<T>* prv) : data(data), nxt(nxt), prv(prv) {}

template <class T>
node<T>::~node() {}

template <class T>
node<T> *node<T>::getNxt() const {
    return nxt;
}
template <class T>
node<T> *node<T>::getPrv() const {
    return prv;
}
template <class T>
void node<T>::setNxt(node *nxt) {
    node::nxt = nxt;
}
template <class T>
T node<T>::getData() const {
    return data;
}
template <class T>
void node<T>::setData(T data) {
    node::data = data;
}

template <class T>
void node<T>::setPrv(node<T> *prv) {
    node::prv = prv;
}

template <class T>
LinkedList<T>::LinkedList() {
    size = 0;
    head = new node<T>(T(),NULL,NULL); //Header value = 0(Won't use it anyway), Nxt = Null (Empty List).
    tail = new node<T>(T(),NULL,head);
    head->setNxt(tail);
}

template <class T>
LinkedList<T>::LinkedList(T myData, int size) {
    LinkedList::size = 0;
    head = new node<T>(T(),NULL,NULL);
    tail = new node<T>(T(),NULL,head);
    head->setNxt(tail);
    for (int i = 0; i < size; ++i) {
        push_back(myData);
    }
}

template <class T>
LinkedList<T>::~LinkedList() {
    node<T>* itr = head;
    node<T>* toDelete;
    while(itr)
    {
        toDelete = itr;         //hold current position.
        itr = itr->getNxt();    //iterate...
        delete toDelete;        //delete current position.
    }
}

template <class T>
node<T> *LinkedList<T>::beginNode() const {
    return head->getNxt();
}

template <class T>
node<T> *LinkedList<T>::endNode() const {
    return tail;
}

template <class T>
void LinkedList<T>::push_back(T myData) {
    node<T>* newNode = new node<T>(myData,tail,tail->getPrv());
    tail->getPrv()->setNxt(newNode);
    tail->setPrv(newNode);
    size++;
    return;
}

template <class T>
void LinkedList<T>::push_front(T myData) {
    node<T>* tmp = new node<T>(myData, beginNode(),head);
    beginNode()->setPrv(tmp);
    head->setNxt(tmp);
    size++;
    return;
}

template <class T>
bool LinkedList<T>::pop_back() {
    if(beginNode() == endNode())
        return false; //Linked-List is empty;
    node<T>* toDelete = tail->getPrv();
    toDelete->getPrv()->setNxt(tail);
    tail->setPrv(toDelete->getPrv());
    delete toDelete;
    size--;
    return true;
}

template <class T>
bool LinkedList<T>::pop_front() {
    if(beginNode() == endNode())
        return false; //Linked-List is empty;
    node<T>* toDelete = beginNode();
    toDelete->getNxt()->setPrv( head );
    head->setNxt(toDelete->getNxt());
    delete toDelete;
    size--;
    return true;
}

template <class T>
bool LinkedList<T>::insert_afterN(T newData, node<T> *myNode){
    if(!myNode) //if NULL is passed, return false;
        return false;
    node<T>* tmp = new node<T>(newData,myNode->getNxt(),myNode);
    myNode->getNxt()->setPrv(tmp);
    myNode->setNxt(tmp);
    size++;
    return true;
}

template <class T>
bool LinkedList<T>::insertN(T newData, node<T> *myNode) { //INSERT
    if(!myNode) //if NULL is passed, return false (To use search() T the parameters;
        return false;
    node<T>* tmp = new node<T>(newData, myNode, myNode->getPrv());
    myNode->getPrv()->setNxt(tmp);
    myNode->setPrv(tmp);
    return false;
}

template <class T>
void LinkedList<T>::print() {
    if(beginNode() == endNode()) {
        cout << "->Empty" << endl;
        return;
    }
    node<T>* tmp = beginNode();
    while(tmp != tail){
        cout << tmp->data << " ";
        tmp = tmp->getNxt();
    }
    cout << endl;
    return;
}

template <class T>
node<T>* LinkedList<T>::searchN(T myData) {
    node<T>* ptr = beginNode();
    while(ptr != endNode()) {
        if (ptr->data == myData) {
            return ptr;
        }
        ptr = ptr->getNxt();
    }
    return NULL;
}

template <class T>
bool LinkedList<T>::replaceN(node<T> *myNode, T newData) {
    if(!myNode) //If NULL return false -> to use search() as a parameter.
        return false;
    myNode->setData(newData);
    return true;
}

template <class T>
bool LinkedList<T>::replace(T myData, T newData) {
    node<T> *ptr = beginNode();
    while (ptr != endNode()) {
        if (ptr->data == myData){
            ptr->data = newData;
            return true;
        }
        ptr = ptr->getNxt();
    }
    return false;
}

template <class T>
bool LinkedList<T>::replaceAll(T myData, T newData) {
    node<T> *ptr = beginNode();
    bool flag = false;
    while (ptr != endNode()) {
        if (ptr->data == myData){
            ptr->data = newData;
            flag = true;
        }
        ptr = ptr->getNxt();
    }
    return flag;
}

template <class T>
bool LinkedList<T>::deleteN(node<T> *myNode) {
    myNode->getPrv()->setNxt( myNode->getNxt() );
    myNode->getNxt()->setPrv( myNode->getPrv() );
    delete myNode;
    return true;
}

template <class T>
bool LinkedList<T>::deleteX(T myData) {
    node<T>* ptr = beginNode();
    node<T>* myNode;
    while(ptr != endNode())
    {
        if (ptr->getData() == myData) {
            myNode = ptr;
            myNode->getPrv()->setNxt( myNode->getNxt() );
            myNode->getNxt()->setPrv( myNode->getPrv() );
            delete myNode;
            return true;
        }
        else
            ptr = ptr->getNxt();

    }
    return false;
}

template <class T>
bool LinkedList<T>::deleteAllX(T myData) {
    node<T>* ptr = beginNode();
    node<T>* myNode; bool flag = false;
    while(ptr != endNode())
    {
        if (ptr->getData() == myData) {
            myNode = ptr;
            myNode->getPrv()->setNxt( myNode->getNxt() );
            myNode->getNxt()->setPrv( myNode->getPrv() );
            ptr = ptr->getNxt();
            delete myNode;
            flag = true;
        }
        else
            ptr = ptr->getNxt();

    }
    return flag;
}


template <typename T>
typename LinkedList<T>::iterator LinkedList<T>::begin(){
    return beginNode();
}

template <typename T>
typename LinkedList<T>::iterator LinkedList<T>::end(){
    return endNode();
}

template <typename T>
typename LinkedList<T>::iterator LinkedList<T>::search(T myData) {
    iterator ptr = beginNode();
    while(ptr != end()) {
        if (*ptr == myData) {
            return ptr;
        }
        ptr++;
    }
    return endNode();
}

template <typename T>
bool LinkedList<T>::insert_after(T newData, LinkedList::iterator myNode) {
    if(myNode == end())
        return false;
    node<T>* tmp = new node<T>(newData,myNode->getNxt(),myNode.address());
    myNode->getNxt()->setPrv(tmp);
    myNode->setNxt(tmp);
    size++;
    return true;
}

template <typename T>
bool LinkedList<T>::insert(T newData, LinkedList::iterator myNode) {
    node<T>* tmp = new node<T>(newData, myNode.address(), myNode->getPrv());
    myNode->getPrv()->setNxt(tmp);
    myNode->setPrv(tmp);
    return false;
}

template <typename T>
bool LinkedList<T>::replace(LinkedList::iterator myNode, T newData) {
    if(myNode == end())
        return false;
    myNode->setData(newData);
    return true;
}

template <typename T>
bool LinkedList<T>::deleteX(LinkedList::iterator myNode) {
    if(myNode == endNode())
        return false;
    myNode->getPrv()->setNxt( myNode->getNxt() );
    myNode->getNxt()->setPrv( myNode->getPrv() );
    delete myNode.address();
    return true;
}

template <typename T>
typename LinkedList<T>::iterator LinkedList<T>::erase(LinkedList::iterator myNode) {
    if(myNode == end())
        return end();
    myNode->getPrv()->setNxt( myNode->getNxt() );
    myNode->getNxt()->setPrv( myNode->getPrv() );
    delete myNode++.address();
    return myNode;
}
#endif
