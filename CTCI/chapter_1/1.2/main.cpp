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

// note &s1 makes s1 not a copy, but a direct reference, of the string passed in.
bool checkPermutation(const string &s1, const string &s2){
    
    // check length
    if (s1.size() != s2.size()){
        return false;
    }
    else{
        unordered_map<char, int> charTable;
        // build frequency table
        for(size_t i=0; i < s1.size(); i++){
            charTable[s1[i]]++;
            charTable[s2[i]]--;
        }
        for(auto it=charTable.begin(); it!=charTable.end(); it++){
            if (it->second != 0){
                return false;
            }
        }
        return true;
    }
}

int main(){
    string s1, s2;
    s1 = "acbc";
    s2 = "abcc";
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s1 permutes to s2?: " << checkPermutation(s1, s2) << endl;
    return 0;
}

