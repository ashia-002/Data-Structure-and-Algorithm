// Function to create a linked list and automatically detect cycle from repeated elements
// Node* createLinkedListWithCycle() {
//     Node* head = nullptr;
//     Node* tail = nullptr;
//     unordered_map<int, Node*> nodeMap; // To track nodes by value for cycle detection

//     int value;
//     cout << "Enter the values of the linked list (enter -1 to stop): " << endl;

//     while (true) {
//         cin >> value;
        
//         if (value == -1) break; // End input with -1
        
//         // Check if the value already exists in the list (cycle detected)
//         if (nodeMap.find(value) != nodeMap.end()) {
//             tail->next = nodeMap[value]; // Create the cycle by pointing to the repeated node
//             break;
//         }
        
//         // Create a new node
//         Node* newNode = new Node(value);
        
//         // If it's the first node, initialize head
//         if (head == nullptr) {
//             head = newNode;
//         } else {
//             tail->next = newNode; // Link the previous node to the new one
//         }

//         tail = newNode; // Update the tail
//         nodeMap[value] = newNode; // Store the node in the map
//     }

//     return head;
// }


//Hare and Tortoise Algorithm

#include<iostream>
#include <unordered_map>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

Node* createLinkedListWithCycle() {
 
    Node* head = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    Node* node7 = new Node(7);
    Node* node8 = new Node(8);
    Node* node9 = new Node(9);

    // Linking nodesi
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;
    node8->next = node9;
    node9->next = node7; // Creating the cycle back to node 7

    return head;
}


bool detectCycle(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return true;
        }
    }
    return false;
}

int main(){
    Node* head = createLinkedListWithCycle();

    if(detectCycle(head)){
        cout<<"A cycle has been detected"<<endl;
    }else{
        cout<<"No cycle"<<endl;
    }

    cout<<"\n\n\n\n";




    return 0;
}