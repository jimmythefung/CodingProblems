/*
 * mylist.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "mylist.h"

Node* addFront(List* L, int x){
    Node* n = new Node();
    n->data = x;
    n->next = L->head;
    L->head = n;
    return n;
}


Node* findNode(List* L, int key){
    Node* n = L->head;
    while (n!=NULL){
        if (n->data == key){
            return n;
        }
    }
    return NULL;
}
void* popFront(List* L){
    if (L->head != NULL){
        Node *n = L->head->next;
        delete L->head;
        L->head = n;
    }else{
        return L->head;
    }
}

void removeList(List* L){
    while (L->head != NULL){
        popFront(L);
    }
}

void printList(List* L){
    Node* n = L->head;
    while(n != 0){
        cout << n->data << " ";
        n = n->next; // equivalent to n=(*n).next
    }
    cout << endl;
}
