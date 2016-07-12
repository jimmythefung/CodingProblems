#include <stdlib.h> /* srand, rand */
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <queue>
#include <list>
#include <unordered_map>
#include <algorithm> // max()

using namespace std;

int MaxMidArray(vector<int> A, int start, int end){
    int lsum, rsum, accum; // l/r sum, accumulator
    lsum = rsum = accum = 0;
    int M = start + (end-start)/2;

    // start summing left from center
    for (int i=M; i>=start; i--){
        accum = accum + A[i];
        if (accum > lsum){lsum = accum;}
    }
    
    // start summing right from center
    accum = 0;
    for (int i=M+1; i<=end; i++){
        accum = accum + A[i];
        if (accum > rsum){rsum = accum;}
    }

    return lsum + rsum;
}
// maximum subarray - O(nlogn) - divide and conqure
int MSA(vector<int> A, int start, int end){

    // base case - only 1 element
    if (start >= end){
        return A[start];
    }

    int L, M, R, a,b,c;
    L = start;
    R = end;
    M = L + (R-L)/2;

    // a,b,c are maximum sum subarray of left half, cross-center, right half
    // because the MSA is only located in one of these 3 possibilities intervals.
    a = MSA(A, L, M);
    b = MaxMidArray(A, start, end);
    c = MSA(A, M+1, R);

    return max( max(a,b), c);
}




// maximum subarray - O(n)- Dynamic Programming solution; see page 298
int MSA_dp(vector<int> A, int start, int end){

    vector<int> sumA(A.size());
    int tempSum = 0;
    int i=0;
    // initialize sumA to be the sum of A up to index i: 0 -> A.size()-1
    while(i < A.size()){
        tempSum = tempSum + A[i];
        sumA[i] = tempSum;
        i++;
    }

    // keeps track of max and min of sumA so far (up to index i)
    int maxDelta, maxSeen, minSeen;
    maxDelta = maxSeen = minSeen = 0;
    i=0;
    while(i < sumA.size() ){
        if(sumA[i] > maxSeen){
            maxSeen=sumA[i];
        }
        if(sumA[i] < minSeen){
            minSeen=sumA[i];
        }
        if( (maxSeen - minSeen) > maxDelta){
            maxDelta = (maxSeen - minSeen);
        }
        i++;
    }
    return maxDelta;
}


// Fibinacci - DP; f(n)=f(n-1)+f(n-2) where f(0)=0, f(1)=1
int fib(int n, unordered_map<int, int> &cache){

    if (n<2){
        cache[n] = n;
        return n;
    }
    // add to cache if f(n) not already saved
    else{
        return cache[n] = fib(n-1, cache) + fib(n-2, cache);
    }
}



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

void fibTest(){
    unordered_map<int, int> cache;
    for(int x=0; x < 10; x++){
        cout << "Fib("<< x <<"): " << fib(x, cache) << endl;
    }
}




void MSATest(){
    vector<int> A = {904, 40, 523, 12, -335, -385, -124, 481, -31};
    cout << MSA(A, 0, A.size()-1) << endl;
}

void MSA_dpTest(){
    vector<int> A = {904, 40, 523, 12, -335, -385, -124, 481, -31};
    cout << MSA_dp(A, 0, A.size()-1) << endl;
}



int main(){
    //fibTest();
    //MSATest();
    MSA_dpTest();
    return 0;

}

