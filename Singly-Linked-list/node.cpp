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
    head = new node(0,NULL);
}

int LinkedList::addBack(int x) {
    node* newNode = new node(x,NULL);
    node* tmp = head;
    while (tmp->getNxt())
    {
        tmp = tmp->getNxt();
    }
    tmp->setNxt(newNode);
    size++;
    return 0;
}

int LinkedList::addFirst(int x) {
    node* tmp = new node(x,begin());
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

node* LinkedList::search(int x) {
    node* ptr = begin();
    while(ptr) {
        if (ptr->data == x) {
            return ptr;
        }
        ptr = ptr->getNxt();
    }
    return NULL;
}

bool LinkedList::replace(int a, node *x) {
    if(x) {
        x->setData(a);
        return true;
    }
    else return false;
}

bool LinkedList::replace(int a, int x) {
    node *ptr = head;
    while (ptr) {
        if (ptr->data == x){
            ptr->data=a;
            return  true;
        }
        ptr = ptr->getNxt();
    }
    return false;
}

bool LinkedList::replaceAll(int a, int x) {
    node *ptr = head;
    bool ret = false;
    while (ptr) {
        if (ptr->data == x){
            ptr->data = a;
            ret = true;
        }
        ptr = ptr->getNxt();
    }
    return ret;
}

bool LinkedList::deleteX(node *x) {
    node* tmp = head;
    if(!x)return false;
    while(tmp)
    {
        if(tmp->getNxt()==x)
        {
            tmp->setNxt(x->getNxt());
            delete x;
            size--;
            return true;
        }
        tmp = tmp->getNxt();
    }
    return false;
}

bool LinkedList::deleteX(int x) {
    node* tmp = head;
    node* del;
    while(tmp)
    {
        if (tmp->getNxt()) //Check IT is not NULL.
            if (tmp->getNxt()->data == x) {
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

bool LinkedList::deleteAllX(int x) {
    node* tmp = begin();
    node* before = head;
    node* toDelete;
    while(tmp)
    {
        if(tmp->getData()==x)
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

bool LinkedList::addAfter(int a, node *x){
    if(!x)
        return false;
    node* tmp = new node(a,x->getNxt());
    x->setNxt(tmp);
    size++;
    return true;
}

bool LinkedList::addBefore(int a, node *x) {
    node* tmp = head;
    if(!x)return false;
    while(tmp)
    {
        if(tmp->getNxt()==x)
        {
            node* add = new node(a,x);
            tmp->setNxt(add);
            size++;
            return true;
        }
        tmp = tmp->getNxt();
    }
    return false;
}

bool LinkedList::popback() {
    if(head->getNxt() == NULL)
        return false;
    node* tmp = head;
    while(tmp->getNxt()->getNxt())
        tmp = tmp->getNxt();

    delete tmp->getNxt();
    tmp->setNxt(NULL);
    size--;
    return true;
}

bool LinkedList::popfront() {
    if(head->getNxt() == NULL) //Empty List case.
        return false;

    node* tmp = head->getNxt()->getNxt(); //The new first element in the list.
    delete head->getNxt();
    head->setNxt(tmp);
    size--;
    return true;
}







