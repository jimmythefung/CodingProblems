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


bool checkD(int row, int col, vector<vector<int>> M){
    int m=M[0].size();  // number of rows    <= m-1
    int n=M.size();     // number of columns <= n-1
    int curr, next;

    while(true){
        curr = M[col][row];
        col++;
        row++;
        if( col<n && row<m ){
            next = M[col][row];
            if( curr!=next ){
                return false;
            }
        }
        else{
            break;
        }
    }
    return true;
}

bool isToepliz(vector<vector<int>> M){
    int m=M[0].size();  // number of rows    <= m-1
    int n=M.size();     // number of columns <= n-1

    // horizontal-percolation at row=0
    for(int col=0; col<n; col++){
        if(!checkD(0, col, M)){ return false; }
    }

    // vertical-percolation at col=0 
    for(int row=0; row<m; row++){
        if(!checkD(row, 0, M)){ return false; }
    }

    // passed both test
    return true;
}

void printM(vector<vector<int>> M){
    int m = M[0].size();
    int n = M.size();
    for(int row=0; row<m; row++){
        for(int col=0; col<n; col++){
            cout << M[col][row] << " ";
        }
        cout << endl;
    }
}

void isToeplizTest(){
    vector<vector<int>> M = {
        {6,7,8,9,2},
        {4,6,7,8,9},
        {1,4,6,7,8},
        {0,1,4,6,7}
    };
    cout << "Input matrix, M:" << endl;
    printM(M);
    cout << "Is M toepliz? " <<(isToepliz(M)? "true":"false") << endl;
}

int main(){
    isToeplizTest();
    return 0;
}

