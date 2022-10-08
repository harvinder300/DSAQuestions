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

Node *SortList(Node *head)
{
    int count1 = 0;
    int count0 = 0;
    int count2 = 0;
    Node *temp = head;
    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == 0)
            count0++;
        if (curr->data == 1)
            count1++;
        if (curr->data == 2)
            count2++;

        curr = curr->next;
    }

    while (count0--)
    {
        temp->data = 0;
        temp = temp->next;
    }
    while (count1--)
    {
        temp->data = 1;
        temp = temp->next;
    }
    while (count2--)
    {
        temp->data = 2;
        temp = temp->next;
    }
    return head;
}
int main()
{

    Node *node1 = new Node(2);

    // head pointed to node1
    Node *head = node1;
    Node *tail = node1;

    insertAtHead(head, 0);
    insertAtTail(tail, 0);
    insertAtTail(tail, 2);
    insertAtTail(tail, 2);
    insertAtTail(tail, 1);
    insertAtTail(tail, 1);
    SortList(head);
    print(head);
    return 0;
}