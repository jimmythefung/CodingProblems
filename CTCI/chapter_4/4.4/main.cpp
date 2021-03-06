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


int getDepth(treeNode* root, bool &is_balanced_flag){

    if (root == NULL){
        return 0;
    }

    int L = getDepth(root->left, is_balanced_flag);
    int R = getDepth(root->right, is_balanced_flag);

    if (abs(L-R)>1){
        is_balanced_flag = false;
    }

    return max(L,R)+1;

}

bool isBalanced(treeNode* root){
    bool flag = true;
    getDepth(root, flag);
    return flag;
}

int main(){
    treeNode* root = new treeNode(5);
    root->left = new treeNode(3);
    root->right = new treeNode(7); 
    root->right->right = new treeNode(7); 
    root->right->right->right = new treeNode(7); 

    cout << "Is root balanced? ";
    isBalanced(root)? cout << "True" : cout << "False";
    cout << endl;
    return 0;

}

