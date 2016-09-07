#include <stdlib.h> /* srand, rand */
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

bool isPalindromePerutation(string s){
    // hash map declaration: unordered_map<key_type, value_type> varname
    unordered_map<char, unsigned int> char_count;

    // build hash table to map characters to frequency
    for (char c : s){
        ++char_count[c];
    }
    // string is even length
    if (s.size()%2==0){
        for(auto c : char_count){       // traverse hashtable
            if (c.second%2 != 0){       // frequency is not even
                return false;
            }
        }
        return true;                    // no odd characters
    }

    // string is odd length
    else{
        int oddcount = 0;
        for (auto c : char_count){
            if (c.second%2!=0){         // frequency is odd
                oddcount++;
                if (oddcount > 1){      // more than 1 odd frequency invalidates palindrome
                    return false;
                }
            }
        }
        return true;
    }
}

void palindromeTest(){

    string s1 = "edified";  // spelling backward is not palindrome, but has the palindrome permutation
    string s2 = "rotator";
    string s3 = "game";
    string s4 = "false";
    cout << s1 <<": "  << isPalindromePerutation(s1)  << endl;
    cout << s2 <<": "  << isPalindromePerutation(s2)  << endl;
    cout << s3 <<": "  << isPalindromePerutation(s3)  << endl;
    cout << s4 <<": "  << isPalindromePerutation(s4)  << endl;
}

int main(){
    //palindromeTest();

    /*
    set<string>::value_type s; // see chapter 11.3 - operatiosn on associative containers
    s = "mystring"; // this shows that set<string>::value_type is string. There's also key_type, mapped_type
    cout << s << endl;
    */
    return 0;
}

