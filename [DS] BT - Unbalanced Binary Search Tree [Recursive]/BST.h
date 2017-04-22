//
// Created by Sherif on 4/21/2017.
//

#ifndef BST_BST_H
#define BST_BST_H
class node {
    node* leftChild;
    node* rightChild;
public:
    int data;
    node();
    node(int data, node *rightChild, node *leftChild);
    int getData() const;
    node* getLeftChild() const;
    node* getRightChild() const;
    node* getPredecessor();
    node* getSuccessor();
    void setLeftChild(node *leftChild);
    void setRightChild(node *rightChild);
};

class BST {
private:
    void recursivePrint(node* data);
    node* insertRec(int data, node *root);
    node* eraseRec(int data, node *root);
public:
    BST();
    node* root;
    node* search(int data);
    int max();
    int min();
    //Wrapper Functions//
    void insert(int data);
    void erase(int data);
    node* getSuccessor(int data);
    node* getPredecessor(int data);
    //.................//
    void print(); //wrapper function
};


#endif //BST_BST_H
