#include <stdlib.h> /* srand, rand */
#include <cmath>    /* abs()       */
#include <typeinfo>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "mylist.h"

using namespace std;


/* Function Prototyes */
void printv(vector<int>& A);
void printList(List* L);

int main(){
    // Dynamically allocated new list (remember to delete)
    List* L = new List();

    //
    addFront(L, 8);
    addFront(L, 1);
    addFront(L, 3);
    cout << "new list: ";
    printList(L);


    // Find node
    Node* n = findNode(L, 3);
    cout << "find node value returned: "<< n->data << endl;
    
    // Delete
    popFront(L);
    cout << "pop front: ";
    printList(L);

    // Remove all list
    removeList(L);
    cout << "Remove all: ";
    printList(L);


    // clean up L
    delete L;

    return 0;
}

void printv(vector<int>& A){
    vector<int>::iterator it;
    for(it=A.begin(); it<A.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
