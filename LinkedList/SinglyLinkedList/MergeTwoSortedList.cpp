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
// 1 2 3 4 6
// 4 7 8 9
Node *MergerList(Node *Head1, Node *Head2)
{
    Node *NewList = new Node(-1), *NewHead = NewList;
    Node *p1 = Head1, *p2 = Head2;

    while (p1 != NULL and p2 != NULL)
    {
        if (p1->data > p2->data)
        {
            NewHead->next = p2;
            p2 = p2->next;
        }
        else
        {
            NewHead->next = p1;
            p1 = p1->next;
        }
        NewHead = NewHead->next;
    }
    if (p1 != NULL)
    {
        NewHead->next = p1;
    }
    if (p2 != NULL)
    {
        NewHead->next = p2;
    }
    return NewList->next;
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

    Node *neW = MergerList(node1, node2);
    Node *head3=neW;
    print(head3);
    return 0;
}