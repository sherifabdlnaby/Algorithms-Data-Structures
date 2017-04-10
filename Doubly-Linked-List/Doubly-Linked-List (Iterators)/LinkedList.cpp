//
// Created by Sherif on 2/4/2017.
//
#include <iostream>
#include "LinkedList.h"
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

LinkedList::LinkedList(int myData, int size) {
    LinkedList::size = 0;
    head = new node(0,NULL,NULL);
    tail = new node(0,NULL,head);
    head->setNxt(tail);
    for (int i = 0; i < size; ++i) {
        push_back(myData);
    }
}

LinkedList::~LinkedList() {
    node* itr = head;
    node* toDelete;
    while(itr)
    {
        toDelete = itr;         //hold current position.
        itr = itr->getNxt();    //iterate...
        delete toDelete;        //delete current position.
    }
}

node *LinkedList::beginNode() const {
    return head->getNxt();
}

node *LinkedList::endNode() const {
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
    node* tmp = new node(myData, beginNode(),head);
    beginNode()->setPrv(tmp);
    head->setNxt(tmp);
    size++;
    return 0;
}

bool LinkedList::pop_back() {
    if(beginNode() == endNode())
        return false; //Linked-List is empty;
    node* toDelete = tail->getPrv();
    toDelete->getPrv()->setNxt(tail);
    tail->setPrv(toDelete->getPrv());
    delete toDelete;
    size--;
    return true;
}

bool LinkedList::pop_front() {
    if(beginNode() == endNode())
        return false; //Linked-List is empty;
    node* toDelete = beginNode();
    toDelete->getNxt()->setPrv( head );
    head->setNxt(toDelete->getNxt());
    delete toDelete;
    size--;
    return true;
}

bool LinkedList::insert_afterN(int newData, node *myNode){
    if(!myNode) //if NULL is passed, return false;
        return false;
    node* tmp = new node(newData,myNode->getNxt(),myNode);
    myNode->getNxt()->setPrv(tmp);
    myNode->setNxt(tmp);
    size++;
    return true;
}

bool LinkedList::insertN(int newData, node *myNode) { //INSERT
    if(!myNode) //if NULL is passed, return false (To use search() int the parameters;
        return false;
    node* tmp = new node(newData, myNode, myNode->getPrv());
    myNode->getPrv()->setNxt(tmp);
    myNode->setPrv(tmp);
    return false;
}

void LinkedList::print() {
    if(beginNode() == endNode()) {
        cout << "->Empty" << endl;
        return;
    }
    node* tmp = beginNode();
    while(tmp != tail){
        cout << tmp->data << " ";
        tmp = tmp->getNxt();
    }
    cout << endl;
    return;
}

node* LinkedList::searchN(int myData) {
    node* ptr = beginNode();
    while(ptr != endNode()) {
        if (ptr->data == myData) {
            return ptr;
        }
        ptr = ptr->getNxt();
    }
    return NULL;
}

bool LinkedList::replaceN(node *myNode, int newData) {
    if(!myNode) //If NULL return false -> to use search() as a parameter.
        return false;
    myNode->setData(newData);
    return true;
}

bool LinkedList::replace(int myData, int newData) {
    node *ptr = beginNode();
    while (ptr != endNode()) {
        if (ptr->data == myData){
            ptr->data = newData;
            return true;
        }
        ptr = ptr->getNxt();
    }
    return false;
}

bool LinkedList::replaceAll(int myData, int newData) {
    node *ptr = beginNode();
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

bool LinkedList::deleteN(node *myNode) {
    myNode->getPrv()->setNxt( myNode->getNxt() );
    myNode->getNxt()->setPrv( myNode->getPrv() );
    delete myNode;
}

bool LinkedList::deleteX(int myData) {
    node* ptr = beginNode();
    node* myNode;
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

bool LinkedList::deleteAllX(int myData) {
    node* ptr = beginNode();
    node* myNode; bool flag = false;
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

LinkedList::iterator LinkedList::begin(){
    return beginNode();
}

LinkedList::iterator LinkedList::end(){
    return endNode();
}

LinkedList::iterator LinkedList::search(int myData) {
    iterator ptr = beginNode();
    while(ptr != end()) {
        if (*ptr == myData) {
            return ptr;
        }
        ptr++;
    }
    return endNode();
}

bool LinkedList::insert_after(int newData, LinkedList::iterator myNode) {
    if(myNode == end())
        return false;
    node* tmp = new node(newData,myNode->getNxt(),myNode.address());
    myNode->getNxt()->setPrv(tmp);
    myNode->setNxt(tmp);
    size++;
    return true;
}

bool LinkedList::insert(int newData, LinkedList::iterator myNode) {
    node* tmp = new node(newData, myNode.address(), myNode->getPrv());
    myNode->getPrv()->setNxt(tmp);
    myNode->setPrv(tmp);
    return false;
}

bool LinkedList::replace(LinkedList::iterator myNode, int newData) {
    if(myNode == end())
        return false;
    myNode->setData(newData);
    return true;
}

bool LinkedList::deleteX(LinkedList::iterator myNode) {
    if(myNode == endNode())
        return false;
    myNode->getPrv()->setNxt( myNode->getNxt() );
    myNode->getNxt()->setPrv( myNode->getPrv() );
    delete myNode.address();
    return true;
}

LinkedList::iterator LinkedList::erase(LinkedList::iterator myNode) {
    if(myNode == end())
        return end();
    myNode->getPrv()->setNxt( myNode->getNxt() );
    myNode->getNxt()->setPrv( myNode->getPrv() );
    delete myNode++.address();
    if(myNode == end())
        throw 404; ///Why ?! TODO
    return myNode;
}