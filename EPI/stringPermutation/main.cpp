#include <stdlib.h> /* srand, rand */
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <queue>
#include <list>
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
vector<string> perm(string s){
    vector<string> result;

    if(s.size()==1){
        result.push_back(s);
        return result;
    }

    for(string sMinus1: perm(s.substr(1))){
        for (int i=0; i <= sMinus1.size(); i++){
            result.push_back(sMinus1.substr(0,i) + s[0] + sMinus1.substr(i, sMinus1.size()-i));
        }

        /* 
         * if sMinus1 = {bc, cb}
         * the inner loop then insert "a" at all position for each sMinus1:
         * (a)bc, b(a)c, bc(a)
         * (a)cb, c(a)b, cb(a)
         */
    }

    return result;
}
int main(){
    string s = "abc";
    printv2(perm(s));
    return 0;
}

