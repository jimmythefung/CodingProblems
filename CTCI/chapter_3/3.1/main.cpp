#include <stdlib.h> /* srand, rand */
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <queue>
#include <list>
#include <unordered_map>
#include <algorithm>

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

struct Node{
    bool visited = false;
    int name;
    vector<Node*> neighbors;
    Node(int name){
        this->name = name;
        //this->neighbors = neighbors;
    }
};

struct Graph{
    vector<Node*> V;
    Graph(vector<Node*> V){
        this->V = V;
    }
};



int main(){
    
    // construct a graph
    Node *v1, *v2, *v3, *v4, *v5, *v6;
    v1 = new Node(1);
    v2 = new Node(2);
    v3 = new Node(3);
    v4 = new Node(4);
    v5 = new Node(5);
    v6 = new Node(6);
    v1->neighbors = {v2, v5};
    v2->neighbors = {v3, v5, v1};
    v3->neighbors = {v4, v2};
    v4->neighbors = {v3, v5, v6};
    v5->neighbors = {v1, v2, v4};
    v6->neighbors = {v4};
    Graph *G = new Graph({v1,v2,v3,v4,v5,v6});

    return 0;
}

