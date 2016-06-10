#include <iostream>
#include <limits>
using namespace std;

int main(){
                                                                                  // Ubuntu 16.04 LTS, Core i5-3470 3.2GHz 16GB
    cout << "size of bool: "        << sizeof(bool)        << " bytes." << endl;  // 1 bytes, 8 bits
    cout << "size of char: "        << sizeof(char)        << " bytes." << endl;  // 1 bytes, 8 bits
    cout << "size of short: "       << sizeof(short)       << " bytes." << endl;  // 2 bytes, 16 bits
    cout << "size of int: "         << sizeof(int)         << " bytes." << endl;  // 4 bytes, 32 bits
    cout << "size of long: "        << sizeof(long)        << " bytes." << endl;  // 8 bytes, 64 bits
    cout << "size of long long: "   << sizeof(long long)   << " bytes." << endl;  // 8 bytes, 64 bits
    cout << "size of float: "       << sizeof(float)       << " bytes." << endl;  // 4 bytes, 32 bits
    cout << "size of double: "      << sizeof(double)      << " bytes." << endl;  // 8 bytes, 64 bits
    cout << "size of long double: " << sizeof(long double) << " bytes." << endl;  // 16 bytes, 128 bits
    
    cout << "size of unsigned: "           << sizeof(unsigned)          << " bytes." << endl;  // 4 bytes, 32 bits
    cout << "size of unsigned long: "      << sizeof(unsigned long)     << " bytes." << endl;  // 8 bytes, 64 bits
    cout << "size of unsigned long long: " << sizeof(unsigned long long)<< " bytes." << endl;  // 8 bytes, 64 bits

    cout << "numeric_limits<int>::min(): " << numeric_limits<int>::min() << endl;
    cout << "numeric_limits<int>::max(): " << numeric_limits<int>::max() << endl;
    cout << "numeric_limits<float>::min(): " << numeric_limits<float>::min() << endl;
    cout << "numeric_limits<float>::max(): " << numeric_limits<float>::max() << endl;
    
    void *p;
    cout << "size of void pointer: " << sizeof(p)          << " bytes." << endl;  // 8 bytes, 64 bits
    return 0;
}
