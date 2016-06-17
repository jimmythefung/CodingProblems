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
template <typename T>
struct Node {
    shared_ptr<T>       data;
    shared_prt<Node<T>> next;
};

/*
 * A linked list.
 * 'head' points to the first node in the list
 */
template <typename T>
struct List {
    shared_ptr<Node<T>> head;
};

/*
 * Initialize an empty list
 */
template <typename T>
static inline void initList(struct List *list)
{
    list->head = 0;
}

#endif
