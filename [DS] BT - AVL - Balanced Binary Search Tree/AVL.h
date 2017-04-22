//
// Created by Sherif on 4/21/2017.
//

#ifndef BST_BST_H
#define BST_BST_H
class node {
    int height;
    node* leftChild;
    node* rightChild;
public:
    int data;
    node();
    node(int data, node *rightChild, node *leftChild);
    int getData() const;                    //Self-Explanatory
    int getChildMaxHeight() const;          //Return max height from both children and handles NULL children.
    int getBalance() const;                 //Return the difference between left child and right child height + NULL handle.
    node* getLeftChild() const;             //Self-Explanatory
    node* getRightChild() const;            //Self-Explanatory
    node* getPredecessor();                 //Return node* to the next smaller element.
    node* getSuccessor();                   //Return node* to the next greater element.
    void setHeight(int height);             //Return node* to the next smaller element.
    void setLeftChild(node *leftChild);     //Self-Explanatory
    void setRightChild(node *rightChild);   //Self-Explanatory
    node* rotateLeft();                     //Rotate Left and return node* of the new root(the root we rotated around)
    node *rotateRight();                    //Rotate Right ^---------------------------------------------------------^
};

class AVL {
private:
    node* root;
    node* insertRec(int data, node *parent);  //Recursive(Insert node* and return new root address(or unchanged in mid-recursive calls).
    node* eraseRec(int data, node *parent);   //Recursive(Erase node* with data = parameter, and return new root after deletion).
    void recursivePrint(node* parent);        //Recursively print all children of given node in sorted order.
public:
    AVL();
    int max();                              //Return the maximum element in the Tree.
    int min();                              //^..........minimum....................^
    void insert(int data);                  //Insert data and call the recursiveInsertions #Wrapper
    void erase(int data);                   //Erase  data and call the recursiveErase      #Wrapper
    node* search(int data);                 //Search for a node with the given data, return NULL if unsuccessful.
    node* getSuccessor(int data);           //^...................................., and then find the next smaller node.
    node* getPredecessor(int data);         //^...................................., and then find the next greater node.
    void print();                           //Print The tree in sorted order, calls recursivePrint from the root. #Wrapper

};


#endif //BST_BST_H
