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
Node *DeleteNode(Node *head)
{
    /* ReverseLinked(head);
     Node *curr = head;
     Node *maxNode = head;
     Node *temp;
     // Node *curr = head;
     while (curr != NULL and curr->next != NULL)
     {
         if (curr->data < maxNode->data)
         {
             temp = curr->next;
             curr->next = temp->next;
             free(temp);
         }
         else
         {
             curr = curr->next;
             maxNode = curr;
         }
     }
     ReverseLinked(head);
     return head;*/
    if (head == NULL || head->next == NULL)
        return head;
    Node *nextNode = DeleteNode(head->next);

    if (nextNode->data > head->data)
        return nextNode;
    head->next = nextNode;

    return head;
}
int main()
{

    // created a new node
    Node *node1 = new Node(15);
    // Node *node2 = new Node(3);

    // head pointed to node1
    Node *head = node1;
    Node *tail = node1;
    // print(head);
    // head pointer to node2
    insertAtHead(head, 12);
    insertAtTail(tail, 10);
    insertAtTail(tail, 11);
    insertAtTail(tail, 5);
    insertAtTail(tail, 6);
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    print(head);
    head = DeleteNode(head);
    print(head);
    return 0;
}