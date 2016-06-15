#include <stdlib.h> /* srand, rand */
#include <cmath>    /* abs()       */
#include <typeinfo>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


/* Function Prototyes */
void printv(vector<int>& A);
int mystoi(string s);
int getint(char c);

int main(){
    string s = "65550";
    cout << "Input string: " << s << " is type: " << typeid(s).name() << endl;
    cout << "mystoi output: "  << mystoi(s) << " is type: " << typeid(mystoi(s)).name() << endl;

    /*
    int c;
    c = s[0]-'0';
    cout << c << endl;
    cout << "Type of string is: " << typeid("string").name() << endl;
    cout << "Type of int is: " << typeid(c).name() << endl;
    cout << "size of int is: " << sizeof(c) << endl;
    */
    return 0;
}

void printv(vector<int>& A){
    vector<int>::iterator it;
    for(it=A.begin(); it<A.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}


int mystoi(string s){
    int exp;
    unsigned place;  // s.size() is unsigned. So use unsigned for place
    int result=0;

    exp = s.size()-1;
    for(place=0; place < s.size(); place++){
        result = result + getint(s[place])*pow(10, exp);
        exp--;
    }
    return result;
}

int getint(char c){
    return c-'0';
}
