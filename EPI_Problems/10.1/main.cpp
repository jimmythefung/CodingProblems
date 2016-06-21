#include <stdlib.h> /* srand, rand */
#include <cmath>    /* abs()       */
#include <typeinfo>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <memory>
#include "../common/mylist.h"

using namespace std;

/* Forward declaration */
struct tNode{
    int data;
    tNode *L, *R;
};

struct BST{
    tNode* root;

    // constructor
    BST(){
        root = NULL;
    }

    // destructor

    /* Method */

    void traverse( void (*f)(tNode*) ){
        queue<tNode*> q;
        tNode *n;

        // initialize q with root node
        q.push(root);

        while (!q.empty()){
            n = q.front();
            f(n);
            q.pop();
            if (n->L!=NULL){
                q.push(n->L);
            }
            if (n->R!=NULL){
                q.push(n->R);
            }
        }
    }

    static void printNode(tNode* n){
        cout << n->data << endl;
    }

    void printTree(){
        traverse(printNode);
    }
};




int main(){
    vector<int> v = {4,6,1,2,3,9,7,5,3,4,0};
    
    queue<int> q;
    q.push(1);
    q.push(2);

    cout << q.front() << endl;
    q.pop();

    cout << q.front() << endl;
    q.pop();
    
    cout <<"empty? " << q.empty() << endl;
    
    // BST
    BST* t = new BST();
    
    return 0;
}
