/*
 * mylist.h
 */

#ifndef __MYLIST_H__
#define __MYLIST_H__

using namespace std;

#include <iostream>
#include <memory>
#include <string>
#include <vector>

/*
 * A Linked List node
 */
struct Node{
    int data;
    Node* next;
    Node* prev;
};

struct List{
    Node* head;
    Node* tail;

    // default constructor
    List(){
        head = NULL;
        tail = NULL;
    }
};

/*
 * Search for a key
 */
Node* findNode(List* L, int key);

/*
 * Insert a node at front
 */
Node* addFront(List* L, int x);

/*
 * Delete a node at front
 */
void* popFront(List* L);

/*
 * Remove all nodes
 */
void removeList(List* L);

#endif
