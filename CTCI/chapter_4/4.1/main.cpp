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


void clearQ(deque<Node*> &q){
    while(!q.empty()){
        q.pop_front();
    }
}

deque<Node*> getAllNeighborsInQ(deque<Node*> &QofNodes){
    deque<Node*> result;
    for(Node* &n : QofNodes){
        for(Node *neighbor : n->neighbors){
            if (neighbor->visited==false){
                result.push_back(neighbor);
                //cout << neighbor->name;
            }
        }
    }
    return result;
}

bool routeBetween(Node* &src, Node* &dst){
    int bfsLevel = 0;
    deque<Node*> srcQ, dstQ, bfsQ;
    src->visited = true;
    dst->visited = true;
    srcQ.push_back(src);
    dstQ.push_back(dst);

    while(!srcQ.empty() or !dstQ.empty()){
        bfsLevel++;

        // visit all next neighbor of srcQ
        bfsQ = getAllNeighborsInQ(srcQ);
        clearQ(srcQ);
        while(!bfsQ.empty()){
            Node* &s = bfsQ.front();
            bfsQ.pop_front();

            if(s->visited == true){
                cout << s->name << " already visited. Return true." << endl;
                return true;
            }else{
                cout << s->name << " visited. Setting visited=true." << endl;
                s->visited = true;
                srcQ.push_back(s);
            }
        }

        // visit all next neighbor of dstQ
        bfsQ = getAllNeighborsInQ(dstQ);
        clearQ(dstQ);
        while(!bfsQ.empty()){
            Node* &d = bfsQ.front();
            bfsQ.pop_front();

            if(d->visited == true){
                return true;
            }else{
                d->visited = true;
                dstQ.push_back(d);
            }
        }
    }
    cout << "No path found. Return false." << endl;
    return false;
}

bool isConnected(Graph* &G){
    int n,i,j;
    n = G->V.size(); // number of vertex in G
    
    i = 0;
    while( i < n ){
        j=i+1;
        while( j < n ){
            if(!routeBetween(G->V[i], G->V[j])){
                return false;
            }
            j++;
        }
        i++;
    }
    return true;
}

void BFSPrint(Node* &src){
    deque<Node*> q;
    q.push_back(src);
    cout << "BFS: ";
    while(!q.empty()){
        Node* &n = q.front(); // only view front element
        q.pop_front();   // only delete. returns nothing
        
        cout << n->name << " ";
        n->visited = true;

        for(Node* &neighbor : n->neighbors){
            if(neighbor->visited==false){
                q.push_back(neighbor);
                neighbor->visited = true;
            }
        }
    }
    cout << endl;
}

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

    // Check graph G is connected
    //cout << "Is graph G connected? " << isConnected(G) << endl;
    
    //BFSPrint(v1);
    //Node* v7 = new Node(7);
    //v7->neighbors = {};
    cout << routeBetween(v1, v2) << endl;
    
    return 0;
}

