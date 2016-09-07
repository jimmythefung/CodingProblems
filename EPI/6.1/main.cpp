#include <stdlib.h> /* srand, rand */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* Function Prototyes */
void dutchPartition(vector<int>& A, int i);
void swap(int& left, int& right);
void quicksort(vector<int>& A, int start, int end);
int partitionCLRS(vector<int>& A, int start, int end);
void printvector(vector<int>& A);


int main(){
    vector<int> A;
    vector<int> B = {5,1,10,2,9,5,3,8,5};

    // Print B
    cout << "Array B: ";
    printvector(B);
    // dutch partition B:
    dutchPartition(B,0);
    cout << "Array B dutch partitioned: ";
    printvector(B);
    
    // initialize A to random array of 10 elements
    srand (time(NULL));
    for (int i=0; i < 10; i++){
        A.push_back(rand()%11);
    }
    
    // print A
    //cout << "Generated integers: ";
    //printvector(A); 

    return 0;
}

void dutchPartition(vector<int>& A, int ind){
    int pivot;
    int i, j, k;
    pivot = A[ind];
    i = 0;
    j = k = A.size()-1;
    
    while(i<j){
        
        // Current element is greater than the pivot
        if (A[i] > pivot)
        {
            j--;                // push ==boundary left
            swap(A[j], A[k]);   // A[k] is an =p element, fit it in A[j]
            swap(A[i], A[k]);   // A[k] is undetermined element, replace it with A[i] the >p
            k--;                // push >boundary left
            
        }
        // current element is less than the pivot
        else if (A[i] < pivot)
        {
            i++;
        }
        // current element is equal to the pivot
        else
        {
            if (A[j]!=pivot)      // corner case - uninitialized "==boundary". Implicitly also, j=k.
            {
                swap(A[i], A[j]); // Ensure A[j] and A[k] must be an element == pivot
            }
            else
            {
                j--;              // normal case: push ==boundary left, then swap
                swap(A[i],A[j]);
            }
        }


    }



}
void swap(int& left, int& right){
    int temp;
    temp = left;
    left = right;
    right = temp;
}

void quicksort(vector<int>& A, int start, int end){

    if (start < end){
        int partition_index;
        partition_index = partitionCLRS(A, start, end);
        quicksort(A, start, partition_index-1);
        quicksort(A, partition_index+1, end);
    }
}

int partitionCLRS(vector<int>& A, int start, int end){
    int pivot;
    int left, right;

    pivot = A[end];
    left = start - 1;
    for (right=start; right < end; right++){
        if (A[right] <= pivot){
            left++;
            swap(A[left], A[right]);
        }
    }
    swap(A[left+1], A[right]);
    return left+1;
}


void printvector(vector<int>& A){
    vector<int>::iterator it;
    for(it=A.begin(); it<A.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
