//SAME CODE IN A DIFFERENT WAY
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    // Function to insert a new node at the end of the linked list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            // If the list is empty, make the new node the head
            head = newNode;
        } else {
            // Traverse to the last node and insert the new node
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

     // Function to insert a new node at the head of the linked list
    void insertAtHead(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            // If the list is empty, make the new node the head
            head = newNode;
        } else {
            // Set the next of the new node to the current head
            newNode->next = head;
            // Update the head to the new node
            head = newNode;
        }
    }

    // Function to delete a node from the linked list
    void deleteNode(int value) {
        // Check if the list is empty
        if (head == nullptr) {
            return;
        }

        // Check if the head node is the one to be deleted
        if (head->data == value) {
            Node* temp = head;
            head = head->next;//next node will be the new head
            delete temp;
            return;
        }

        // Traverse the list to find the node to be deleted
        Node* current = head;
        Node* prev = nullptr;
        while (current != nullptr && current->data != value) {
            prev = current;
            current = current->next;
        }

        // If the node is found, remove it from the list
        if (current != nullptr) {
            prev->next = current->next;
            delete current;
        }
    }

    // Function to search for an element in the linked list
    bool search(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return true; // Element found
            }
            current = current->next;
        }
        return false; // Element not found
    }

    //Function to reverse a linked list(itterative method)
    Node* reverse(){
        Node* previous = NULL;
        Node* current = head;
        Node* next;

        while(current != NULL){
            next = current->next;//storing the next node of current node
            current->next = previous;//Pointing current node to next node

            previous = current;//Moving previous pointer to current
            current = next;//Moving current pointer to next
        }

        head = previous;//Updating head to previous.
    }

    //Recursive method
    Node* reverse_recursive(Node* head){

        if(head == nullptr || head->next == nullptr){
            return head;
        }
        
        Node* newhead = reverse_recursive(head->next);//recirsively reverse the next of the list
        head->next->next = head;
        head->next = nullptr;//set the next of head pointer to null, making it the last element

        head = newhead;
    }


    // Function to display the linked list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList myList;
    myList.insertAtEnd(1);
    myList.insertAtEnd(2);
    myList.insertAtEnd(3);
    myList.insertAtEnd(0);
    myList.insertAtHead(4);
    //myList.reverse();
    myList.reverse_recursive();
    myList.display();
    bool found = myList.search(2);
    cout << "Element found: " << std::boolalpha << found << endl; // Output: Element found: true

    found = myList.search(4);
    std::cout << "Element found: " << std::boolalpha << found << endl; // Output: Element found: false


    return 0;
}
