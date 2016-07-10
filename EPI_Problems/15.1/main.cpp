#include <stdlib.h> /* srand, rand */
#include <cmath>    /* abs()       */
#include <typeinfo>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <memory>
#include "mybst.h"
#include <limits>

using namespace std;


int isBST_visit(tNode* n, int maxSoFar){
    if((n->data) > maxSoFar){
        return n->data;
    }else{
        return numeric_limits<int>::min();
    }
}

int isBST_traverse(tNode* n, int maxSoFar){
    if (n==NULL){
        return maxSoFar;
    }
    
    maxSoFar = isBST_traverse(n->L, maxSoFar);
    
    maxSoFar = isBST_visit(n, maxSoFar);
    
    maxSoFar = isBST_traverse(n->R, maxSoFar);

    return maxSoFar;
}


bool isBST(tNode* n){
    int min = numeric_limits<int>::min();

    int flag = isBST_traverse(n,min);

    if( flag == numeric_limits<int>::min()){
        return false;
    }else{
        cout << "isBST returned int: " << flag << endl;
        return true;
    }
}

int main(){

    vector<int> v = {4,6,1,2,3,9,7,5,3,4,0};
    vector<int> v2 = {10,5,15,4,3,7};
    
    // BST
    BST* t = new BST(v2);
    t->printTree();
    
    // check BST property
    cout << "is BST property satisfied?: " << isBST(t->root) << endl;

    // clean up
    delete t;
    
    return 0;
}
