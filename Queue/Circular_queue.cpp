#include<bits/stdc++.h>
using namespace std;

class circular_queue{
    int *arr, size;
    int front;
    int rear;
    int count;
public:
    circular_queue(int n){
        arr = new int[n];
        size = n;
        front = 0;
        rear = 0;
        count = 0;
    }

    void push(int x){
        if(count == size) return;
        arr[rear] = x;
        rear = (rear + 1) % size;
        count++;
    } 

    void pop(){
        if(count == 0) return;
        arr[front] = -1;
        front = (front + 1) % size;
        count--;

    }

    int top(){
        if(count == 0) return -1;
        return arr[front];
    }
};

int main(){

    circular_queue q1(5);
    q1.push(0);
    q1.push(2);
    q1.push(4);
    q1.push(6);
    
    for(int i = 0; i<5; i++){
        cout<< q1.top() <<endl;
        q1.pop();
    }

    return 0;

}