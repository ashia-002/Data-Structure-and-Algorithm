#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *link;
    Node *prev;

    Node(int val)
    {
        data = val;
        link = NULL;
        prev = NULL;
    }
};

Node *InsertingAtTail(Node *&head, int value)
{
    Node *n = new Node(value);
    if (head == NULL)
    {
        head = n;
        return head;
    }

    Node *temp = head;
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = n;
    n->prev = temp; // Keepin ttrack of the previous node of the last node
    return head;
}

void Display(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->link;
    }
    cout<<endl;
}

//Here using previous pointer to 
void TraverseFromLastNode(Node *&head, int LastPositionFromTail)
{
    Node *LastNode = head;
    while (LastNode->link != NULL)
    {
        LastNode = LastNode->link; // Finding the last node from tail
    }

    // Traverse from the last node to the given position from the tail
    Node *current = LastNode;
    for (int i = 0; i < LastPositionFromTail && current != NULL; i++)
    {
        current = current->prev; // Using previous pointer to traverse backwards (assuming doubly linked list)
    }

    if (current != NULL)
    {
        cout << current->data; // Output the data if the node exists
    }
    else
    {
        cout << "Position out of range."; // Handle case when given position is out of range
    }
}

//By changing the direction of the link
int getValue(Node *head, int LastPositionFromTail)
{
    Node *temp = head;
    Node *pre = NULL; //to reverse the link
    while (temp != NULL)
    {   
        //In here we are changing the derection of the link
        Node *front = temp->link;
        temp->link = pre;
        pre = temp;
        temp = front;
    }
    for (int i = 0; i < LastPositionFromTail && pre != NULL; i++)
    {
        pre = pre->link;
    }

    return pre->data;
}

int main()
{
    Node *Head = NULL;
    int num;
    Node *n = NULL;
    for (int i = 0; i < 3; i++)
    {
        cin >> num;
        n = InsertingAtTail(Head, num);
    }
    Display(n);
    int value;
    cin >> value;
    cout << "After traversing from last node the value at position " << value <<" is :";
    TraverseFromLastNode(Head, value);
    cout<<endl;

    cout << "After traversing from last node the value at position " << value <<" is :";
    int result = getValue(Head, value);
    cout << result << endl;

    return 0;
}

// int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
//     SinglyLinkedListNode* temp= llist;
//     SinglyLinkedListNode* pre = NULL;
//     while(temp != NULL){
//         SinglyLinkedListNode* front = temp->next;
//         temp->next = pre;
//         pre = temp;
//         temp = front;
//     }
    
//     for(int i = 0; i<positionFromTail && pre != NULL; i++){
//         pre = pre->next;
//     }
    
//     return pre->data;
// }