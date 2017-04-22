//
// Created by Sherif on 4/21/2017.
//

#include "AVL.h"
#include <iostream>

///Node-Functions...

node::node() {
    leftChild = rightChild = NULL;
}

node::node(int data, node *rightChild, node *leftChild) : data(data),
                                                          leftChild(leftChild),
                                                          rightChild(rightChild) {
    height = 1;
}

void node::setHeight(int height) {
    node::height = height;
}

void node::setLeftChild(node *leftChild) {
    node::leftChild = leftChild;
}

void node::setRightChild(node *rightChild) {
    node::rightChild = rightChild;
}

int node::getData() const {
    return data;
}

node *node::getLeftChild() const {
    return leftChild;
}

node *node::getRightChild() const {
    return rightChild;
}

node *node::getPredecessor() {
    node *iterator = leftChild;
    while (iterator->rightChild)
        iterator = iterator->rightChild;
    return iterator;
}

node *node::getSuccessor() {
    node *iterator = rightChild;
    while (iterator->leftChild)
        iterator = iterator->leftChild;
    return iterator;
}

int node::getChildMaxHeight() const {
    return std::max(leftChild ? leftChild->height : 0, rightChild ? rightChild->height : 0);
}

int node::getBalance() const {
    return (leftChild ? leftChild->height : 0) - (rightChild ? rightChild->height : 0);
}

node *node::rotateLeft() {
    node *tmp = rightChild;
    rightChild = tmp->leftChild;
    tmp->leftChild = this;

    ///Update heights
    this->height = getChildMaxHeight() + 1;
    tmp->height = getChildMaxHeight() + 1;

    return tmp; //To be assigned to parent on return.
}

node *node::rotateRight() {
    node *tmp = leftChild;
    leftChild = tmp->rightChild;
    tmp->rightChild = this;

    ///Update heights
    this->height = getChildMaxHeight() + 1;
    tmp->height = getChildMaxHeight() + 1;

    return tmp; //To be assigned to parent on return.
}

///AVL-Functions...

AVL::AVL() {
    root = NULL;
}

int AVL::min() {
    if (root == NULL) //empty tree, cannot get max.
        throw 6800;
    //Iterate to the MAX element.
    node *iterator = root;
    while (iterator->getLeftChild())
        iterator = iterator->getLeftChild();
    return iterator->data;
}

int AVL::max() {
    if (root == NULL) //empty tree, cannot get max.
        throw 6800;
    //Iterate to the MIN element.
    node *iterator = root;
    while (iterator->getRightChild())
        iterator = iterator->getRightChild();
    return iterator->data;
}

void AVL::insert(int data) {
    if (root == NULL)       //in-case list is empty.
        root = new node(data, NULL, NULL);
    else
        root = insertRec(data, root);   //Recursive
    return;
}

void AVL::erase(int data) {
    root = eraseRec(data, root);    //Recursively Delete
}

void AVL::print() {
    std::cout << "BST(Sorted order): ";
    recursivePrint(root);
    std::cout << "\n";
}

void AVL::recursivePrint(node *parent) {
    if (parent == NULL)
        return;
    recursivePrint(parent->getLeftChild());
    std::cout << parent->data << " ";
    recursivePrint(parent->getRightChild());
}

node *AVL::search(int data) {
    node *iterator = root;
    while (iterator) {
        if (iterator->data == data)
            return iterator;
        else if (iterator->data < data)
            iterator = iterator->getRightChild();
        else
            iterator = iterator->getLeftChild();
    }
    return NULL;
}

node *AVL::getSuccessor(int data) {
    return search(data)->getSuccessor();
}

node *AVL::getPredecessor(int data) {
    return search(data)->getPredecessor();
}

