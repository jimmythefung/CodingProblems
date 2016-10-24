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

int nSteps(int n, unordered_map<int, int> &cache){

    if (cache.count(n)!=0){
        return cache[n];
    }

    int sum = 0;

    if (n-1 >= 0){
        sum = sum + nSteps(n-1, cache);
    }

    if (n-2 >= 0){
        sum = sum + nSteps(n-2, cache);
    }

    if (n-3 >= 0){
        sum = sum + nSteps(n-3, cache);
    }

    cache[n] = sum;
    
    return sum;
}


int nStepsHelper(int n){
    unordered_map<int, int> cache;
    cache[0] = 1;
    return nSteps(n, cache);
}

int main(){

    cout << "n=1: " << nStepsHelper(1) << endl;
    cout << "n=2: " << nStepsHelper(2) << endl;
    cout << "n=3: " << nStepsHelper(3) << endl;
    cout << "n=4: " << nStepsHelper(4) << endl;

    return 0;
}

