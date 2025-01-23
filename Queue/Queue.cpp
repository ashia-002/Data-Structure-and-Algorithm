//Array implementation of Queue
//FIFO -- First in first out

#include<iostream>
using namespace std;

#define n 20 

class queue{
    int *arr;
    int front;
    int back;

    public:
    queue(){
        arr = new int[n];
        front = -1;
        back = -1;
    }

    void push(int x){ // enqueue(x)
        if(back == n-1){
            cout<<"Queue overflow"<<endl;
            return;
        }
        back++;

        arr[back] = x;

        if(front == -1){
            front++;
        }
    }

    void pop(){ // dequeue()
        if(front == -1 || front > back){
            cout<<"No element in Queue"<<endl;
            return;
        }

        front++;
    }

    int peek(){ //This function will print the front element of the queue or the next element to be deleted

        if(front == -1 || front > back){
            cout<<"No element in Queue"<<endl;
            return -1;
        }

        return arr[front];
    }

    bool empty(){ //Will check if the queue is empty or not
        if(front == -1 || front > back){
            return true;
        }
        return false;
    }

    void display() { //Will display the whole queue
        if (front == -1 || front > back) {
            cout << "No element in Queue" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= back; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    queue q1;
    for(int i = 0; i<7; i++){ // entering 6 elements through the back
        q1.push(i);
    }

    for(int i = 0; i<3; i++){ // This will remove first three elements through the front
        q1.pop();
    }
    cout<<q1.peek()<<endl; // output: 4


    return 0;
}