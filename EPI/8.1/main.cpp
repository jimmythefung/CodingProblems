#include <stdlib.h> /* srand, rand */
#include <cmath>    /* abs()       */
#include <typeinfo>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "mylist.h"

using namespace std;

/* Forward declaration */
void list_test();
List* merge(List *L1, List *L2);

int main(){

    // Build 2 lists
    List *L1 = new List();
    List *L2 = new List();
    addFront(L1,7);         // L1 add elements
    addFront(L1,5);
    addFront(L1,2); 
    addFront(L2,11);         // L2 add elements
    addFront(L2,3);
    cout << "List L1: " << endl;
    printMyList(L1);
    cout << "List L2: " << endl;
    printMyList(L2);

    // Merge the sorted list
    List *M;
    M = merge(L1, L2);
    cout << "printing merged list: ";
    printMyList(M);

    // clean up
    removeList(M);  // delete all Nodes() structures
    delete L1;      // delete all List() structures
    delete L2;

    //list_test();
    return 0;
}

List* merge(List* L1, List* L2){
    Node *a, *b, *tail;
    List* result;
    a = L1->head;
    b = L2->head;
    if (L1->head->data < L2->head->data){
        result = L1;
        a = a->next;
    }else{
        result = L2;
        b = b->next;
    }
    tail = result->head;

    while(a!=NULL && b!=NULL){
    //    cout << tail->data << endl;
        if (a->data < b->data){
            tail->next = a;
            a->prev = tail;
            tail = a;
            a = a->next;
        }else{
            tail->next = b;
            b->prev = tail;
            tail = b;
            b = b->next;
        }
    }
    
    (a==NULL) ? tail->next=b : tail->next=a;
    return result;
}

void list_test(){
    // Dynamically allocated new list (remember to delete)
    List* L = new List();

    // Build simple list
    addFront(L, 8);
    addFront(L, 1);
    addFront(L, 3);
    cout << "new list: ";
    printMyList(L);

    // Find node
    Node* n = findNode(L, 3);
    cout << "find node value returned: "<< n->data << endl;
    
    // Delete
    popFront(L);
    cout << "pop front: ";
    printMyList(L);

    // Remove all list
    removeList(L);
    cout << "Remove all: ";
    printMyList(L);

    // clean up L - free memory
    delete L;
}
