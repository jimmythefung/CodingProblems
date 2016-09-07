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
 * A node in linked list
 */
struct Node {
    int   data;
    Node* next;
};

/*
 * A linked list.
 * 'head' points to the first node in the list
 */
struct List {
    Node* head;
};

/*
 * Initialize an empty list
 */
static inline void initList(List* L)
{
    L->head = 0;
}

/* functions */
Node* addfront(List *L, int x);
void printList(List *L);
#endif
