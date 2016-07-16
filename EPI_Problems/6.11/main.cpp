#include <stdlib.h> /* srand, rand */
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <queue>
#include <list>
#include <algorithm> /* iter_swap(v.begin() + delta1, v.begin() + delta2); */
#include <unordered_set>

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
    int pick;
    unordered_set<int> usedTable;
    vector<int> B;

    /* seed rand() */
    srand(time(NULL));

    int i=0;
    while(i<k){

        // get a new random index
        pick = rand() % A.size(); // note the range of R%n is 0,1,...,n-1

        // if pick isn't recorded as used, procede.
        if(usedTable.count(pick) == 0){
            B.push_back( A[pick] );
            usedTable.insert(pick);
            i++;
        }
    }
    return B;
}

vector<int> randSampInPlace(vector<int> A, int k){
    srand(time(NULL));
    int temp, pick, offset;
    offset=0;
    while(offset<k){
        pick = rand()%A.size() + offset;
        // swap A[offset] and A[pick]
        temp = A[offset];
        A[offset] = A[pick];
        A[pick] = temp;
        offset++;
    }
    vector<int> B(&A[0], &A[offset]); // vector constructor takes iterator (address/pointer)
    return B;
}

    void randSampTest(){
        int k;
        cout << "Pick a number less than 15: ";
        cin >> k;

        vector<int> A = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
        printv2(A, "Input A: ");
        printv2(randSamp(A, k),to_string(k)+" random elements of A: ");
        printv2(randSampInPlace(A, k),to_string(k)+" in place random elements of A: ");
    }

    int main(){
        randSampTest();
        return 0;
    }

