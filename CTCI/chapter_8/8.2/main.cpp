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

template <typename T>
void printM(vector<vector<T>> M){

    for(auto it=M.begin(); it!=M.end(); it++){
        printv2(*it, "");
    }
}

int main(){
    vector<vector<int>> M;
    M = {
        {1,1,1,1},
        {1,0,0,1},
        {1,0,0,1},
        {1,1,1,-1}
    };

    printM(M);
    return 0;
}

