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



int main(){
    treeNode* root = new treeNode(5);
    root->left = new treeNode(3);
    root->right = new treeNode(7);
    
    return 0;

}

