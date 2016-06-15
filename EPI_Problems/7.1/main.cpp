#include <stdlib.h> /* srand, rand */
#include <cmath>    /* abs()       */
#include <typeinfo>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


/* Function Prototyes */
void printv(vector<int>& A);
string myitos(int x);
int mystoi(string s);
int getint(char c);

int main(){
    string s = "-65550";
    cout << "Input string: " << s << " is type: " << typeid(s).name() << endl;
    // string to integer
    cout << "mystoi output: "  << mystoi(s) << " is type: " << typeid(mystoi(s)).name() << endl;

    // integer to string

    
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
    string significant="";
    int signMultiplier=1;

    // evaluate the sign and the significant part of the string
    if (s[0] == '-'){
        signMultiplier = -1;
        significant    = s.substr(1, string::npos);
    }else{
        signMultiplier = 1;
        significant    = s;
    }
    
    // start conversion
    exp = significant.size()-1;
    for(place=0; place < significant.size(); place++){
        result = result + getint(significant[place])*pow(10, exp);
        exp--;
    }

    return signMultiplier*result;
}

int getint(char c){
    return c-'0';
}
