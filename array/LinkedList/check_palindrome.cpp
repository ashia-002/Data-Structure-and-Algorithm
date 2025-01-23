//using linked list
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* link;

    node(int val){
        data = val;
        link = NULL;
    }
};

//Inserting values
void InsertAtTail(node* &head, int value){
    node* n = new node(value);

    if(head == NULL){
        head = n;
        return;
    }
    node* temp = head;
    while(temp->link != NULL){
        temp = temp->link;
    }

    temp->link = n;

}

//Printing the linked list
void Display(node* &head){
    node* temp = head;

    while(temp != NULL){
        cout<< temp->data << " ";
        temp = temp->link;
    }
}

//Checking if the list is palindrome or not
//Can be done using stack
bool Is_Palindrome(node* &head){
    node* temp = head;
    stack<int> st;

    while(temp != NULL){
        st.push(temp->data);
        temp = temp->link;
    }

    temp = head;
    while(temp != NULL){
        if(temp->data != st.top()){
            return false;
        } 

        temp = temp->link;
        st.pop();
    }

    return true;
}


int main(){
    node* Head=NULL;
    int n;
    for(int i = 0; i<6; i++){
        cin>> n;
        InsertAtTail(Head, n);
    }

    cout<<"The Inserted list is: ";
    Display(Head);

    bool ans = Is_Palindrome(Head);
    if(!ans){
        cout<<"\nThe list is not a Palindrome"<<endl;
    }else{
        cout<<"\nThe list is a Palindrome"<<endl;
    }


    return 0;
}