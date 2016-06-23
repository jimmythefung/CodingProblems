/*
 * mybst.h
 */

#ifndef __MYLIST_H__
#define __MYLIST_H__

using namespace std;

#include <iostream>
#include <memory>
#include <string>
#include <vector>

/*
 * A tree node
 */

struct tNode{
    int data;
    tNode *L, *R;

    tNode(int x){
        data = x;
        L = NULL;
        R = NULL;
    }

};

/*
 * The Binary Search Tree class
 */

struct BST{
    tNode* root=NULL;

    // default constructor
    BST(){}

    // constructor
    BST(vector<int> v){
        for (auto it=v.begin(); it!=v.end(); it++){
            insert(*it);
        }
    }

    // destructor
    ~BST(){
        removeTree();
    }

    // Insert
    void insert(int x){
        RInsert(root, x);
    }
    void RInsert(tNode* &n, int x){
        // empty tree
        if (n==NULL){
            n = new tNode(x); // requires (tNode* &n)
        }
        // x is smaller
        else if (x < n->data){
            if (n->L!=NULL){
                RInsert(n->L, x);
            }else{
                n->L = new tNode(x);
            }
        }
        // x is equal or bigger
        else{
            if (n->R!=NULL){
                RInsert(n->R, x);
            }else{
                n->R = new tNode(x);
            }
        }
    }

    // traverse
    void traverse( void (*f)(tNode*) ){
        queue<tNode*> q;
        tNode *n;

        // initialize q with root node
        q.push(root);

        while (!q.empty()){
            n = q.front();
            if (n->L!=NULL){
                q.push(n->L);
            }
            if (n->R!=NULL){
                q.push(n->R);
            }
            q.pop();
            f(n);
        }
    }

    static void printNode(tNode* n){ // static because traverse takes function from global namespace
        cout <<  n->data << " ";
    }

    void printTree(){
        cout << "print Tree: ";
        traverse(printNode);
        cout << endl;
    }

    static void removeNode(tNode* n){
        delete n;
    }

    void removeTree(){
        traverse(removeNode);
        root = NULL;
    }
};

/* Function Prototypes */
// returns -1 if unbalanced node found, otherwise height of root
int getDepth(tNode* n, int parentDepth);
bool isHeightBalanced(BST* t);

#endif
