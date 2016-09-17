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

list<treeNode*> convertToList(deque<treeNode> q){
    list<treeNode> *l = new list<treeNode>();
    for(treeNode n : q){
        l.push_back(n);
    }
    return &l;
}
void ListOfDepths(treeNode* root){
    vector<list*> result;
    deque<treeNode> q;
    q.push_back(root);

    int len;
    treeNode* n;
    while(!q.empty()){
        list<treeNode*> *l = convertToList(q);
        result.push_back(l);
        len = q.size();
        for(int i=0; i<len; i++){
            n = q.front();
            if(n->left!=NULL){q.push_back(n->left);}
            if(n->right!=Null){q.push_back(n->right);}
            q.pop_front();
        }
    }
    return result;
}


int main(){
    vector<int> A = {1,2,3,4,5,6,7,8,9,10};
    return 0;
}

