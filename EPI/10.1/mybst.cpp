/*
 * myBST.cpp
 */

#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include "mybst.h"


// returns -1 if unbalanced node found, otherwise height of root
int getDepth(tNode* n, int parentDepth){

    // leaf
    if (n == NULL){
        return parentDepth;
    }

    int LDepth, RDepth, deltaHeight, deepest;
    int currentDepth;

    // get depth of left and right child nodes
    currentDepth = parentDepth+1;
    LDepth = getDepth(n->L, currentDepth);
    RDepth = getDepth(n->R, currentDepth);
    
    deepest = max(LDepth, RDepth);
    deltaHeight = abs(LDepth-RDepth);
    if ( (deltaHeight>1) || (LDepth==-1) || (RDepth==-1) ){
        return -1;
    }else{
        return deepest;
    }
}

bool isHeightBalanced(BST* t){

    int result = getDepth(t->root, 0);

    if (result==-1){
        return false;
    }else{
        return true;
    }

}
