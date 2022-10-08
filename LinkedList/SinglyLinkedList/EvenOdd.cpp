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
// 12->15->10->11->5->6->2->3->NULL
// 15->11->6->3->NULL.

Node *ReverseLinked(Node *head)
{
    Node *prev = NULL;
    while (head != NULL)
    {
        Node *nextNode = head->next;
        head->next = prev;
        prev = head;
        head->next = nextNode;
    }
    return prev;
}

Node *Segregate(Node *head)
{
    Node *temp = head;

    vector<int> even;
    vector<int> odd;
    while (temp != NULL)
    {
        if (temp->data % 2 == 0)
            even.push_back(temp->data);
        else
            odd.push_back(temp->data);
        temp=temp->next;
    }
    Node *ansList = new Node(-1);
    Node *curr=ansList;
    Node *ansHead = ansList;
    
    for (auto i : even)
        insertAtTail(ansHead,i);
    
    for (auto i : odd)
       insertAtTail(ansHead,i);
    return curr->next;
}
/*
Input: 17->15->8->12->10->5->4->1->7->6->NULL
Output: 8->12->10->4->6->17->15->5->1->7->NULL
*/
int main()
{

    // created a new node
    Node *node1 = new Node(1);
    // Node *node2 = new Node(3);

    // head pointed to node1
    Node *head = node1;
    Node *tail = node1;
    // print(head);
    // head pointer to node2
    //insertAtHead(head, 17);
    insertAtTail(tail, 3);
    insertAtTail(tail, 5);
    /*insertAtTail(tail, 10);
    insertAtTail(tail, 5);
    insertAtTail(tail, 4);
    insertAtTail(tail, 1);
    insertAtTail(tail, 7);
    insertAtTail(tail, 6);*/
    print(head);
    head = Segregate(head);
    print(head);
    return 0;
}