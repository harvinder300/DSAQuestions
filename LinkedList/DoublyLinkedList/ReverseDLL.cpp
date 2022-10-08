#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node()
    {
        int val = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << val << endl;
    }
};

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
// INSERTING---------------------------------------
void InsertAtHead(Node *&tail, Node *&head, int d)
{ // If List is Empty
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    Node *temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}
void InsertAtTail(Node *&tail, Node *&head, int d)
{ // If List is Empty
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        tail = temp;
        head = temp;
    }
    Node *temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}
void InsertAtPostition(Node *&tail, Node *&head, int pos, int d)
{ // Start
    if (pos == 1)
    {
        InsertAtHead(tail, head, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // inserting at Last Position
    if (temp->next == NULL)
    {
        InsertAtTail(tail, head, d);
        return;
    }

    // Inserting at pos
    Node *nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}
// DELETING--------------------------------
void deleteNode(int position, Node *&head)
{

    // deleting first or start node
    if (position == 1)
    {
        Node *temp = head;

        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting any middle node or last node
        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
Node *ReverseDLL(Node *head)
{
    Node *curr = head;
    if (curr == NULL or curr->next == NULL)
        return head;
    while (curr->next != NULL)
        curr = curr->next;
    head = curr;//Head is pointing to the last node
    curr->next = curr->prev;
    curr->prev = NULL;
    curr = curr->next;
   //For middle nodes
    while (curr->prev != NULL)
    {
        Node *temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;
        curr = curr->next;
    }
    //1st Node 
    curr->prev = curr->next;
    curr->next = NULL;
    return head;
}
int main()
{
    Node *node1 = new Node(20);
    Node *head = node1;
    Node *tail = node1;
    InsertAtTail(tail, head, 30);
    InsertAtTail(tail, head, 40);
    InsertAtTail(tail, head, 50);
    InsertAtTail(tail, head, 60);
    // InsertAtPostition(tail, head, 6, 15);
    print(head);

    head = ReverseDLL(head);

    print(head);
    return 0;
}