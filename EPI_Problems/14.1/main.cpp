#include <stdlib.h> /* srand, rand */
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <queue>
#include <list>
#include <set>

using namespace std;

vector<int> intersection(vector<int> &A, vector<int> &B){
    vector<int> r;
    unsigned int a=0, b=0;

    while (true){
        if(A[a]==B[b]){
            r.push_back(A[a]);
            a++;
            b++;
        }
        else{
            A[a] < B[b] ? a++ : b++;
        }

        if ( (a>A.size()-1) || (b>B.size()-1) ){
            return r;
        }
    }
}

vector<int> intersection2(const vector<int>& A, const vector<int>& B){
    set<int> s;
    vector<int> r;

    for( auto it=A.begin(); it!=A.end(); it++){
        s.insert(*it);
    }

    for( auto it=B.begin(); it!=B.end(); it++){
        if (s.find(*it)!=s.end()){
            r.push_back(*it);
        }
    }
    return r;
}


template <typename T> 
void printv2(vector<T> v, const string &s=string("Printing vector: ")){
    // s is a const& - constant reference; content of s is constant 
    //   and s is refereced so no copying

    cout << s;
    for(auto it=v.begin(); it!=v.end(); it++){
        cout << *it << ", ";
    }
    cout << endl;
}

void printv(vector<int> v){
    cout << "Print vector: ";
    for(auto it=v.begin(); it!=v.end(); it++){
        cout << *it << ", ";
    }
    cout << endl;
}

void intersectTest(){
    vector<int> A = {1,3,5,7,  9,   11,   13};
    vector<int> B = {1,2,4,6,8,9,10,11,12,13};
    vector<int> I = intersection(A, B);
    printv2(A, "Input  A: ");
    printv2(B, "Input  V: ");
    printv2(I, "Output I: ");
}

void intersectTest2(){
    vector<int> A = {1,3,5,7,  9,   11,   13};
    vector<int> B = {1,2,4,6,8,9,10,11,12,13};
    vector<int> I = intersection2(A, B);
    printv2(A, "Input  A: ");
    printv2(B, "Input  V: ");
    printv2(I, "Output I: ");
}

int main(){
    //intersectTest();
    intersectTest2();
    return 0;
}

