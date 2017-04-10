//
// Created by Sherif on 2/4/2017.
//

#include "node.h"
#include <iostream>
using namespace std;
node::node(int data=0, node *nxt) : data(data), nxt(nxt) {}

node::~node() {


}

node *node::getNxt() const {
    return nxt;
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

LinkedList::LinkedList() {
    size = 0;
    head = new node(0,NULL); //Header value = 0(Won't use it anyway), Nxt = Null (Empty List).
}

LinkedList::~LinkedList() {
    node* itr = head;
    node* toDelete;
    while(itr)
    {
        toDelete = itr;		 //hold current position.
        itr = itr->getNxt(); //iterate...
        delete toDelete;	 //delete current position.
    }
}

int LinkedList::addBack(int myData) {
    node* newNode = new node(myData,NULL);
    node* tmp = head;
    while (tmp->getNxt())
    {
        tmp = tmp->getNxt();
    }
    tmp->setNxt(newNode);
    size++;
    return 0;
}

int LinkedList::addFirst(int myData) {
    node* tmp = new node(myData,begin());
    head->setNxt(tmp);
    size++;
    return 0;
}

void LinkedList::print() {
    node* tmp = begin();
    while(tmp)
    {
        cout << tmp->data << endl;
        tmp = tmp->getNxt();
    }
    return;
}

node *LinkedList::begin() const {
    return head->getNxt();
}

node* LinkedList::search(int myData) {
    node* ptr = begin();
    while(ptr) {
        if (ptr->data == myData) {
            return ptr;
        }
        ptr = ptr->getNxt();
    }
    return NULL;
}

bool LinkedList::replace(int newData, node *myNode) {
    if(myNode) //If not NULL.
    {
        myNode->setData(newData);
        return true;
    }
    else return false;
}

bool LinkedList::replace(int newData, int myData) {
    node *ptr = head;
    while (ptr) {
        if (ptr->data == myData){
            ptr->data=newData;
            return  true;
        }
        ptr = ptr->getNxt();
    }
    return false;
}

bool LinkedList::replaceAll(int newData, int myData) {
    node *ptr = head;
    bool ret = false;
    while (ptr) {
        if (ptr->data == myData){
            ptr->data = newData;
            ret = true;
        }
        ptr = ptr->getNxt();
    }
    return ret;
}

bool LinkedList::deleteX(node *myNode) {
    node* tmp = head;
    if(!myNode)
        return false;
    while(tmp)
    {
        if(tmp->getNxt()==myNode)
        {
            tmp->setNxt(myNode->getNxt());
            delete myNode;
            size--;
            return true;
        }
        tmp = tmp->getNxt();
    }
    return false;
}

bool LinkedList::deleteX(int myData) {
    node* tmp = head;
    node* del;
    while(tmp->getNxt())
    {
        if (tmp->getNxt()->data == myData) {
            del = tmp->getNxt();
            tmp->setNxt(tmp->getNxt()->getNxt());
            delete del;
            size--;
            return true;
        }
        tmp = tmp->getNxt();
    }
    return false;
}

bool LinkedList::deleteAllX(int myData) {
    node* tmp = begin();
    node* before = head;
    node* toDelete; //A pointer to hold the to be deleted pointer.
    while(tmp)
    {
        if(tmp->getData()==myData)
        {
            before->setNxt(tmp->getNxt());
            toDelete = tmp;
            tmp = tmp->getNxt();
            delete toDelete;
            size--;
        }
        else
        {
            before = tmp;
            tmp = tmp->getNxt();
        }
    }
    return true;
}

bool LinkedList::addAfter(int newData, node *myNode){
    if(!myNode) //if NULL is passed, return false;
        return false;
    node* tmp = new node(newData,myNode->getNxt());
    myNode->setNxt(tmp);
    size++;
    return true;
}

bool LinkedList::addBefore(int newData, node *myNode) {
    if(!myNode) //if NULL is passed, return false;
        return false;
    node* tmp = head;
    while(tmp)
    {
        if(tmp->getNxt()==myNode)
        {
            node* add = new node(newData,myNode);
            tmp->setNxt(add);
            size++;
            return true;
        }
        tmp = tmp->getNxt();
    }
    return false;
}

bool LinkedList::popback() {
    if(!begin()) //If LinkedList is empty, (begin == NULL).
        return false;
    node* tmp = head;
    while(tmp->getNxt()->getNxt()) //Iterate to the before-end cell.
        tmp = tmp->getNxt();
    delete tmp->getNxt();
    tmp->setNxt(NULL);
    size--;
    return true;
}

bool LinkedList::popfront() {
    if(!begin()) //If LinkedList is empty, (begin == NULL).
        return false;
    node* tmp = begin()->getNxt(); //The new first element in the list.
    delete begin();
    head->setNxt(tmp);
    size--;
    return true;
}







