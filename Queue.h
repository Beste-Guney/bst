/*
* Title: Binary Search Trees
* Author: Beste Guney
* ID: 21901631
* Section: 1
* Assignment: 2
* Description: This is the header file for Queue Adt which is used in level order traversal
*/
#include <iostream>
#include "BinaryNode.h"
using namespace std;

typedef BinaryNode* QueueItem;

class Queue{
public:
    //constructor
    Queue();

    //destructor
    ~Queue();

    //methods
    bool isEmpty();
    void enqueue(QueueItem item);
    void dequeue(QueueItem& item);
    void getFront(QueueItem& item);
    void dequeue();

private:
    struct QueueNode{
        QueueItem value;
        QueueNode* next;
    };

    QueueNode* backPtr;
    QueueNode* frontPtr;
};
