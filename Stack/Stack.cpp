//LIFO --- Last in fast out
#include<iostream>
using namespace std;

#define n 100

class Stack{
    int* arr;
    int top;

    public:
    Stack(){
        arr = new int[n];
        top = -1;
    }

    void push(int x){
        if(top == n-1){
            cout<<"Stack Overflowed"<<endl;
            return;
        }

        top++;
        arr[top] = x;

    }

    void pop(){
        if(top == -1){
            cout<<"No element to pop"<<endl;
            return;
        }
        top--;
    }

    void Top(){
        if(top == -1){
            cout<<"No element in stack"<<endl;
            return;
        }
        cout<<arr[top]<<endl;
    }

    bool empty(){
        return top == -1;
    }

};


int main(){
    Stack my;
    my.push(0);
    my.push(1);
    my.push(3);
    my.push(4);
    my.Top();    //prints 4
    my.pop(); //removes 4
    my.Top();    //prints 3
    my.pop(); //removes 3
    my.Top();    //prints 1
    my.pop(); //removes 1
    my.pop(); //removes 0
    my.pop();
    my.pop();





    return 0;
}