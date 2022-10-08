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

bool CycleDetect(Node *head)
{
    if (head == NULL)
        return false;
    Node *hare = head;
    Node *turtle = head;

    while (hare != NULL and hare->next != NULL)
    {
        hare = hare->next->next;
        turtle = turtle->next;
        if (hare == turtle)
            return true;
    }
    return false;
}
int main()
{

    // created a new node
    Node *node1 = new Node(2);

    // head pointed to node1
    Node *head = node1;
    Node *tail = node1;
    // print(head);

    insertAtHead(head, 1);
    insertAtTail(tail, 2);

    // print(head);

    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);

    cout << CycleDetect(head);
    //print(head);
    return 0;
}