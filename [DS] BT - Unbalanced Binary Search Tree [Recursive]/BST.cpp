//
// Created by Sherif on 4/21/2017.
//

#include "BST.h"
///BST-Functions...

BST::BST() {
    root = NULL;
}

int BST::min() {
    if (root == NULL) //empty tree, cannot get max.
        throw 6800;
    //Iterate to the MAX element.
    node *iterator = root;
    while (iterator->leftChild)
        iterator = iterator->leftChild;
    return iterator->data;
}

int BST::max() {
    if (root == NULL) //empty tree, cannot get max.
        throw 6800;
    //Iterate to the MIN element.
    node *iterator = root;
    while (iterator->rightChild)
        iterator = iterator->rightChild;
    return iterator->data;
}

void BST::insert(int data) {
    if (root == NULL)       //in-case list is empty.
        root = new node(data, NULL, NULL);
    else
        root = insertRec(data, root);   //Recursive
    return;
}

void BST::erase(int data) {
    root = eraseRec(data, root);    //Recursively Delete
}

void BST::printInOrder() {
    std::cout << "BST(Sorted order): ";
    recursivePrint(root);
    std::cout << "\n";
}

void BST::recursivePrint(node *parent) {
    if (parent == NULL)
        return;
    recursivePrint(parent->leftChild);
    std::cout << parent->data << " ";
    recursivePrint(parent->rightChild);
}

bool BST::search(int data) {
    node *iterator = root;
    while (iterator) {
        if (iterator->data == data)
            return true;
        else if (iterator->data < data)
            iterator = iterator->rightChild;
        else
            iterator = iterator->leftChild;
    }
    return false;
}

BST::node *BST::insertRec(int data, node *parent) {
    //NULL ? Create new node here and return address to the recursiveCall to link it.
    if (parent == NULL)
        return new node(data, NULL, NULL);
    if (parent->data < data)
        parent->rightChild = insertRec(data, parent->rightChild);
    else
        parent->leftChild  = insertRec(data, parent->leftChild);
    return parent; //If root was unchanged.
}

BST::node *BST::eraseRec(int data, node *parent) {
    ///Recursive search + updating..
    if (parent == NULL)                                                     //Reached NULL, nothing to be deleted;
        return parent;
    if (data < parent->data)
        parent->leftChild  = eraseRec(data, parent->leftChild);             //Search on the left route and update it if there are changes
    else if (data > parent->data)
        parent->rightChild = eraseRec(data, parent->rightChild);            //Search on the right rout and update it.
    else {
        node *leftChild = parent->leftChild;                                //for code simplicity. (could be omitted)
        node *rightChild = parent->rightChild;                               //^-------------------------------------^
        if (leftChild == NULL && rightChild == NULL) {                      //Case #1: Has no children.
            node *tmp = parent;
            parent = NULL;
            delete tmp;
        } else if (leftChild == NULL || rightChild == NULL) {               //Case #2: Has only one child.
            node *tmp = parent;
            parent = leftChild ? leftChild : rightChild;                    //Select the non-NULL child.
            delete tmp;
        } else {                                                            //Case #3: Has two children.
            node *successor = parent->getMaxNode();
            parent->data = successor->data;
            parent->rightChild =  eraseRec(successor->data, rightChild);    //recursive call (Case #1 || Case #2 is guaranteed)
        }
    }
    return parent;
}


///Node-Functions...
BST::node::node() {
    leftChild = rightChild = NULL;
}

BST::node::node(int data, node *rightChild, node *leftChild) : data(data),
                                                               leftChild(leftChild),
                                                               rightChild(rightChild) {
}

BST::node *BST::node::getMinNode() {
    node *iterator = leftChild;
    while (iterator->rightChild)
        iterator = iterator->rightChild;
    return iterator;
}

BST::node *BST::node::getMaxNode() {
    node *iterator = rightChild;
    while (iterator->leftChild)
        iterator = iterator->leftChild;
    return iterator;
}

