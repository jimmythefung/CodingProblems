#include <stdlib.h> /* srand, rand */
#include <cmath>    /* abs()       */
#include <iostream>
#include <string>
#include <vector>
using namespace std;


/* Function Prototyes */
void printv(vector<int>& A);

int main(){

    return 0;
}

void printv(vector<int>& A){
    vector<int>::iterator it;
    for(it=A.begin(); it<A.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
