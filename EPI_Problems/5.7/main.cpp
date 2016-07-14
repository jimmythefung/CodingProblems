#include <stdlib.h> /* srand, rand */
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <queue>
#include <list>
#include <unordered_map>

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

double pow_Oy(double x, int y){
    double result=x;
    for(int i=1; i < y; i++){
        result = result * x;
    }
    return result;
}

void pow_OyTest(){
    double x;
    int y;
    cout << "Enter a double (x): ";
    cin >> x;
    cout << "Enter a integer (y): ";
    cin >> y;
    cout << "pow_On(" << x << "," << y << ") is: " << pow_Oy(x,y) << endl;
}


int get_y2k(int y){
    int b = 1;
    while (b <= y){
        b = b << 1;
    }
    return b >> 1; // return b=2^k closest to, but less than, y
}
double pow_Ology(double x, int y, unordered_map<int, int> cache){
    
    // base case exponent is 0
    if (y==0){ return 1; }

    // base case exponent is 1
    if (y==1){ return x; }

    // base case exponent is in cache
    if (cache.count(y)!=0){ return cache[y]; }

    // Ensure y is of the form: y^2k
    int two_k = get_y2k(y);
    if (y==two_k){    
        // x^y = x^(y/2) + x^(y/2)
        cache[y] = pow_Ology(x,y/2,cache) * pow_Ology(x,y/2,cache);
    }else{
        // x^y = x^(y - 2^k + 2^k)
        //     = x^(y - 2^k) * x^(2^k)
        cache[y] = pow_Ology(x, y-two_k, cache) * pow_Ology(x, two_k, cache);
    }
    return cache[y];
}


void pow_OlogyTest(){
    unordered_map<int, int> cache;
    double x;
    int y;
    cout << "Enter a double (x): ";
    cin >> x;
    cout << "Enter a integer (y): ";
    cin >> y;
    cout << "pow_Ology(" << x << "," << y << ") is: " << pow_Ology(x,y,cache) << endl;
}

int main(){
    //pow_OyTest();
    pow_OlogyTest();
    return 0;
}

