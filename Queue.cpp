/*
* Title: Binary Search Trees
* Author: Beste Guney
* ID: 21901631
* Section: 1
* Assignment: 2
* Description: This is the implementation file for Queue Adt which is used in level order traversal
*/
#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue(){
    backPtr = NULL;
    frontPtr = NULL;
}
Queue::~Queue(){
    while(!isEmpty()){
        dequeue();
    }
}
bool Queue::isEmpty(){
    return backPtr == NULL;
}
void Queue::enqueue(QueueItem item){
    QueueNode* newPtr = new QueueNode;
    newPtr->value = item;
    newPtr->next = NULL;

    if(frontPtr == NULL){
        frontPtr = newPtr;
    }
    else{
        backPtr->next = newPtr;
    }
    backPtr = newPtr;
}

void Queue::dequeue(){
    if(frontPtr != NULL){
        QueueNode* temp = frontPtr;
        if(frontPtr == backPtr){
            frontPtr = NULL;
            backPtr = NULL;
        }
        else{
            frontPtr = frontPtr->next;
        }
        delete temp;
    }
}

void Queue::dequeue(QueueItem& item){
    if(frontPtr != NULL){
        QueueNode* temp = frontPtr;
        item = frontPtr->value;
        if(frontPtr == backPtr){
            frontPtr = NULL;
            backPtr = NULL;
        }
        else{
            frontPtr = frontPtr->next;
        }
        delete temp;
    }
}

void Queue::getFront(QueueItem& item){
    if(frontPtr != NULL){
        item = frontPtr->value;
    }
}
