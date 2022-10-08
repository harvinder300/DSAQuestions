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
/*
Input:  11->15->20->5->10
Output: 11->20->5->15->10
*/
Node *RearrangeList(Node *head)
{
    bool flag = true;
    Node *curr = head;
     //If flag is true, then next node should be greater in
    // the desired output.
    while (curr->next != NULL)
    {
        if (flag)
        {
            if (curr->data > curr->next->data)
                swap(curr->data, curr->next->data);
        }
        else
        {
            if (curr->data < curr->next->data)
                swap(curr->data, curr->next->data);
        }
        curr = curr->next;
        flag = !flag;
    }
    return head;
}
int main()
{

    // created a new node
    Node *node1 = new Node(2);
    // Node *node2 = new Node(3);

    // head pointed to node1
    Node *head = node1;
    Node *tail = node1;
    // print(head);
    // head pointer to node2
    insertAtHead(head, 1);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    // insertAtTail(tail, 5);
    print(head);
    head = RearrangeList(head);
    print(head);

    return 0;
}