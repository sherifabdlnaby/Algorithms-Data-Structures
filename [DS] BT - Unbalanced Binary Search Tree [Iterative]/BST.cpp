//
// Created by Sherif on 4/21/2017.
//

#include "BST.h"
#include <iostream>

node::node(int data, node *parent, node *rightChild, node *leftChild) : data(data), parent(parent),
                                                                        leftChild(leftChild), rightChild(rightChild) {}

node *node::getParent() const {
    return parent;
}

void node::setParent(node *parent) {
    node::parent = parent;
}

node *node::getLeftChild() const {
    return leftChild;
}

void node::setLeftChild(node *leftChild) {
    node::leftChild = leftChild;
}

node *node::getRightChild() const {
    return rightChild;
}

void node::setRightChild(node *rightChild) {
    node::rightChild = rightChild;
}

node *node::getPredecessor() {
    node* iterator = leftChild;
    while (iterator->rightChild)
        iterator = iterator->rightChild;
    return iterator;
}

node *node::getSuccessor() {
    node* iterator = rightChild;
    while (iterator->leftChild)
        iterator = iterator->leftChild;
    return iterator;
}

node::node() {
    parent = leftChild = rightChild = NULL;
}


void BST::insert(int data) {
    node* iterator = root;
    node* previous = NULL;
    while (iterator)
    {
        previous = iterator;
        if(iterator->data < data)
            iterator = iterator->getRightChild();
        else
            iterator = iterator->getLeftChild();
    }
    iterator = new node(data,previous,NULL,NULL);
    //UPDATE root if it was the first insert.
    if(previous == NULL)
        root = iterator;
    else//UPDATE previous
    {
        if(previous->data < data)
            previous->setRightChild(iterator);
        else
            previous->setLeftChild(iterator);
    }

}

void BST::erase(node *toDelete) {

    if(toDelete == NULL) //in-case search() returned NULL;
        return;

    node* parent = toDelete->getParent();
    node* leftChild = toDelete->getLeftChild();
    node* rightChild = toDelete->getRightChild();

    //handling if we're deleting the root. (so parent is NULL)
    if(toDelete == root)
        parent = new node(); //Give a tmp node for parent(to avoid rewriting redundant code)

    if(leftChild == NULL && rightChild == NULL )
    {
        if(parent == NULL) //means we're deleting the root with no other nodes(empty tree)
            ; //do nothing
        else if(parent->getLeftChild() == toDelete)
            parent->setLeftChild(NULL);
        else
            parent->setRightChild(NULL);
    }
    else if(leftChild != NULL && rightChild == NULL )
    {
        if(parent->getLeftChild() == toDelete)
            parent->setLeftChild(leftChild);
        else
            parent->setRightChild(leftChild);
        leftChild->setParent(parent);
    }
    else if(leftChild == NULL && rightChild != NULL )
    {
        if(parent->getLeftChild() == toDelete)
            parent->setLeftChild(rightChild);
        else
            parent->setRightChild(rightChild);
        rightChild->setParent(parent);
    }
    else
    {
        node* successor = toDelete->getSuccessor();
        toDelete->data = successor->data;
        erase(successor); //one recursive call (Case #1 is guaranteed)
        toDelete = NULL;  //We no longer want to delete it. (to avoid deleting the node at the code termination below)
    }

    if(toDelete == root)
    {
        if(parent->getLeftChild())
            root = parent->getLeftChild();
        else
            root = parent->getRightChild();

        if(root)
            root->setParent(NULL);

        delete parent;
    }

    delete toDelete;
}

BST::BST() {
    root = NULL;
}

node *BST::search(int data) {
    node* iterator = root;
    while (iterator)
    {
        if(iterator->data == data)
            return iterator;
        else if(iterator->data < data)
            iterator = iterator->getRightChild();
        else
            iterator = iterator->getLeftChild();
    }
    return NULL;
}

int BST::min() {
    if(root == NULL) //empty tree, cannot get max.
        throw 6800;
    //Iterate to the MAX element.
    node* iterator = root;
    while (iterator->getLeftChild())
        iterator = iterator->getLeftChild();
    return iterator->data;
}

int BST::max() {
    if(root == NULL) //empty tree, cannot get max.
        throw 6800;
    //Iterate to the MIN element.
    node* iterator = root;
    while (iterator->getRightChild())
        iterator = iterator->getRightChild();
    return iterator->data;
}

node* BST::getSuccessor(int data) {
    return search(data)->getSuccessor();
}
node* BST::getPredecessor(int data){
    return search(data)->getPredecessor();
}

void BST::print() {
    std::cout << "BST(Sorted order): ";
    recursivePrint(root);
    std::cout << "\n";
}

void BST::recursivePrint(node *data) {
    if(data == NULL)
        return;
    recursivePrint(data->getLeftChild());
    std::cout << data->data << " ";
    recursivePrint(data->getRightChild());
}
