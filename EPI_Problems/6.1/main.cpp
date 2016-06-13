#include <stdlib.h> /* srand, rand */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* Function Prototyes */
void dutchSort(vector<int>& A, int i);
void swap(int& left, int& right);
void quicksort(vector<int>& A, int start, int end);
int partitionCLRS(vector<int>& A, int start, int end);
void printvector(vector<int>& A);


int main(){
    vector<int> A;
    srand (time(NULL));
    for (int i=0; i < 10; i++){
        A.push_back(rand()%11);
    }
    
    // print original list
    cout << "Generated integers: ";
    printvector(A); 

    // dutchsort
    cout << "Pivot at index=4, A[4] = " << A[4] << endl;
    dutchSort(A, 4);
    cout << "Dutch Sorted integers: ";
    printvector(A); 

    //int q;
    //q = partitionCLRS(A, 0, A.size()-1);
    //cout <<"partition returns: " << q << endl;
    //quicksort(A, 0, A.size()-1);
    //printvector(A);

    return 0;
}

void dutchSort(vector<int>& A, int i){
    swap(A[i], A[A.size()-1]);
    quicksort(A, 0, A.size()-1);
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
        cout << *it;
    }
    cout << endl;
}
