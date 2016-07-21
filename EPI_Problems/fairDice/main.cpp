#include <stdlib.h> /* srand, rand */
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <queue>
#include <list>
#include <unordered_map>
#include <map>

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

void printQueue(deque<vector<int>> q){
    for(auto it=q.begin(); it!=q.end(); it++){
        cout << "(";
        for(auto v=(*it).begin()+1; v!=(*it).end(); v++){
            cout << *v;
            if (v+1 != (*it).end()){
                cout << ", ";
            }
        }
        cout << ")->" << (*it)[0] << endl;
    }
}

void printTable(map<int, int> table){
    for(auto it=table.begin(); it!=table.end(); it++){
        int key = it->first;
        int value = it->second;
        cout << key << ": " << value << endl;
    }
}

map<int, int> buildmap(deque<vector<int>> q){
    int key;
    map<int, int> table;
    
    for(auto it=q.begin(); it!=q.end(); it++){
        
        key = (*it)[0];
        
        if (table.count(key)==0){
            table[key] = 1;
        }else{
            table[key] = table[key]+1;
        }
    }
    return table;
}

deque<vector<int>> fairDice(int m, int n){
    // initialize
    deque<vector<int>> q;
    for(int i=1; i<=m; i++){
        vector<int> v = {i,i};
        q.push_back(v);
    }

    // iterate all combinations
    vector<int> v, v_copy;
    for(int ithDraw=2; ithDraw<=n; ithDraw++){

        // iterate all current states
        int qSize = q.size();
        for (int k=0; k<qSize; k++){

            // get a v from front of queue
            v_copy = q.front();
            q.pop_front();

            // iterate all possible new draw
            for(int i=1; i<=m; i++){

                // reset v to current working state
                v = v_copy;

                // modify v
                v[0] += i;      // v[0] is sum of v[1]...v[end]
                v.push_back(i);

                // push back into q
                q.push_back(v);
            }
        }
    }
    return q;
}

void fairDiceTest(){
    int m, n;
    deque<vector<int>> q;
    map<int, int> table;

    cout << "Enter m, the number of sides: ";
    cin >> m;
    cout << "Enter n, the number of dice: ";
    cin >> n;
    
    q = fairDice(m,n);
    table = buildmap(q);

    printQueue(q);
    printTable(table);
}

int main(){
    fairDiceTest();
    return 0;
}

