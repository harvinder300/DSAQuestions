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
Node *Reverse(Node *&head)
{
    Node *temp = NULL;
    Node *curr = head;
    while (curr != NULL)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if (temp != NULL)
        head = temp->prev;
    return head;
}
Node *MergerList(Node *&first, Node *&second)
{
    if (!first)
        return second;
    if (!second)
        return first;
    Node *ans = new Node(-1);

    Node *temp = ans;
    while (first != NULL and second != NULL)
    {
        if (first->data < second->data)
        {
            int d = first->data;
            InsertAtTail(temp, first, d);
            first = first->next;
        }
        else
        {
            int d = second->data;
            InsertAtTail(temp, second, d);
            second = second->next;
        }
    }
    while (first != NULL)
    {
        int d = first->data;
        InsertAtTail(temp, first, d);
        first = first->next;
    }
    while (second != NULL)
    {
        int d = second->data;
        InsertAtTail(temp, second, d);
        second = second->next;
    }
    return ans->next;
}
// head 1 :-  2 5 7 12 10 6 4 1
// head 2 : - 1 4 6 10
Node *SortList(Node *&head)
{
    Node *curr = head->next;
    while (curr != NULL)
    {
        if (curr->data < curr->prev->data)
            break;
        curr = curr->next;
    }
    if (curr == NULL)
        return head;
    // Destroying the Link
    curr->prev->next = NULL;
    curr->prev = NULL;
    // Reversing the second half
    Reverse(curr);

    return MergerList(head, curr);
}
int main()
{
    Node *node1 = new Node(2);
    Node *head = node1;
    Node *tail = node1;
    InsertAtTail(tail, head, 5);
    InsertAtTail(tail, head, 7);
    InsertAtTail(tail, head, 12);
    InsertAtTail(tail, head, 10);
    InsertAtTail(tail, head, 6);
    InsertAtTail(tail, head, 4);
    InsertAtTail(tail, head, 1);
    // InsertAtPostition(tail, head, 6, 15);
    print(head);
    head = SortList(head);
    print(head);
    return 0;
}