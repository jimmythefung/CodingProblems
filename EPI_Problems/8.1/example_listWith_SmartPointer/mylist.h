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
    shared_ptr<Node> next;
};

/*
 * A linked list.
 * 'head' points to the first node in the list
 */
struct List {
    shared_ptr<Node> head;
};

/*
 * Initialize an empty list
 */
static inline void initList(shared_ptr<List> L)
{
    L->head = 0;
}

/* functions */
shared_ptr<Node> addfront(shared_ptr<List> L, int x);
void printList(shared_ptr<List> L);
#endif
