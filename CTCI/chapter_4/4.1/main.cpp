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

void resetGraph(Graph* G){
    for(Node* &n : G->V){
        n->visited = false;
    }

}

deque<Node*> getAllNeighborsInQ(deque<Node*> &QofNodes){
    deque<Node*> result;
    for(Node* &n : QofNodes){
        //n->visited = true;
        for(Node *neighbor : n->neighbors){
            result.push_back(neighbor);
            //if (neighbor->visited==false){
            //    result.push_back(neighbor);
                //cout << neighbor->name;
        }
    }
    return result;
}

bool routeBetween(Node* &src, Node* &dst){
    cout << "Searching route between: " << src->name << " and " << dst->name << ". Result: ";
    int bfsLevel = 0;
    deque<Node*> visitedQ, unVisitedQ;
    src->visited = true;
    visitedQ.push_back(src);

    while(!visitedQ.empty()){// or !dstQ.empty()){
        bfsLevel++;

        // visit all next neighbor of visitedQ
        unVisitedQ = getAllNeighborsInQ(visitedQ);
        clearQ(visitedQ);
        while(!unVisitedQ.empty()){
            Node* &s = unVisitedQ.front();
            unVisitedQ.pop_front();

            if (s->visited == false){
                s->visited = true;
                visitedQ.push_back(s);
            }
        }
        
        if(dst->visited==true){
            cout << "Found" << endl;
            return true;
        }
    }
    //cout << "No path found. Return false." << endl;
    cout << "Not Found." << endl;
    return false;
}

bool isConnected(Graph* G){
    int n,i,j;
    n = G->V.size(); // number of vertex in G
    
    i = 0;
    while( i < n ){
        j=i+1;
        while( j < n ){
            if(!routeBetween(G->V[i], G->V[j])){
                cout << "No route between " << G->V[i]->name << " and " << G->V[j]->name << endl;
                return false;
            }
            // need to reset all the vertex to unvisited
            resetGraph(G);
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
    cout << "Is graph G connected? " << isConnected(G) << endl;
    
    //BFSPrint(v1);
    Node* v7 = new Node(7);
    v7->neighbors = {};
    routeBetween(v1, v7);
    
    return 0;
}

