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
string getstr(int v);
int mystoi(string s);
int getint(char c);
int isNeg(int x);
void sreverse(string& s);

int main(){
   
    // test integer to string
    int val = -17381;
    int val2 = 0;
    cout << "Convert interger "<< val << " to string: '"<< myitos(val) << "'"<< endl;
    cout << "Convert interger "<< val2 << " to string: '"<< myitos(val2) << "'"<< endl;

    // test string to integer
    string s = "-42912";
    cout << "Convert string '"<<s<<"' to integer: "<< mystoi(s) << endl;


    // Other testing
    /*
    cout << "-128 is negative?: "<< isNeg(-128) << endl;
    cout << "127 is negative?: "<< isNeg(127) << endl;
    cout << (int)sizeof(s) << endl; // return type of sizeof() is 'size_t' 32 bytes
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

string myitos(int x){
    string signplace   = "";
    string significant = (x==0) ? "0" : "";  // corner case when x=0, while loop was skipped.
    int r = 0;
    string result ="";

    // determines signplace
    signplace = (x < 0) ? "-" : "";


    // conversion
    x = (x<0) ? -x : x; // x must be positive number for proper mod operation
    while(x != 0){
        r = x % 10; // r = 496 % 10 = 6 
        significant = significant + getstr(r);
        x = (x-r)/10; // (496-6)/10 = 49
    }

    // reuslt is reversed concatenated
    result = significant + signplace;
    sreverse(result);
    return result;
}

void sreverse(string& s){
    char l = 0;
    char r = s.size()-1;
    char tmp;
    while (l < r){
        tmp = s[l];
        s[l] = s[r];
        s[r] = tmp;
        l++;
        r--;
    }
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

string getstr(int v){
    char c;
    c = '0'+v;
    string s(1,c);
    return s;
}

int getint(char c){
    return c-'0';
}

int isNeg(int x){
    int y;
    y = (unsigned)x >> ((int)sizeof(x)*8-1); // extract the left most bit. unsigned x to not preserve sign. sizeof() returns size_t, cast to int.
    return y;
}
