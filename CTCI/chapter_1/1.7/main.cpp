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

void printM(vector<vector<int>> M){
    for( auto row : M ){
        for( auto cell : row ){
            cout << to_string(cell) << " ";
        }
        cout << endl;
    }
}

void RotateCell(vector<vector<int>> &M, vector<int> a, vector<int> b, vector<int> c, vector<int> d){
    int temp;
    temp = M[b[0]][b[1]];                  // b -> t
    M[ b[0] ][ b[1] ] = M[ a[0] ][ a[1] ]; // a -> b
    M[ a[0] ][ a[1] ] = M[ c[0] ][ c[1] ]; // c -> a
    M[ c[0] ][ c[1] ] = M[ d[0] ][ d[1] ]; // d -> c
    M[ d[0] ][ d[1] ] = temp;              // a -> b
}

void RotateMatrix(vector<vector<int>> &M){
    int N = M.size()-1;
    vector<int> a, b, c, d;
    int ar, ac, br, bc, cr, cc, dr, dc;
    int i, j, right_wall;

    for(int left_wall=0; left_wall < N/2; left_wall++){
        right_wall = N-left_wall;
        i = left_wall;
        while (i < right_wall){ // i starts from left wall.
            j = N-i;            // j starts from right wall, opposite of i.
                                // So they close in on each other

            ar = left_wall; // left_wall is the first row, just imagine rotate M cc by 90 degree.
            ac = i;
            a = {ar, ac};

            br = i;
            bc = right_wall;
            b = {br, bc};

            cr = j;
            cc = left_wall;
            c = {cr, cc};

            dr = right_wall;
            dc = j;
            d = {dr, dc};

            RotateCell(M, a, b, c, d);
            i++;
        }
    }
}



int main(){
    // input
    cout << "Input Matrix:" << endl;
    vector<vector<int>> M;
    M = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    printM(M);
    
    // rotate
    cout << "\nRotated Matrix:" << endl;
    RotateMatrix(M);
    printM(M);
    return 0;
}

