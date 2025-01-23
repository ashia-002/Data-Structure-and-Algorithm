//iterator method 
//recursive method
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* link;

    Node(int value){
        data = value;
        link = NULL;
    }
};

void InsertValue(Node* &head, int val){ 
    Node* newNode = new Node(val);

    if(!head){
        head = newNode;
    }else{
        Node* temp = head;
        while(temp->link != NULL){
            temp = temp->link;
        }
        temp->link = newNode;
    }
    
}

void InsertAtHead(Node* &head, int val){
    Node* temp = new Node(val);
    temp->link = head;
    head = temp;

}

void InsertAtTail(Node* &head, int val){
    Node* n = new Node(val);

    if(head == NULL){
        head = n;
        return;
    }

    Node* temp = head;
    while(temp->link != NULL){
        temp = temp->link;
    }
    temp->link = n;

}

void Display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp->data << " ";
        temp = temp->link;
    }
}

//Using Stack to reverse a Linkrd List
/*This will not change the llink but will change the
data.*/
void reverseLinkedList(Node* head){ 
    Node* temp = head;
    stack<int> st;
//step 1 Putting everything into the stack
    while(temp != NULL){
        st.push(temp->data);
        temp = temp->link;
    }
    temp = head;

    while(temp != NULL){
        temp->data = st.top();
        st.pop();
        temp = temp->link;
    }

}

//Just changing the link
/*Time complexity - O(N)
Space Complexity - O(1)*/
Node* reverseLink(Node* head){
    Node* temp = head;
    Node* pre = NULL;
    while(temp != NULL){
        Node* front = temp->link;
        temp->link = pre;
        pre = temp;
        temp = front;
    }
    return pre;
}

//Reversing using recursion
/*Time complexity - O(N)
Space Complexity - O(N)Bs of recursive stack space*/
Node* reverseRecursion(Node* head){
    //Done with one node(Base case)
    if(head == NULL /*meaning there is no head*/|| head->link == NULL /*meaning only one element*/){
        return head;
    }
    Node* newHead = reverseRecursion(head->link);
    Node* front = head->link;
    front->link = head;
    head->link = NULL;

    return newHead;
}

int main(){
    
    Node* Head=NULL;
    for(int i = 1; i<11; i++){
        InsertAtTail(Head, i);
    }
    Display(Head);
    reverseLinkedList(Head);
    cout<<"\nAfter reversing the list: ";
    Display(Head);

    Node* n=NULL;
    n = reverseLink(Head);
    cout<<"\nAfter reversing the list by changing the links: ";
    Display(n);
    



    return 0;
}

