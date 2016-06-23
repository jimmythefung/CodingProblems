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


int main(){

    vector<int> v = {4,6,1,2,3,9,7,5,3,4,0};
    vector<int> v2 = {10,5,15,4,3,7};
    
    // BST
    BST* t = new BST(v2);
    t->printTree();
    
    // height balanced?
    cout << "height balanced? " << isHeightBalanced(t) << endl;

    // clean up
    delete t;
    
    return 0;
}
