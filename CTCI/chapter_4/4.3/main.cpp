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


vector<list<treeNode*>> ListOfDepths(treeNode* root){
    vector<list<treeNode*>> result;
    // create a deque to BFS root
    deque<treeNode*> q;
    q.push_back(root);

    // listLength keeps track number of nodes at each tree level 
    int listLength;
    treeNode* n;
    list<treeNode*> l;
    while(!q.empty()){
        listLength = q.size();
        l.clear();
        // for each level, build all nodes into a linked list, l
        for(int i=0; i < listLength; i++){
            n = q.front();
            q.pop_front();
            l.push_back(n);

            if (n->left!=NULL){q.push_back(n->left);}
            if (n->right!=NULL){q.push_back(n->right);}
        }

        // put the linked list at each level into result
        result.push_back(l);

    }
    return result;
}

int main(){
    treeNode* root = new treeNode(5);
    root->left = new treeNode(3);
    root->right = new treeNode(7);
    
    vector<list<treeNode*>> l = ListOfDepths(root);
    for(auto it=l.begin(); it!=l.end(); it++){
        cout << "list: " << "";
        for(auto e=it->begin(); e!=it->end(); e++){
            cout << (*e)->data << " ";
        }
        cout << endl;
    }
    return 0;

}

