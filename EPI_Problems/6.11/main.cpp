#include <stdlib.h> /* srand, rand */
#include <ctime>
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


vector<int> randSamp(vector<int> A, int k){
    vector<int> B = A;
    return B;
}

void randSampTest(){
    vector<int> A = {2,5,3,1,6};
    printv2(A);
}

int main(){
    randSampTest();
    return 0;
}

