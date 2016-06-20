#include <stdlib.h> /* srand, rand */
#include <cmath>    /* abs()       */
#include <typeinfo>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "../common/mylist.h"

using namespace std;

/* Forward declaration */
struct myStack{

    // fields
    List *L;

    // constructor
    myStack(){
        L = new List();
    }

    myStack(vector<int>& v){
        L = new List();
        for (auto it=v.begin(); it != v.end(); it++){
            addFront(L, *it);
        }
    }

    // destructor
    ~myStack(){
        removeList(L);
        delete L;
    }

    /* myStack methods */     

    // push
    void push(int x){
        addFront(L, x);
    }

    // top
    int top(){
        return L->head->data;
    }

    // pop
    void pop(){
        popFront(L);
    }

    // empty
    bool isEmpty(){
        return (L->head == NULL) ? true : false;
    }
    
    // max
    int max(){
        myStack *t = new myStack();
        
        int m =0;
        while (!this->isEmpty()){
            if (this->top() > m){
                m = this->top();
            }
            t->push( this->top() );
            this->pop();
        }

        while(!t->isEmpty()){
            this->push( t->top() );
            t->pop();
        }

        delete t;
        return m;
    }
    

    // print
    void print(){
        Node *temp = L->head;
        cout << "myStack: ";
        while (temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};



int main(){
    vector<int> v = {4,6,1,2,3,9,7,5,3,4,0};

    // build stack
    myStack *s = new myStack(v);
    s->print();

    // max
    cout << "max: " << s->max() << endl;

    // top
    cout << "top: " << s->top() << endl;
    
    // pop
    s->pop();
    cout << "popped. top: " << s->top() << endl;
    
    // empty
    while (!(*s).isEmpty()){
        (*s).pop();
    }
    cout << "popped all." << endl;
    (*s).print();

    delete s;

    // why this way of calling doesn't require memory clean up - i.e. delete s2?
    myStack s2(v);  // automatic storage; allocated on the stack not heap; google initialize struct on stack/heap
    s2.print();
    return 0;
}
