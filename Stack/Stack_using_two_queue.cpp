#include<bits/stdc++.h>
using namespace std;

class Stack{
    queue<int> q1, q2;

    public:
    void push(int x){
        q2.push(x);

        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void pop(){
        if(q1.empty()){
            return;
        }

        q1.pop();
    }
    int Top(){
        if(q1.empty())
            return -1;

        return q1.front();
    }

    int size(){
        return q1.size();
    }

};

int main(){
    Stack S1;
    S1.push(1);
    S1.push(2);
    S1.push(3);
    S1.push(4);
    cout<<"The size is: ";
    cout<< S1.size() <<endl;
    S1.pop();
    cout<< S1.Top() <<endl;
    S1.pop();
    cout<< S1.Top() <<endl;



    return 0;
}