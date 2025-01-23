#include<iostream>
using namespace std;

/*Linked List 
--> A Linear data structure that stores a list of values.
-->Multiple blocks of mamory from different place gets linked together.
--> Size can be modified.
-->Non-contiguous memory.
-->Insertion and deletation at any point is easier.
*/
class node{ //A class representing a Node.
    public:
    int data;
    node* link;//Creating a pointer to node. here next is pointing to other node. 

    node(int val){//constructor
        data=val;
        link=NULL;
    }
};

//We are making a element, inserting the data and adding it in the head, making it the new head.
/*1.We are creating a new node
  2.inserting the data in the new node
  3.new node's link is pointing to the previous head.
  4.making the new node the head. */
void insertAtHead(node* &head, int val){//head is containing the address of node.
    node* n = new node(val);
    n->link=head; //n of link is pointing to the head. Because the head is storing the address of the first node.
    head=n; //Now we are giving n to head(Address).now the n will be new head.
}


void insertAtTail(node* &head, int val){//We are adding element before NULL.
    node* n = new node(val); //This is The new node that we want to insert.And will contain the value val

    if(head==NULL){ //when there is no other element or head is NULL we give the value of n to the head.
        head=n;
        return;
    }

    node* temp=head; //Initializing from head. Making a new node named temp. which is storing the address of head.
    while(temp->link != NULL){ //Triversing through the list Like when the temp's address is not NULL.
        temp = temp->link;  //temp will hold the next temp's address.
    }
    temp->link=n;
}
void deletion(node* &head, int val){//n is the value we are going to delete.
    node* temp = head;
    while(temp->link->data != val){//here is iterating upto n-1 value.
        temp=temp->link;
    }
    
    node* todelete=temp->link;
    temp->link=temp->link->link;
    //n-1 link will change to n+1
    delete todelete;
}


void display(node* head){
    node* temp=head; //Initializing from head and triversing through the list
    while(temp!= NULL){
        cout<<temp->data<<"->";//WE are printing the data from temp.
        temp=temp->link;//here we are going to the next temp/node.
    }
    cout<<"NULL"<<endl;
}

bool search(node* head, int key){ //Searching through the list to find the element named key.
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp=temp->link;
    }
    return false;
}


int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    display(head);
    insertAtHead(head,4);
    display(head);
    // cout<<search(head,5)<<endl;// here this will show False as 0
    // cout<<search(head,3)<<endl;//here this will show True as 1.

    deletion(head, 3);
    display(head);
    return 0;
}

