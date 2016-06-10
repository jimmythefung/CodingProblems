#include <iostream>
using namespace std;

int main(){
                                                                                  // Ubuntu 16.04 LTS, Core i5-3550 16GB
    cout << "size of bool: "        << sizeof(bool)        << " bytes." << endl;  // 1 bytes
    cout << "size of char: "        << sizeof(char)        << " bytes." << endl;  // 1 bytes
    cout << "size of short: "       << sizeof(short)       << " bytes." << endl;  // 2 bytes
    cout << "size of int: "         << sizeof(int)         << " bytes." << endl;  // 4 bytes
    cout << "size of long: "        << sizeof(long)        << " bytes." << endl;  // 8 bytes
    cout << "size of long long: "   << sizeof(long long)   << " bytes." << endl;  // 8 bytes
    cout << "size of float: "       << sizeof(float)       << " bytes." << endl;  // 4 bytes
    cout << "size of double: "      << sizeof(double)      << " bytes." << endl;  // 8 bytes
    cout << "size of long double: " << sizeof(long double) << " bytes." << endl;  // 16 bytes
    
    void *p;
    cout << "size of void pointer: " << sizeof(p)          << " bytes." << endl;  // 8 bytes
    return 0;
}
