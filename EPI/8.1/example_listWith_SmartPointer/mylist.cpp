/*
 * mylist.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "mylist.h"

shared_ptr<Node> addfront(shared_ptr<List> L, int x){
    shared_ptr<Node> n(new Node());
    n->data = x;
    n->next = L->head;
    L->head = n;
    return n;
}


void printList(shared_ptr<List> L){
    shared_ptr<Node> n = L->head;
    while(n != 0){
        cout << n->data << " ";
        n = n->next; // equivalent to n=(*n).next
    }
    cout << endl;
}
