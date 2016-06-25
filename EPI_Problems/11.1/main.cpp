#include <stdlib.h> /* srand, rand */
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <queue>
using namespace std;

void printMatrix(vector<vector<int>> &m){
    for(vector<int> v : m){
        for(int ele : v){
            cout << ele << " ";
        }
        cout << endl;
    }
}


int main(){
    vector<int> v1 = {0, 5, 8};
    vector<int> v2 = {1, 9, 13, 19};
    vector<int> v3 = {4, 2, 8, 6};

    vector<vector<int>> m = {v1, v2, v3};
    printMatrix(m);
    return 0;
}
