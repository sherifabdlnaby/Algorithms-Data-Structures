//
// Created by Sherif on 2/4/2017.
//

#include "LinkedList.h"
#include <iostream>
using namespace std;
node::node(int data, node *nxt, node* prv) : data(data), nxt(nxt), prv(prv) {}

node::~node() {}

node *node::getNxt() const {
    return nxt;
}

node *node::getPrv() const {
    return prv;
}

void node::setNxt(node *nxt) {
    node::nxt = nxt;
}

int node::getData() const {
    return data;
}

void node::setData(int data) {
    node::data = data;
}

void node::setPrv(node *prv) {
    node::prv = prv;
}

LinkedList::LinkedList() {
    size = 0;
    head = new node(0,NULL,NULL); //Header value = 0(Won't use it anyway), Nxt = Null (Empty List).
    tail = new node(0,NULL,head);
    head->setNxt(tail);
}

LinkedList::~LinkedList() {
    node* itr = head;
    node* toDelete;
    while(itr)
    {
        toDelete = itr;     //hold current position.
        itr = itr->getNxt();    //iterate...
        delete toDelete;    //delete current position.
    }
}

node *LinkedList::begin() const {
    return head->getNxt();
}

node *LinkedList::end() const {
    return tail;
}

int LinkedList::push_back(int myData) {
    node* newNode = new node(myData,tail,tail->getPrv());
    tail->getPrv()->setNxt(newNode);
    tail->setPrv(newNode);
    size++;
    return 0;
}

int LinkedList::push_front(int myData) {
    node* tmp = new node(myData,begin(),head);
    begin()->setPrv(tmp);
    head->setNxt(tmp);
    size++;
    return 0;
}

bool LinkedList::pop_back() {
    if(begin() == end())
        return false; //Linked-List is empty;
    node* toDelete = tail->getPrv();
    toDelete->getPrv()->setNxt(tail);
    tail->setPrv(toDelete->getPrv());
    delete toDelete;
    size--;
    return true;
}

bool LinkedList::pop_front() {
    if(begin() == end())
        return false; //Linked-List is empty;
    node* toDelete = begin();
    toDelete->getNxt()->setPrv( head );
    head->setNxt(toDelete->getNxt());
    delete toDelete;
    size--;
    return true;
}

bool LinkedList::insert_after(int newData, node *myNode){
    if(!myNode) //if NULL is passed, return false;
        return false;
    node* tmp = new node(newData,myNode->getNxt(),myNode);
    myNode->getNxt()->setPrv(tmp);
    myNode->setNxt(tmp);
    size++;
    return true;
}

bool LinkedList::insert(int newData, node *myNode) { //INSERT
    if(!myNode) //if NULL is passed, return false (To use search() int the parameters;
        return false;
    node* tmp = new node(newData, myNode, myNode->getPrv());
    myNode->getPrv()->setNxt(tmp);
    myNode->setPrv(tmp);
    return false;
}

void LinkedList::print() {
    if(begin() == end()) {
        cout << "->Empty" << endl;
        return;
    }
    node* tmp = begin();
    while(tmp != tail){
        cout << tmp->data << " ";
        tmp = tmp->getNxt();
    }
    cout << endl;
    return;
}

node* LinkedList::search(int myData) {
    node* ptr = begin();
    while(ptr != end()) {
        if (ptr->data == myData) {
            return ptr;
        }
        ptr = ptr->getNxt();
    }
    return NULL;
}

bool LinkedList::replace(node *myNode, int newData) {
    if(!myNode) //If NULL return false -> to use search() as a parameter.
        return false;
    myNode->setData(newData);
    return true;
}

bool LinkedList::replace(int myData, int newData) {
    node *ptr = begin();
    while (ptr != end()) {
        if (ptr->data == myData){
            ptr->data = newData;
            return true;
        }
        ptr = ptr->getNxt();
    }
    return false;
}

bool LinkedList::replaceAll(int myData, int newData) {
    node *ptr = begin();
    bool flag = false;
    while (ptr != end()) {
        if (ptr->data == myData){
            ptr->data = newData;
            flag = true;
        }
        ptr = ptr->getNxt();
    }
    return flag;
}

bool LinkedList::deleteX(node *myNode) {
    myNode->getPrv()->setNxt( myNode->getNxt() );
    myNode->getNxt()->setPrv( myNode->getPrv() );
    delete myNode;
}

bool LinkedList::deleteX(int myData) {
    node* ptr = begin();
    node* myNode;
    while(ptr != end())
    {
        if (ptr->getData() == myData) {
            myNode = ptr;
            myNode->getPrv()->setNxt( myNode->getNxt() );
            myNode->getNxt()->setPrv( myNode->getPrv() );
            ptr = ptr->getNxt();
            delete myNode;
            return true;
        }
        else
            ptr = ptr->getNxt();

    }
    return false;
}

bool LinkedList::deleteAllX(int myData) {
    node* ptr = begin();
    node* myNode; bool flag = false;
    while(ptr != end())
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