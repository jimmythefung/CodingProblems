#include <stdlib.h> /* srand, rand */
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <queue>
#include <list>
#include <map>
#include <set>
using namespace std;

void orderedMapTest(){
    //pair<int, int> p = make_pair(1,2); // the map uses a pair<> container under the hood just like this
    map<char, int> word_count;
    string word;
    cout << "Enter some words. Send EOF by 'Ctrl + D'" << endl;
    while(cin >> word){
        for (char c:word){
            ++word_count[c];
        }
    }
    for (auto w:word_count){ // use ctrl+d to send EOF on keyboard
        cout << w.first << " occurs " << w.second << " times" << endl;
    }
}

int main(){
    orderedMapTest();
    return 0;
}

