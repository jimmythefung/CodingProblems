/*
 * mylist.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "mylist.h"


Node* addfront(List *L, int x){
    Node* n = new Node();
    n->data = x;
    n->next = L->head;
    L->head = n;
    return n;
}


void printList(List *L){
    Node* n = L->head;
    while(n != 0){
        cout << n->data << " ";
        n = n->next; // equivalent to n=(*n).next
    }
    cout << endl;
}
