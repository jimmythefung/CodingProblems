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

bool oneAway(const string &s1, const string &s2){
    // Can not be within one edit away
    if (  abs((int)s1.size()-(int)s2.size()) > 1 ){
        cout << s1.size()-s2.size() << endl; 
        return false;
    }

    // build character frequency table, take difference
    unordered_map<char, int> charFreq;
    for(char c1 : s1){ charFreq[c1]++; }
    for(char c2 : s2){ charFreq[c2]--; }

    // examine delta
    int delta = 0;
    for(auto it=charFreq.begin(); it!=charFreq.end(); it++){
        delta += it->second;
    }
    return abs(delta)>1? false : true; // delta={-1,0,1} are 1 edit away.
}

int main(){
    string s1 = "abc";
    string s2 = "abcd";
    string s3 = "abcf";

    cout << "s1="+s1 << ", s2="+s2 << ", s3="+s3 << endl;
   
    cout << "oneAway(s1, s2): " << oneAway(s1, s2) << endl;
    cout << "oneAway(s2, s1): " << oneAway(s2, s1) << endl;
    cout << "oneAway(s2, s3): " << oneAway(s2, s3) << endl;
    
    return 0;
}

