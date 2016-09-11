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

string stringCompression(const string &s){

    int count = 1;
    string output = "";

    for(size_t i=1; i < s.size(); i++){
        // regular case: current character differ than last
        if (s[i] != s[i-1]){ // i.e. "abc"; i=3, s[i]="c" != "b"
            output += s[i-1] + to_string(count); // = "a1b1"
            count = 1;
        }
        // repeated case: current char is same as last one
        else{
            count++;
        }
    }
    // final case: last character
    output += s[s.size()-1] + to_string(count); // "a1b1" + "c1"
    
    
    return output.size() < s.size()? output : s;
}

int main(){
    // get input
    string s;
    cout << "Enter a string to be compressed: ";
    cin >> s;
    // output display
    cout << "Compressed string of "+s << " is: " << endl;
    cout << stringCompression(s) << endl;
    return 0;
}

