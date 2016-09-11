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
int getKth(List* L, int k){
    Node* a = L->head;
    Node* b = L->head;
    for(int i=0; i<k; i++){
        b = b->next;
    }

    while (b->next != NULL){
        a = a->next;
        b = b->next;
    }

    return a->data;
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
    
    // test remove dupi
    int k = 3;
    cout << "The "+to_string(k)+"th to last element is: " << getKth(L1, k) << endl;
    
    // clean up of List data structure
    removeList(L1);
    delete L1;

    return 0;
}

