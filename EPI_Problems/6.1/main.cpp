#include <iostream>
#include <string>
#include <vector>
using namespace std;

void swap(int *left, int *right);

int main(){
    vector<int> A{0,1,2,3};
    
    // print original list
    cout << A[0] << A[1] << A[2] << A[3] << endl;
    
    // swap pointer
    swap(&A[0], &A[3]);
    cout << A[0] << A[1] << A[2] << A[3] << endl;
    return 0;
}

void swap(int *left, int *right){
    int temp;
    temp = *left;
    *left = *right;
    *right = temp;
}
