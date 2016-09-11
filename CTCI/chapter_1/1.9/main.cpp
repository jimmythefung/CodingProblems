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

bool isSubstring(const string &s1, const string &s2){
    size_t found = s1.find(s2);
    if (found != string::npos){
        return true;
    }else{
        return false;
    }
}

bool stringRotation(const string &s1, const string &s2){
    return isSubstring(s1+s1, s2);
}

int main(){
    string s1 = "waterbottle";
    string s2 = "erbottlewat";
    cout << "Is "+s2+" a rotation of "+s1+"? " << stringRotation(s1, s2) << endl; 
    return 0;
}

