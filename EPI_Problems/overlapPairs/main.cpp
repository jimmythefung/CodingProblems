#include <stdlib.h> /* srand, rand */
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <queue>
#include <list>
#include <unordered_map>
using namespace std;

template <typename T> 
void printv2(vector<T> v, const string &s=string("Printing vector: ")){
    // s is a const& - constant reference;
    //   -content of s is constant; content can not be changed through s 
    //   -s is a reference, so no copying
    //   -In effect: Use s directly with no danger of mutation

    cout << s;
    for(auto it=v.begin(); it!=v.end(); it++){
        cout << *it << ", ";
    }
    cout << endl;
}

string AtoS(vector<string> A){
    string s;
    for(string c:A){
        s=s+c;
    }
    return s;
}


deque<deque<string>> overlap(vector<string> A, unordered_map<string, deque<deque<string>>> &cache){
    deque<string> q;
    deque<deque<string>> Qin, Qout;
    vector<string> v(A.begin()+1, A.end());

    if(A.size()==1){
        q.push_back(A[0]);
        Qout.push_back(q);
        return Qout;
    }
    else if (cache.count(AtoS(A))!=0){
        return cache[AtoS(A)];
    }

    Qin = overlap(v, cache);

    q.push_front(AtoS(A));
    Qout.push_front(q);
    for(auto it=Qin.begin(); it!=Qin.end(); it++){
        q = *it;
        q.push_front(A[0]);
        Qout.push_front(q);
    }
    
    cache[AtoS(A)] = Qout;
    return Qout;
}

deque<deque<string>> helper(vector<string> A){
    string firstLetters;
    deque<deque<string>> Qin, Qout;
    unordered_map<string, deque<deque<string>>> cache;
    int i=0;
    while(i<A.size()-1){ // split A into L, R: A=[abcd] vL=[a] vR=[bcd], each loop move 1 letter to vL from vR
        vector<string> vL(A.begin(), A.begin()+1+i);
        vector<string> vR(A.begin()+1+i, A.end());
        
        firstLetters = AtoS(vL);
        Qin = overlap(vR, cache); //firstLetters=(a), Qin=[ (bcd), (b,cd), (b,c,d) ] and so on
        for(auto q=Qin.begin(); q!=Qin.end(); q++){
            (*q).push_front(firstLetters); //(a)(bcd), (a)(b,cd), (a)(b,c,d)
            Qout.push_back(*q);
        }
        i++;
    }
    return Qout;
}




int main(){
    vector<string> A = {"a", "b", "c", "d"};
    deque<deque<string>> Q = helper(A);
    for(auto q=Q.begin(); q!=Q.end(); q++){
        for(auto e:(*q)){
            cout << "(" << e << ")";
        }
        cout << endl;
    }
    return 0;
}

