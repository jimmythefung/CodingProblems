#include <stdlib.h> /* srand, rand */
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <queue>
#include <list>
#include <unordered_map>

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
/*
// over counted solution
int f(int x, vector<int> S, unordered_map<int, int> &cache){

    // base case 1: x is 0; i.e. x = xlast-e = 0
    if (x == 0){ 
        return 1; 
    }

    // base case 2: x is in cache
    if (cache.count(x)!= 0){
        return cache[x];
    }

    // recursive case: f(x) = f(x-e1) + f(x-e2) + ... + f(x-en)
    for (int e: S){     // 
        if ( x-e >= 0 ){
            cache[x] += f(x-e, S, cache);
        }
    }
    return cache[x];
}

// over counted solution
int buildcache(int n, vector<int> S){
    unordered_map<int, int> cache;
    int result;
    result = f(n, S, cache);

    for(auto it=cache.begin(); it!=cache.end(); it++){
        cout << it->first<< " -> " << it->second << endl;
    }
    return result;
}

// over counted solution
void overCountedTest(){
    int n = 12;
    vector<int> S = {2,3,7};
    cout << "Number of ways to get 12 from {2,3,7} is: " << buildcache(n, S) << endl;
}
*/



// use optimal substructure: www.algorithmist.com/index.php/coinchange
int f2(vector<int> S, int k, int x, unordered_map<int, int> &cache){ // k is the length of S; x is the target change value

    // base case: x is 0
    if (x == 0){
        return 1; 
    }

    // base case: x < 0; no solution
    if (x < 0){
        return 0;
    }

    // base case: x is greater than zero, but coin set (bounded by length k; k=0) is none
    if ((k <= 0) && (x>=1)){
        return 0;
    }

    // recursive case: f(x) = [f(x) exlcuding last change] + [ f(x-S[k]) including last(kth) change]
    return f2(S, k-1, x, cache) + f2(S, k, x-S[k-1], cache);
}

// correct solution
int buildcache2(int n, vector<int> S){
    unordered_map<int, int> cache;
    
    return f2(S, S.size(), n, cache);
}

// correct solution
void countTest(){
    int n = 12;
    vector<int> S = {2,3,7};
    cout << "Number of ways to get 12 from {2,3,7} is: " << buildcache2(n, S) << endl;
}

int main(){
    //countTest();
    countTest();
    return 0;
}

