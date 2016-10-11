#include <stdlib.h> /* srand, rand */
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <queue>
#include <list>
#include <unordered_map>
#include <algorithm>
#include <deque>
#include <list>
#include <limits>

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

struct treeNode{
    int data;
    treeNode* left;
    treeNode* right;
    treeNode(int x){
        this->data = x;
        this->left = NULL;
        this->right = NULL;
    }
};

bool inOrderDFS(treeNode* root, int &last){
    if (root == NULL){
        return true;
    }
    
    // explore left
    bool L = inOrderDFS(root->left, last);

    // visit current node
    if (root->data < last){
        return false;
    }else{
        last = root->data;
    }

    // explore right
    bool R = inOrderDFS(root->right, last);

    return L&R;
}

bool isBST(treeNode* root){
    int min = numeric_limits<int>::min();
    return inOrderDFS(root, min);
}

treeNode* getSuccessor(treeNode* root){
    treeNode* n = root;
    if (n->right != NULL){
        n = n->right;
        while (n->left != NULL){
            n = n->left;
        }
    }
    /* else the parent is the next node - had our treeNode has parent attribute
    else{
        n = n->parent;
    }
    */
     

    return n;
}


int main(){
    treeNode* root = new treeNode(5);
    root->left = new treeNode(3);
    root->right = new treeNode(7);
    root->left->left = new treeNode(9);
    root->right->right = new treeNode(7); 
    root->right->right->right = new treeNode(7); 

    cout << "Successor of " << root->data << " is " << getSuccessor(root)->data << endl;
    return 0;



}

