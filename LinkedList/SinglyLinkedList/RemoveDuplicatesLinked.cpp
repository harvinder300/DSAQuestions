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
        //cout << " memory is free for node with data " << value << endl;
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
Node *RemoveDuplicates(Node *head)
{
    unordered_set<int> s;

    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL)
    {
        if (s.find(curr->data) != s.end())
        {
            prev->next = curr->next;
            delete (curr);
        }
        else
        {
            s.insert(curr->data);
            prev = curr;
        }
        curr = curr->next;
    }
    return head;
}
int main()
{

    // created a new node
    Node *node1 = new Node(2);

    // head pointed to node1
    Node *head = node1;
    Node *tail = node1;

    insertAtHead(head, 1);
    insertAtTail(tail, 2);
    insertAtTail(tail, 2);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);
    insertAtTail(tail, 5);
    RemoveDuplicates(head);
    print(head);
    return 0;
}