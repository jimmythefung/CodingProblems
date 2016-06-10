#include <iostream>
using std::cin;
using std::cout;
using std::endl; // end line - flush buffer to stream object

int main(){
    int v1 = 0;
    int v2 = 0;
    cout << "hello world!" << endl;
    cout << "Enter 2 numbers:" << endl;
    cin >> v1 >> v2;
    cout << "The sum of " << v1 << " and " << v2
        << " is " << v1+v2 << endl;
    return 0;
}
