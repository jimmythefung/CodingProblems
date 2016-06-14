#include <stdlib.h> /* srand, rand */
#include <cmath>    /* abs()       */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> prices_CLRS = {100, 113, 110, 85, 105, 102, 86, 63, 81, 101, 94, 106, 101, 79, 94, 90, 97};
vector<int> prices_EPI = {310, 315, 275, 295, 260, 270, 290, 230, 255, 250};


/* Function Prototyes */
int getProfit(vector<int>& A);
void printv(vector<int>& A);

int main(){

    printv(prices_CLRS);
    cout << "Profit:  " << getProfit(prices_CLRS) << endl;
    printv(prices_EPI);
    cout << "Profit:  " << getProfit(prices_EPI) << endl;

    return 0;
}

int getProfit(vector<int>& A){
    int currentProfit;
    int bestProfit=0;      // not buying and selling beats buying then sold for a loss, for starter.
    int minPriceSeen=A[0]; // because the loop below starts at i=1, the 2nd element.
    
    for(int i=1; i < A.size(); i++){

        currentProfit = A[i] - minPriceSeen;
        if (currentProfit > bestProfit){
            bestProfit = currentProfit;
        }

        if (A[i] < minPriceSeen){
            minPriceSeen = A[i];   
        }
    }
    return bestProfit;
}

void printv(vector<int>& A){
    vector<int>::iterator it;
    for(it=A.begin(); it<A.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
