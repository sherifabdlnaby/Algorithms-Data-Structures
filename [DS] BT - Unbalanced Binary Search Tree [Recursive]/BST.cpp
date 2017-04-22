//
// Created by Sherif on 4/21/2017.
//

#include "BST.h"
#include <iostream>

node::node(int data, node *rightChild, node *leftChild) : data(data),
                                                                        leftChild(leftChild), rightChild(rightChild) {}
int node::getData() const {
    return data;
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
    leftChild = rightChild = NULL;
}

node* BST::insertRec(int data, node *root) {
    if(root == NULL)
        return new node(data,NULL,NULL);
    if(root->data < data)
        root->setRightChild(insertRec(data, root->getRightChild()) );
    else
        root->setLeftChild(insertRec(data, root->getLeftChild()) );
    return root;
}

void BST::insert(int data) {
    if(BST::root == NULL)       //in-case list is empty.
        BST::root = new node(data, NULL, NULL);
    else
        insertRec(data,root);   //Recursive
    return;
}

node *BST::eraseRec(int data, node *root) {

    /*Recursive search + updating*/
    if (root == NULL)                                                   //Reached NULL, nothing to be deleted;
        return root;
    if (data < root->data)
        root->setLeftChild(eraseRec(data, root->getLeftChild()));       //Search on the left route and update it if there are changes
    else if (data > root->data)
        root->setRightChild(eraseRec(data, root->getRightChild()));     //Search on the right rout and update it.
    else{
        node *leftChild = root->getLeftChild();
        node *rightChild = root->getRightChild();
        if (leftChild == NULL && rightChild == NULL) {                  //Case #1: Has no children.
            node *tmp = root;
            root = NULL;
            delete tmp;
        } else if (leftChild == NULL || rightChild == NULL) {           //Case #2: Has only one child.
            node *tmp = root;
            root = leftChild ? leftChild : rightChild;                  //Select the non-NULL child.
            delete tmp;
        } else {                                                        //Case #3: Has two children.
            node *successor = root->getSuccessor();
            root->data = successor->data;
            root->setRightChild(
                    eraseRec(successor->getData(), root->getRightChild())); //recursive call (Case #1 || Case #2 is guaranteed)
        }
    }
    return root;
}

void BST::erase(int data) {
    root = eraseRec(data, root);    //Recursively Delete
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

