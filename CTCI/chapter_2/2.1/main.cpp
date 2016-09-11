#include <stdlib.h> /* srand, rand */
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <queue>
#include <list>
#include <unordered_map>
#include <algorithm>
#include <set>
#include "mylist.h"

using namespace std;

template <typename T> 
void printv2(vector<T> v, const string &s=string("Printing vector: ")){
    // s is a const& - constant reference;
    //   -content of s is constant; content can not be changed through s 
    //   -s is a reference, so no copying
    //   -In effect: Use s directly with no danger of mutation

    cout << s;
    for(auto it=v.begin(); it!=v.end(); it++){
        cout << *it << ", ";
    }
    cout << endl;
}

void removeDup(List *L){
    set<int> s;
    Node* n = L->head;
    while (n != NULL){
        if (s.count(n->data)==0){
            s.insert(n->data);
            n = n->next;
        }else{
            Node *toBeDeleted = n;
            (n->prev)->next = n->next;
            (n->next)->prev = n->prev;
            n = n->next;
            delete toBeDeleted;
        }
    }

}

int main(){
    // Build 2 lists
    List *L1 = new List();
    addFront(L1,7);         // L1 add elements
    addFront(L1,5);
    addFront(L1,2); 
    addFront(L1,11);  
    addFront(L1,3);
    addFront(L1, 1);
    addFront(L1, 2);
    addFront(L1, 3);
    cout << "List L1: " << endl;
    printMyList(L1);
    
    // test remove dup
    removeDup(L1);
    printMyList(L1);
    
    // clean up of List data structure
    removeList(L1);
    delete L1;

    return 0;
}

