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
        cout << "memory is free for node with data " << value << endl;
    }
};

Node *Insertion(Node *&tail, int element, int d)
{ // Empty List
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    { // Non-Empty List

        Node *curr = tail;
        while (curr->data != element)
            curr = curr->next;
        // Element Found now inserting after the element
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
    return tail;
}
void Deletion(Node *&tail, int value)
{
    if (tail == NULL)
    {
        cout << "List is Empty" << endl;
    }
    else
    {
        Node *prev = tail;
        Node *curr = prev->next;
        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        // cout<<tail->data<<" "<<curr->data<<prev->data<<endl;
        // If 1 node is present in linkedlist
        if (curr = prev)
            tail = NULL;
        // Greater than 2 node present in linked lsit
        if (tail == curr)
            tail = prev;
        // cout<<tail->data<<endl;
        curr->next = NULL;
        delete curr;
    }
}
void print(Node *&tail)
{
    if (tail == NULL)
    {
        cout << "Empty List" << endl;
        return;
    }
    Node *temp = tail;
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}

int main()
{
    // Node *node1 = new Node(1);
    Node *tail = NULL;

    Insertion(tail, 5, 3);
    Insertion(tail, 3, 5);
    print(tail);
    /* print(tail);

     print(tail);
     Insertion(tail, 5, 7);
     print(tail);
     Insertion(tail, 3, 4);
     print(tail);
     */
    Deletion(tail,3);
    print(tail);

    return 0;
};
