/*
* Title: Binary Search Trees
* Author: Beste Guney
* ID: 21901631
* Section: 1
* Assignment: 2
* Description: This is the header file for BinaryNode
*/


typedef int NodeItem; //node items are integers

class BinaryNode{
private:
    //constructors
    BinaryNode();
    BinaryNode(const NodeItem&);

    //destructor
    ~BinaryNode();

    //data members
    NodeItem item;
    BinaryNode* leftChildPtr;
    BinaryNode* rightChildPtr;

    //methods
    NodeItem getItem();
    void setItem(NodeItem value);

    //in order to make access by binary tree it will be declared as a friend
    friend class BinarySearchTree;

};
