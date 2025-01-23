#include<bits/stdc++.h>
using namespace std;

class Queue{
    public:

    stack<int> s1, s2;

    void enQueue(int x){

        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    int deQueue( ){
        if(s1.empty()){
            return -1;
        }

        int x = s1.top();
        s1.pop();
        return x;

    }

};

int main(){

    Queue q1;
    q1.enQueue(1);
    q1.enQueue(2);
    q1.enQueue(3);
    //here the queue or s1 will st0re the elements ae - 1 2 3
    //so the first element to be printed is the first one inserted

    cout<<q1.deQueue()<<endl; //output: 1
    cout<<q1.deQueue()<<endl; //output: 2
    cout<<q1.deQueue()<<endl; //output: 3


    return 0;
}
/*
   This C++ code implements a queue using two stacks (s1 and s2).
   The enQueue operation is implemented by transferring all elements from s1 to s2,
   pushing the new element onto s1, and then transferring elements back from s2 to s1.

   The deQueue operation simply involves popping the top element from s1,
   effectively mimicking the behavior of a queue.

   The main function demonstrates the usage of this queue by enQueueing elements 1, 2, and 3,
   and then deQueueing them one by one. The order of elements printed is as follows:
   1. enQueue(1): 1
   2. enQueue(2): 2
   3. enQueue(3): 3

   The deQueue operation retrieves and prints elements in the same order they were enQueued:
   4. deQueue(): 1
   5. deQueue(): 2
   6. deQueue(): 3
*/
