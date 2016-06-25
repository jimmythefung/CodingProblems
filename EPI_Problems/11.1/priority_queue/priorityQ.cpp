#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <functional>

using namespace std;

template<typename T>
void printq(T& q){
    while(!q.empty){
        cout << q.top() << endl;
        q.pop();
    }
}

int main(){

    // different ways to define lambda function, declared by []
    auto cmp = [](int x, int y) {return x > y;};
    auto cmp2 = [] (int x, int y) -> bool {return x > y;};
    bool cmp3 = [](int x, int y) {return x > y;};
    function<bool (int, int)> cmp4 = [](int x, int y) {return x > y;};
    priority_queue<int, vector<int>, function<bool (int, int)>> pq( [](int x, int y) -> bool {return x > y;} );

    
    pq.push(4);
    pq.push(2);
    pq.push(9);
    pq.push(1);
    pq.push(5);
    
    
    while (!pq.empty()){
        cout << pq.top() << endl;
        pq.pop();
    }
    

    /*
    priority_queue<string*, vector<string*>, function<bool (const string* const &, const string* const &)>> pq ([](const string* const &s1, const string* const &s2)->bool{return s1 < s2;}); 
    string* s1 = new string("4");
    string* s2 = new string("2");
    pq.push(s1);
    pq.push(s2);
    printq(pq);
    */
    /*
    priority_queue<int> q;
    q.push(4);
    cout << q.top() << endl;
    */
    return 0;
}

