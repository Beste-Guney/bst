/*
* Title: Binary Search Trees
* Author: Beste Guney
* ID: 21901631
* Section: 1
* Assignment: 2
* Description: This is the implementation file for BinaryNode
*/

#include "BinaryNode.h"
#include <iostream>
using namespace std;

BinaryNode::BinaryNode(){
    item = 0; //default value will be 0
    leftChildPtr = NULL;
    rightChildPtr = NULL;
}
BinaryNode::~BinaryNode(){
    delete leftChildPtr;
    delete rightChildPtr;
}
BinaryNode::BinaryNode(const NodeItem& value){
    item = value;
    leftChildPtr = NULL;
    rightChildPtr = NULL;
}

NodeItem BinaryNode::getItem(){
    return item;
}

void BinaryNode::setItem(NodeItem value){
    item = value;
}
