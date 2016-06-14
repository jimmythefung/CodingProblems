#include <stdlib.h> /* srand, rand */
#include <cmath>    /* abs()       */
#include <typeinfo>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


/* Function Prototyes */
void printv(vector<int>& A);
int stoi(string s);
int getint(char c);

int main(){
    string s = "123";
    int c;


    c = s[0]-'0';
    cout << c << endl;
    cout << "Type of string is: " << typeid("string").name() << endl;
    cout << "Type of int is: " << typeid(c).name() << endl;
    cout << "size of int is: " << sizeof(c) << endl;
    return 0;
}

void printv(vector<int>& A){
    vector<int>::iterator it;
    for(it=A.begin(); it<A.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}


int stoi(string s){
    int exp;
    int place;
    int result=0;

    exp = s.size()-1;
    for(place=0; place < s.size(); place++){
        result = result + getint[place]*pow(10,exp);
        exp--;
    }
    return result;
}

int getint(char c){
    return c-'0';
}
