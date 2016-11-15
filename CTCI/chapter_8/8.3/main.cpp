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

void magicIndexHelper(vector<int> A, int start, int end, int &result){
    int m;
    m = (end-start)/2 + start;
    cout << "m=" << m << ", A[m]=" << A[m] << endl;


    // solution already found. Exit recursion
    if (result != -1){
        return;
    }

    // case 1: middle index is solution
    if (A[m]==m){
        result = m;
        return;
    }

    // base case
    if (start == end){
        return;
    }

    // case 2: A[m]>m, must search left
    if (A[m]<m){
        magicIndexHelper(A, m+1, end, result);
    }

    // case 3: A[m]<m, must search right
    if (A[m]>m){
        magicIndexHelper(A, start, m-1, result);
    }

}



int magicIndex(vector<int> A){
    int result = -1;
    magicIndexHelper(A, 0, A.size()-1, result);
    return (result==-1)? -1 : result;
}


int main(){
    vector<int> A = {-2,-1,0,1,2,3,4,7,11,30}; // 7 is the magic index
    cout << "Magic Index: " << magicIndex(A) << endl; // expected: 7
    return 0;
}

