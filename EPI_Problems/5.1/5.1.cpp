#include <iostream>
using namespace std;

int CountBits(unsigned long long x);
int computeParity(unsigned long long x);
int computeParity2(unsigned long long x);

int main(){
    unsigned long long v; // create some value whose parity to be tested
    int parity;             // holds the parity

    cout << "Enter a number to compute its parity: " << endl;
    cin >> v;
    parity = computeParity2(v);
    cout << "The parity of " << v << " is: " << parity << endl;

    return 0;
}

int CountBits(unsigned long long x){
    int num_bits = 0; // counter of number of bits
    while (x){
        num_bits = num_bits + (x & 1);
        x = x >> 1;
    }
    return num_bits;
}

int computeParity(unsigned long long x){
    int n = 0;
    int parity = 0;
    
    // Compute number of set bits in x
    n = CountBits(x);
    
    if ((n%2)==1){
        parity = 1;
    }else{
        parity = 0;
    }
    
    return parity;
}

int computeParity2(unsigned long long x){
    unsigned long long y;
    int i=0;
    while (x){
        y = x & ~(x-1);
        x = x ^ y;
        i++;
    }

    return (i%2==1) ? 1:0;
}


