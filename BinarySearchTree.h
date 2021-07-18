/*
* Title: Binary Search Trees
* Author: Beste Guney
* ID: 21901631
* Section: 1
* Assignment: 2
* Description: This is the header file for BST
*/
#include "Queue.h"
class BinarySearchTree{
public:
    //constructors
    BinarySearchTree();

    //destructor
    ~BinarySearchTree();

    //methods
    bool isEmpty();
    int getHeight();
    int getNumberOfNodes();
    bool add(const int newEntry);
    bool remove(const int anEntry);
    bool contains(const int anEntry);
    void preorderTraverse();
    void inorderTraverse();
    void postorderTraverse();
    void levelorderTraverse();
    int span(const int a, const int b);
    void mirror();

    //extra function definitions
    bool deleteItem(const int value, BinaryNode*& cur);
    void deleteNode(BinaryNode*& cur);
    int recursiveHeight(BinaryNode* cur);
    void insertRecursive(const int& value, BinaryNode*& cur);
    void inorder(BinaryNode*);
    void preOrder(BinaryNode*);
    void postOrder(BinaryNode*);
    void mirrorRecursive(BinaryNode* cur);
    int spanRecursive(BinaryNode* cur, const int a, const int b);

private:
    //properties
    BinaryNode* root;
    int numberOfNodes;
};
