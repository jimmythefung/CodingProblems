#include <stdlib.h> /* srand, rand */
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <queue>
#include <list>
using namespace std;

void printv(vector<int> v){
    cout << "Input: ";
    for(auto it = v.begin(); it!=v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

int search(vector<int> A, int x){
    int l, r, m;
    l = 0;
    r = A.size()-1;
    m = (r-l)/2 + l;

    while ( l <= r){

        if (A[m] == x){ return m;}
        else if (x > A[m]){
            l = m+1;
            m = (r-l)/2 + l;
        }else{
            r  = m-1;
            m = (r-l)/2 + l;
        }
    }

    // not found
    return -1;
}

int rSearch(vector<int> A, int x, int l, int r){
    if (l > r){
        return -1;
    }

    int m = (r-l)/2+l;
    if (A[m]==x){
        return m;
    }
    else if(x > A[m]){
        return rSearch(A, x, m+1, r);
    }
    else{
        return rSearch(A, x, l, r-1);
    }
}

void binarySearchTest(){

    vector<int> A = {0,1,2,3,4,5,7,8,9};
    printv(A);

    for(decltype(A.size()) i=0; i!=A.size(); i++){
        cout << "Procedural searching " << i << ". Index at: "; 
        cout << search(A,i) << endl;
    }
    for(decltype(A.size()) i=0; i!=A.size(); i++){
        cout << "Recursive Searching " << i << ". Index at: "; 
        cout << rSearch(A, i, 0, A.size()-1) << endl;
    }
}

int dupSearch(vector<int> A, int x){
    int L, R, M, i;
    i = -1;
    L = 0;
    R = A.size()-1;
    M = (R-L)/2 + L;

    while (L <= R){

        if(x==A[M]){
            i = M;
            R = M - 1;
        }
        else if( x < A[M] ){
            R = M - 1;
        }
        else {
            L = M + 1;
        }

        M = (R-L)/2 + L;
    }
    return i;
}

void dupSearchTest(){
    int n=108, n2=285;
    vector<int> v = {-14, -10, 2, 108, 108, 243, 285, 285, 285, 401};
    
    cout << "Dup-Search " << n << ". Index at: ";
    cout << dupSearch(v, n) << endl;
    
    cout << "Dup-Search " << n2 << ". Index at: ";
    cout << dupSearch(v, n2) << endl;
}

int main(){
    //binarySearchTest();
    dupSearchTest();
    return 0;
}

