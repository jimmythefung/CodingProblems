#include <stdlib.h> /* srand, rand */
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <queue>
#include <list>
using namespace std;

void printMatrix(vector<vector<int>> &m){
    for(vector<int> v : m){
        for(int ele : v){
            cout << ele << " ";
        }
        cout << endl;
    }
}


int main(){
    vector<int> v1 = {5, 3, 1};
    vector<int> v2 = {19,13,9,1};
    vector<int> v3 = {8,6,4};

    list<vector<int>> l;
    l.push_back(v1);
    l.push_back(v2);
    l.push_back(v3);

    priority_queue<int, vector<int>, greater<int>> minQ;
    priority_queue<int, vector<int>, greater<int>> resultQ;

    // initialize minQ
    for(auto v=l.begin(); v!=l.end(); v++){
        minQ.push( v->back() );
        v->pop_back();
    }

    // cycle through v from list l, 1. pull e from v into minQ, 2. pull e from minQ to resultQ
    vector<int> v;
    while (!l.empty()){

        // gets a vector from list
        v = l.front();
        l.pop_front();

        // insert last element of v into minQ
        minQ.push( v.back() );
        v.pop_back();

        // put v back into list if not empty
        if (!v.empty()){
            l.push_back( v );
        }

        // stream a min to result
        resultQ.push( minQ.top() );
        minQ.pop();
    }
    
    // transfer remaining minQ to resultQ
    while(!minQ.empty()){
        resultQ.push( minQ.top() );
        minQ.pop();
    }

    // print resultQ
    cout << "resultQ: ";
    while(!resultQ.empty()){
        cout << resultQ.top() << ", ";
        resultQ.pop();
    }
    cout << endl;

    return 0;

}
