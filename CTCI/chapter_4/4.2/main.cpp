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

treeNode* getMidNode(vector<int> A, int start, int end){
    /*
    if (start == end){
        treeNode *n = new treeNode( A[start] );
        return n;
    }
    */
    if (start > end){
        return NULL;
    }

    int m = (end - start)/2 + start;

    treeNode *n = new treeNode(A[m]);
    n->left = getMidNode(A, start, m-1);
    n->right = getMidNode(A, m+1, end);

    return n;

}
void printBST(treeNode* root){
    deque<treeNode*> q;
    q.push_back(root);
    while(!q.empty()){
        int len = q.size();
        for(int i=0; i<len; i++){
            cout << q.front()->data << " ";
            if(q.front()->left != NULL){
                q.push_back(q.front()->left);
            }
            if(q.front()->right != NULL){
                q.push_back(q.front()->right);
            }
            q.pop_front();
        }
        cout << endl;
    }

}

int main(){
    vector<int> A = {1,2,3,4,5,6,7,8,9,10};
    treeNode *root = getMidNode(A,0,A.size()-1);
    printBST(root);
    return 0;
}

