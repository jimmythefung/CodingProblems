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

void URLify(string &s, int n){
    int a, b;
    a = n       -1;  // pay attention to the -1 offset for proper last element index
    b = s.size()-1;  // same here

    while (a != -1){
        if (s[a] == ' '){
            s[b]   = '0';
            s[b-1] = '2';
            s[b-2] = '%';
            b = b-3;  // pay attention to the -3 offset to prepare b for the unused position 
        }
        else{
            s[b] = s[a];
            b--;
        }
        a--;
    }
}

int main(){
    string s="Mr John Smith    ";
    cout << "Input : " << s << endl;
    URLify(s, 13);
    cout << "Output: " << s << endl;
    return 0;
}

