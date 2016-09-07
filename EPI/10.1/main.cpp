#include <stdlib.h> /* srand, rand */
#include <cmath>    /* abs()       */
#include <typeinfo>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <memory>
#include "mybst.h"

using namespace std;

void visit(tNode* n){
    cout << n->data << " ";
}
void inOrder(tNode* n){
    if (n!=NULL){
        inOrder(n->L);
        visit(n);
        inOrder(n->R);
    }
}
void preOrder(tNode* n){
    if (n!=NULL){
        visit(n);
        preOrder(n->L);
        preOrder(n->R);
    }
}
void postOrder(tNode* n){
    if (n!=NULL){
        postOrder(n->L);
        postOrder(n->R);
        visit(n);
    }
}

int main(){

    vector<int> v = {4,6,1,2,3,9,7,5,3,4,0};
    vector<int> v2 = {10,5,15,4,3,7};
    
    // BST
    BST* t = new BST(v2);
    t->printTree();
    
    // height balanced?
    cout << "height balanced? " << isHeightBalanced(t) << endl;

    // in-order traversal
    cout << "In order traversal  : ";
    inOrder(t->root);
    cout << endl;

    // pre-order traversal
    cout << "pre order traversal : ";
    preOrder(t->root);
    cout << endl;
    
    // post-order traversal
    cout << "post order traversal: ";
    postOrder(t->root);
    cout << endl;
    
    // clean up
    delete t;
    
    return 0;
}
