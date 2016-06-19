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

int main(){
    shared_ptr<List> L (new List());
    //List L;
    initList(L);
    addfront(L, 8);
    addfront(L, 1);
    addfront(L, 3);
    printList(L);


    return 0;
}

void printv(vector<int>& A){
    vector<int>::iterator it;
    for(it=A.begin(); it<A.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
