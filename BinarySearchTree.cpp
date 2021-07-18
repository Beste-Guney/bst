/*
* Title: Binary Search Trees
* Author: Beste Guney
* ID: 21901631
* Section: 1
* Assignment: 2
* Description: This is the implementation file for BST
*/
#include "BinarySearchTree.h"
#include <iostream>
using namespace std;

BinarySearchTree::BinarySearchTree(){
    root = NULL;
    numberOfNodes = 0;
}
BinarySearchTree::~BinarySearchTree(){
    delete root;
}
bool BinarySearchTree::isEmpty(){
    return root == NULL;
}

bool BinarySearchTree::contains(const int value){
    BinaryNode* cur = root;

    while(cur){
        if(cur->item == value)
            return true;
        else if(value > cur->item)
            cur = cur->rightChildPtr;
        else
            cur = cur->leftChildPtr;
    }
    return false;
}
int BinarySearchTree::getNumberOfNodes(){
    return numberOfNodes;
}
int BinarySearchTree::getHeight(){
    return recursiveHeight(root);
}

int BinarySearchTree::recursiveHeight(BinaryNode* cur){
    if(cur == NULL){
        return 0;
    }
    else{
        if(recursiveHeight(cur->leftChildPtr) > recursiveHeight(cur->rightChildPtr)){
            return 1 + recursiveHeight(cur->leftChildPtr);
        }
        else{
            return 1+ recursiveHeight(cur->rightChildPtr);
        }
    }
}
bool BinarySearchTree::add(const int newEntry){
    if(contains(newEntry))
        return false;

    //after being sure that the value doesn't exist insertion is done
    insertRecursive(newEntry,root);
    numberOfNodes++;
    return true;
}

void BinarySearchTree::insertRecursive(const int& value, BinaryNode*& cur){
    if (cur == NULL){
        //create a new node with value
        cur = new BinaryNode();
        cur->setItem(value);
    }
    else if (value > cur->item){
        insertRecursive(value, cur->rightChildPtr);
    }
    else{
        insertRecursive(value, cur->leftChildPtr);
    }
}

//traversals
void BinarySearchTree::inorderTraverse(){
    inorder(root);
}

void BinarySearchTree::inorder(BinaryNode* cur){
    if(cur != NULL){
        inorder(cur->leftChildPtr);
        cout << cur->item << ", ";
        inorder(cur->rightChildPtr);
    }
}

void BinarySearchTree::preorderTraverse(){
    preOrder(root);
}

void BinarySearchTree::preOrder(BinaryNode* cur){
    if(cur != NULL){
        cout << cur->item << ", ";
        preOrder(cur->leftChildPtr);
        preOrder(cur->rightChildPtr);
    }
}

void BinarySearchTree::postorderTraverse(){
    postOrder(root);
}

void BinarySearchTree::postOrder(BinaryNode* cur){
    if(cur != NULL){
        postOrder(cur->leftChildPtr);
        postOrder(cur->rightChildPtr);
        cout << cur->item << ", ";
    }
}

//removal
bool BinarySearchTree::remove(const int anEntry){
    if(!contains(anEntry))
        return false;
    numberOfNodes--;
    return deleteItem(anEntry,root);
}

bool BinarySearchTree::deleteItem(const int value, BinaryNode*& cur){
    if(root == NULL){
        return false;
    }

    //deciding the location to delete the node
    if(value == cur->item){
        deleteNode(cur);
    }
    else if(value > cur->item){
        deleteItem(value, cur->rightChildPtr);
    }
    else{
        deleteItem(value, cur->leftChildPtr);
    }
}

void BinarySearchTree::deleteNode(BinaryNode*& cur){
    BinaryNode* temp;
    int newValue;

    if(cur->leftChildPtr == NULL && cur->rightChildPtr == NULL){
        delete cur;
        cur = NULL; // to indicate its parents
    }
    else if(cur->rightChildPtr == NULL){//only left child
        temp = cur;
        cur = cur->leftChildPtr;
        delete temp;
    }
    else if(cur->leftChildPtr == NULL){ // only right child
        temp = cur;
        cur = cur->rightChildPtr;
        delete temp;
    }
    else{ //two children
        BinaryNode*& smallest = cur->rightChildPtr;
        while (smallest->leftChildPtr != NULL){
            smallest = smallest->leftChildPtr;
        }
        if (smallest->leftChildPtr == NULL){
            newValue = smallest->item;
            temp = smallest;
            smallest = smallest->rightChildPtr;
            delete temp;
        }
        cur->item = newValue;
    }
}

void BinarySearchTree::levelorderTraverse(){
    //creating a queue to print values
    Queue que;
    BinaryNode* item;
    BinaryNode* cur = root;
    if(isEmpty()){
        return;
    }
    que.enqueue(cur);
    que.getFront(item);
    cout << item->item << ", ";

    while(!que.isEmpty()){
         que.getFront(item);
        if(item->leftChildPtr != NULL){
            cout << item->leftChildPtr->item << ", ";
            que.enqueue(item->leftChildPtr);
        }
        if(item->rightChildPtr != NULL){
            cout << item ->rightChildPtr->item << ", ";
            que.enqueue(item->rightChildPtr);
        }
        que.dequeue();
    }
}

void BinarySearchTree::mirror(){
    if(isEmpty())
        return;
    mirrorRecursive(root);
}

void BinarySearchTree::mirrorRecursive(BinaryNode* cur){
    //base case
    if(cur == NULL){
        return;
    }
    else{
        //mirror left and right subtrees and then swap the pointers
        mirrorRecursive(cur->leftChildPtr);
        mirrorRecursive(cur->rightChildPtr);

        BinaryNode* temp = cur->leftChildPtr;
        cur->leftChildPtr = cur->rightChildPtr;
        cur->rightChildPtr = temp;
    }
}

int BinarySearchTree::span(const int a, const int b){
    if(isEmpty()){
        return 0;
    }
    return spanRecursive(root,a,b);
}

int BinarySearchTree::spanRecursive(BinaryNode* cur, const int a, const int b){
    int spanValue = 0;

    if (cur == NULL){
        return 0;
    }
    else{
        if(cur->item > a && cur->item < b){
            spanValue++;
            spanValue+= spanRecursive(cur->leftChildPtr,a,b);
            spanValue+= spanRecursive(cur->rightChildPtr,a,b);
        }
        else if(cur->item == a){
            spanValue++;
            spanValue+= spanRecursive(cur->rightChildPtr,a,b);
        }
        else if(cur->item < a){
            spanValue+= spanRecursive(cur->rightChildPtr,a,b);
        }
        else if(cur->item == b){
            spanValue++;
            spanValue+= spanRecursive(cur->leftChildPtr,a,b);
        }
        else if(cur->item > b){
            spanValue+= spanRecursive(cur->leftChildPtr,a,b);
        }
    }
    return spanValue;
}
