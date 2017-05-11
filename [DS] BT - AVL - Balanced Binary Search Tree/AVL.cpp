//
// Created by Sherif on 4/21/2017.
//

#include "AVL.h"


///AVL-Functions...

AVL::AVL() {
    root = NULL;
}

int AVL::min() {
    if (root == NULL) //empty tree, cannot get max.
        throw 6800;
    //Iterate to the MAX element.
    node *iterator = root;
    while (iterator->leftChild)
        iterator = iterator->leftChild;
    return iterator->data;
}

int AVL::max() {
    if (root == NULL) //empty tree, cannot get max.
        throw 6800;
    //Iterate to the MIN element.
    node *iterator = root;
    while (iterator->rightChild)
        iterator = iterator->rightChild;
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

void AVL::printInOrder() {
    std::cout << "AVL(Sorted order): ";
    recursivePrint(root);
    std::cout << "\n";
}

void AVL::recursivePrint(node *parent) {
    if (parent == NULL)
        return;
    recursivePrint(parent->leftChild);
    std::cout << parent->data << " ";
    recursivePrint(parent->rightChild);
}

bool AVL::search(int data) {
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

AVL::node *AVL::insertRec(int data, node *parent) {
    //NULL ? Create new node here and return address to the recursiveCall to link it.
    if (parent == NULL)
        return new node(data, NULL, NULL);
    if (parent->data < data)
        parent->rightChild = insertRec(data, parent->rightChild);
    else
        parent->leftChild  = insertRec(data, parent->leftChild);

    //////Update and Balance after *each* recursive call//////

    parent->height = parent->getChildMaxHeight() + 1; //Update height at each call (Up to the initial root).
    int balance = parent->getBalance();

    //Updating root or returning different root, link it's parent with it according to the recursive calls.

    ///Left-Left
    if (balance > 1 && parent->leftChild->data > data)
        return parent->rotateRight(); //Will return the new root(and assigned to parent by the recursive call)

    ///Left-Right
    if (balance > 1 && parent->leftChild->data < data) {
        parent->leftChild = parent->leftChild->rotateLeft();
        return parent->rotateRight();
    }

    ///Right-Right
    if (balance < -1 && parent->rightChild->data < data)
        return parent->rotateLeft();

    ///Right-Left
    if (balance < -1 && parent->rightChild->data > data) {
        parent->rightChild = parent->rightChild->rotateRight();
        return parent->rotateLeft();
    }
    //////////////////////////////////////////////////////////

    return parent; //If root was unchanged.
}

AVL::node *AVL::eraseRec(int data, node *parent) {

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

    if (parent == NULL)   //in-case root = NULL after deletion(this is the recursive call we actually deleted the target in.)
        return parent;

    ///Update + Balance nodes at each recursive call (before return...)
    parent->height   = parent->getChildMaxHeight() + 1;        //Update current node Height.
    int balance      = parent->getBalance();                   //Root balance score.
    int rightBalance = parent->rightChild ? parent->rightChild->getBalance(): 0;  //if right is NULL balance = 0; else calculate it.
    int leftBalance  = parent->leftChild  ? parent->leftChild->getBalance() : 0;  //^--left ---------------------------------------^

    //Updating root or returning a different root, link it's parent with it according to the recursive calls
    //Will return the new root(and assigned by the recursive call)

    ///left-left
    if (balance > 1 && leftBalance >= 0)
        return parent->rotateRight();
    ///left-right
    if (balance > 1 && leftBalance < 0) {
        parent->leftChild = parent->leftChild->rotateLeft();
        return parent->rotateRight();
    }
    ///right-right
    if (balance < -1 && rightBalance <= 0)
        return parent->rotateLeft();
    ///right-left
    if (balance < -1 && rightBalance > 0) {
        parent->rightChild = parent->rightChild->rotateRight();
        return parent->rotateLeft();
    }

    //The unchanged root(If no deletion or Balance happened, return original root to the recursive calls)
    return parent;
}


///Node-Functions...
AVL::node::node() {
    leftChild = rightChild = NULL;
}

AVL::node::node(int data, node *rightChild, node *leftChild) : data(data),
                                                               leftChild(leftChild),
                                                               rightChild(rightChild) {
    height = 1;
}

AVL::node *AVL::node::getMinNode() {
    node *iterator = leftChild;
    while (iterator->rightChild)
        iterator = iterator->rightChild;
    return iterator;
}

AVL::node *AVL::node::getMaxNode() {
    node *iterator = rightChild;
    while (iterator->leftChild)
        iterator = iterator->leftChild;
    return iterator;
}

int AVL::node::getChildMaxHeight() const {
    return std::max(leftChild ? leftChild->height : 0, rightChild ? rightChild->height : 0);
}

int AVL::node::getBalance() const {
    return (leftChild ? leftChild->height : 0) - (rightChild ? rightChild->height : 0);
}

AVL::node *AVL::node::rotateLeft() {
    node *tmp = rightChild;
    rightChild = tmp->leftChild;
    tmp->leftChild = this;

    ///Update heights
    this->height = getChildMaxHeight() + 1;
    tmp->height = tmp->getChildMaxHeight() + 1;

    return tmp; //To be assigned to parent on return.
}

AVL::node *AVL::node::rotateRight() {
    node *tmp = leftChild;
    leftChild = tmp->rightChild;
    tmp->rightChild = this;

    ///Update heights
    this->height = getChildMaxHeight() + 1;
    tmp->height = tmp->getChildMaxHeight() + 1;

    return tmp; //To be assigned to parent on return.
}
