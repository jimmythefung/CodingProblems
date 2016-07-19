#include <stdlib.h> /* srand, rand */
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <queue>
#include <list>
#include <unordered_set>
#include <set>
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




set<set<string>> Comb(string s, int k, set<set<string>> &nCk){
    if(k==0){return nCk;}

    for(set<string> choosingSet:nCk){ // the value of the element in a set cannot be modified once in the container
        nCk.erase(choosingSet);       // so erase first
        for(char c:s){
            
            // convert char to string, save in "ctos"
            string ctos(1, c);
            
            // modify choosingSet with new character insertion, and check for successful insertion
            bool insertResult = choosingSet.insert(ctos).second; // true=new element, false = existing

            if (insertResult!=false){
                nCk.insert(choosingSet);  // re-insert choosing set back into (n choose k)
            }
           

            // Continue with picking, until the k'th choose
            Comb(s, k-1, nCk);
        }
    }

    return nCk;
}


set<set<string>> CombHelper(string s, int k){
    set<set<string>> nCk;
    for(char c:s){                      //  (string c:s) fails - can't directly convert char, c, to string
        set<string> choosingSet;
        string ctos(1,c);
        choosingSet.insert(ctos);
        nCk.insert(choosingSet);
    }
    Comb(s, k-1, nCk);
    return nCk;
}

void CombTest(){
    string s = "abcde";
    int k = 4;
    set<set<string>> result = CombHelper(s, k);
    cout << "Printing set<set<string>>: ";
    for(auto e:result){
        for(auto c=e.begin(); c!=e.end(); c++){ // careful: c is an interation (or pointer to char, i.e. char*
            cout << *c;
        }
        cout << ", ";
    }
    cout << endl;
}

int main(){
    CombTest();
    return 0;
}

