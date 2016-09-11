#include <stdlib.h> /* srand, rand */
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <queue>
#include <list>
#include <unordered_map>
#include <algorithm>
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

void printM(vector<vector<int>> M){
    for( auto row : M ){
        for( auto cell : row ){
            cout << to_string(cell) << " ";
        }
        cout << endl;
    }
}


void setRow(vector<vector<int>> &M, int row){
    int n = M[0].size();
    for(int j=0; j < n; j++){
        M[row][j] = 0;
    }
}

void setCol(vector<vector<int>> &M, int col){
    int m = M.size();
    for(int i=0; i < m; i++){
        M[i][col] = 0;
    }
}

void zeroMatrix(vector<vector<int>> &M){
    int n, m;
    set<int> rowTable, colTable;

    n = M[0].size();
    m = M.size();
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if (M[i][j] == 0){
                rowTable.insert(i);
                colTable.insert(j);
            }
        }
    }

    for(auto it=rowTable.begin(); it!=rowTable.end(); it++){ setRow(M, *it); }
    for(auto it=colTable.begin(); it!=colTable.end(); it++){ setCol(M, *it); }
}



int main(){
    // input
    cout << "Input Matrix:" << endl;
    vector<vector<int>> M;
    M = {
        {0,1,1,1},
        {1,1,0,1},
        {1,1,1,1},
        {1,1,0,1}
    };
    printM(M);
    
    // output
    cout << "\nOutput:" << endl;
    zeroMatrix(M);
    printM(M);

    return 0;
}

