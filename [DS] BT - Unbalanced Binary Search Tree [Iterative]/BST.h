//
// Created by Sherif on 4/21/2017.
//

#ifndef BST_BST_H
#define BST_BST_H
class node {
    node* parent;
    node* leftChild;
    node* rightChild;
public:
    int data;
    node();
    node(int data, node *parent, node *rightChild, node *leftChild);
    node* getParent() const;
    node* getLeftChild() const;
    node* getRightChild() const;
    node* getPredecessor();
    node* getSuccessor();
    void setParent(node *parent);
    void setLeftChild(node *leftChild);
    void setRightChild(node *rightChild);
};

class BST {
private:
    node* root;
    void recursivePrint(node* data);
public:
    BST();
    void insert(int data);
    void erase(node* toDelete);
    node* search(int data);
    int max();
    int min();
    node* getSuccessor(int data);  //Wrapper function.
    node* getPredecessor(int data);//Wrapper function.
    void print(); //wrapper function
};


#endif //BST_BST_H