node *AVL::insertRec(int data, node *parent) {
    //NULL ? Create new node here and return address to the recursiveCall to link it.
    if (parent == NULL)
        return new node(data, NULL, NULL);
    if (parent->data < data)
        parent->setRightChild(insertRec(data, parent->getRightChild()));
    else
        parent->setLeftChild(insertRec(data, parent->getLeftChild()));

    //////Update and Balance after *each* recursive call//////

    parent->setHeight(parent->getChildMaxHeight() + 1); //Update height at each call (Up to the initial root).
    int balance = parent->getBalance();

    //Updating root or returning different root, link it's parent with it according to the recursive calls.

    ///Left-Left
    if (balance > 1 && parent->getLeftChild()->data > data)
        return parent->rotateRight(); //Will return the new root(and assigned by the recursive call)

    ///Left-Right
    if (balance > 1 && parent->getLeftChild()->data < data) {
        parent->setLeftChild(parent->getLeftChild()->rotateLeft());
        return parent->rotateRight();
    }

    ///Right-Right
    if (balance < -1 && parent->getRightChild()->data < data)
        return parent->rotateLeft();

    ///Right-Left
    if (balance < -1 && parent->getRightChild()->data > data) {
        parent->setRightChild(parent->getRightChild()->rotateRight());
        return parent->rotateLeft();
    }
    //////////////////////////////////////////////////////////

    return parent; //If root was unchanged.
}

node *AVL::eraseRec(int data, node *parent) {

    ///Recursive search + updating..
    if (parent == NULL)                                                     //Reached NULL, nothing to be deleted;
        return parent;
    if (data < parent->data)
        parent->setLeftChild(eraseRec(data,
                                      parent->getLeftChild()));             //Search on the left route and update it if there are changes
    else if (data > parent->data)
        parent->setRightChild(eraseRec(data, parent->getRightChild()));     //Search on the right rout and update it.
    else {
        node *leftChild = parent->getLeftChild();
        node *rightChild = parent->getRightChild();
        if (leftChild == NULL && rightChild == NULL) {                      //Case #1: Has no children.
            node *tmp = parent;
            parent = NULL;
            delete tmp;
        } else if (leftChild == NULL || rightChild == NULL) {               //Case #2: Has only one child.
            node *tmp = parent;
            parent = leftChild ? leftChild : rightChild;                    //Select the non-NULL child.
            delete tmp;
        } else {                                                            //Case #3: Has two children.
            node *successor = parent->getSuccessor();
            parent->data = successor->data;
            parent->setRightChild(
                    eraseRec(successor->getData(),
                             parent->getRightChild()));                     //recursive call (Case #1 || Case #2 is guaranteed)
        }
    }

    if (parent == NULL)   //in-case root = NULL after deletion(if this is the recursive call we actually deleted in.)
        return parent;

    ///Update + Balance nodes at each recursive call (before return...)
    parent->setHeight(parent->getChildMaxHeight() + 1);   //Update current node Height.
    int balance = parent->getChildMaxHeight();            //Root balance score.
    int rightBalance = parent->getRightChild() ? parent->getRightChild()->getBalance(): 0;  //if right is NULL balance = 0; else calculate it.
    int leftBalance  = parent->getLeftChild()  ? parent->getLeftChild()->getBalance() : 0;  //^--left ---------------------------------------^

    //Updating root or returning different root, link it's parent with it according to the recursive calls
    //Will return the new root(and assigned by the recursive call)

    ///left-left
    if (balance > 1 && leftBalance > 0)
        return parent->rotateRight();
    ///left-right
    if (balance > 1 && leftBalance > 0) {
        parent->setLeftChild(parent->getLeftChild()->rotateLeft());
        return parent->rotateRight();
    }
    ///right-right
    if (balance < -1 && rightBalance > 0)
        return parent->rotateLeft();
    ///right-left
    if (balance < -1 && rightBalance > 0) {
        parent->setRightChild(parent->getRightChild()->rotateRight());
        return parent->rotateLeft();
    }

    //The unchanged root(If no deletion or Balance happened, return original root to the recursive calls)
    return parent;
}


