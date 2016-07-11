#include <stdlib.h> /* srand, rand */
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <queue>
#include <list>
#include <stack>
#include <map>

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

struct peg{
    string name;
    stack<int> p;

    // constructor
    peg(string s, int h){
        name = s;
        for (int i=h; i!=0; i--){
            p.push(i);
        }
    }
};

struct tower{
    peg *A, *B, *C;
    int height;

    tower(int h){
        A = new peg("A",h);
        B = new peg("B",0);
        C = new peg("C",0);
        height = h;
    }

    ~tower(){
        delete(A);
        delete(B);
        delete(C);
    }

    void moveTower(peg &SRC, peg &DEST, peg &HELP, int n){
        if(n==0){return ;}
        // 1 peg left from source
        if (n==1){
            moveApeg(SRC, DEST);
            return ;
        }

        // Move n-1 pegs from source-tower to helper-tower
        //cout << SRC.name << " -> " << HELP.name << endl;
        moveTower(SRC, HELP, DEST, n-1);

        // Move nth (last) peg from source tower to final tower
        //cout << SRC.name << " -> " << DEST.name << endl;
        moveTower(SRC, DEST, HELP, 1);

        // Move n-1 pegs from helper-tower to destination tower
        //cout << HELP.name << " -> " << SRC.name << endl;
        moveTower(HELP, DEST, SRC, n-1);
    }

    void moveApeg(peg &SRC, peg &DEST){
        // safty check - ensure peg insertion is legitimate
        // check destination tower is not empty
        cout << SRC.name << " -> " << DEST.name << endl;
        if (!DEST.p.empty()){
            if (SRC.p.top() < DEST.p.top()){ // check smaller peg is placing on top of bigger peg
                DEST.p.push( SRC.p.top() );
                SRC.p.pop();
            }else{
                cout << "Error: moving peg " << SRC.p.top() <<" on top of smaller peg " << DEST.p.top() << endl;
            }
        }
        // case 2: destination tower is empty - second tower move
        else{
            DEST.p.push( SRC.p.top() );
            SRC.p.pop();
        }
    }

    void start(){
        moveTower(*A, *B, *C, height);

        // print tower B
        cout << "Tower B: ";
        int size = (B->p).size();
        int i = 0;
        while(i < size){
            cout << (B->p).top() << " ";
            B->p.pop();
            i++;
        }
        cout<<endl;
    }
};



int main(){
    cout << "Provide tower height: ";
    int height;
    cin >> height;
    tower *t = new tower(height);
    t->start();

    delete(t);
    return 0;
}

