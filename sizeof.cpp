#include <iostream>
using namespace std;

int main(){

    void *p;

    cout << "size of bool: "        << sizeof(bool)      << " bytes." << endl;
    cout << "size of char: "        << sizeof(char)      << " bytes." << endl;
    cout << "size of short: "       << sizeof(short)     << " bytes." << endl;
    cout << "size of int: "         << sizeof(int)       << " bytes." << endl;
    cout << "size of long: "        << sizeof(long)      << " bytes." << endl;
    cout << "size of long long: "   << sizeof(long long) << " bytes." << endl;
    cout << "size of float: "       << sizeof(float)     << " bytes." << endl;
    cout << "size of double: "      << sizeof(double)    << " bytes." << endl;
    cout << "size of long double: " << sizeof(long double) << " bytes." << endl;
    
    cout << "size of void pointer: " << sizeof(p) << " bytes." << endl;
    return 0;
}
