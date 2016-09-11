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

bool isPalPerm(const string &s){
    
    // build char frequency table
    unordered_map<char, int> charTable;
    for(auto it=s.begin(); it!=s.end(); it++){
        charTable[*it] += 1;
    }

    // count number of odd frequencies. More than 1 occurnace of odd violates palindrome
    int oddCount = 0;
    for(auto it=charTable.begin(); it!=charTable.end(); it++){
        if ( (it->second)%2 != 0 ){
            if(++oddCount > 1){ return false; }
        }
    }
    return true;
}

int main(){
    string s = "tactcoa";
    cout << "Is "+s+" a palindrom permutation? " << isPalPerm(s) << endl;
    return 0;
}

