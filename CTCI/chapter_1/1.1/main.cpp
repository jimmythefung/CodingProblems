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

bool isUnique(string s){

    unordered_map<char, int> cache;

    // build hashTable to count the frequency of characters
    for(size_t i=0; i < s.size() ; i++){
        // check if character already in cache
        if (cache.count(s[i])==0){
            cache[s[i]] = 1;
        }else{
            cache[s[i]]++;
        }
    }

    // iterate table
    bool flag = true;
    for (auto it=cache.begin(); it!=cache.end(); it++){
        cout << "c = " << (*it).first << ", ";
        cout << "f = " << it->second << endl;
        if (it->second > 1){
            flag = false;
        }
    }
    return flag;
}


bool isUniqueNoDS(string s){
    sort(s.begin(), s.end());
    for(size_t i=1; i < s.size(); i++){
        if (s[i]==s[i-1]){
            return false;
        }
    }
    return true;
}

int main(){
    string s = "jimmyfung";
    cout << "Is "+s+" unique? " << isUnique(s) << endl;

    string s2 = "jimyfung";
    cout << "Is "+s2+" unique? " << isUniqueNoDS(s2) << endl;

    return 0;
}

