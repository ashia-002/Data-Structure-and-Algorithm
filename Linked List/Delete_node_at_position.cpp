#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* link;

    Node(int val){
        data = val;
        link = NULL;
    }
};

void InsertAtTail(Node* &head, int value) {
    Node* n = new Node(value);
    if (head == NULL) {
        head = n;
        return;
    }

    Node* temp = head;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = n;
}


void Display(Node* &head){
    Node* temp = head;
    while(temp->link != NULL){
        cout<< temp->data << " ";
        temp = temp->link;
    }
    cout<<endl;
}

// deletation at any position
Node* Deletation_At_Position(Node* &head, int position){
    
    if(head == NULL){ //If there is no node;
        cout<<"There is no list to delete.";
    }

    if(position == 0){ //If the node to be deleted is the head
       Node* temp = head;
       head = head->link;
       delete temp;
       //return;
       return head; 
    }

    Node* temp = head;
    for(int i = 0; temp != nullptr && i < position-1; ++i){ //traverse upto the node to be deleted
        temp = temp->link;
    }
    Node* todelete = temp->link; // the node to be deleted
    temp->link = todelete->link; // reconnecting the link

    delete todelete; //deleting the node
    //return;
    return head; // the list after deletation

}

//Deleting any value
void DeleteValue(Node* &head, int value){ 
    Node* temp = head;

    while(temp->link->data != value){
        temp = temp->link;
    }

    Node* toDelete = temp->link;
    temp->link = toDelete->link;
}

int main(){
    Node* Head=NULL;
    //int num;
    for(int i = 1; i<6; i++){
        //cin >> num;
        InsertAtTail(Head, i);
    }

    Display(Head);

    Node* afterDelete = Deletation_At_Position(Head, 3);
    //Deletation_At_Position(Head, 3);

    Display(afterDelete);
    //Display(Head);

    return 0;
}