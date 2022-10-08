#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};

void insertAtHead(Node *&head, int d)
{

    // new node create
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int d)
{
    // new node create
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void print(Node *&head)
{

    if (head == NULL)
    {
        cout << "List is empty " << endl;
        return;
    }
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    
    Node* a=head1;
    Node* b=head2;
    
    while(a!=b)
    {
        if(a==NULL)
          a=head2;
         else
         a=a->next;
         
        if(b==NULL)
         b=head1;
        else
         b=b->next;
    }
    int data=a->data;
    return data;
}
int main()
{

    // created a new node
    Node *node1 = new Node(2);
    Node *node2 = new Node(3);

    // head pointed to node1
    Node *head = node1;
    Node *tail = node1;
    // print(head);
    // head pointer to node2
    Node *head2 = node2;
    Node *tail2 = node2;
    insertAtHead(head, 1);
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 6);
    // Inserting in second list

    insertAtHead(head, 4);
    insertAtTail(head, 7);
    insertAtTail(tail, 8);
    insertAtTail(tail, 9);
    cout << intersectPoint(head, head2);
    return 0;
}