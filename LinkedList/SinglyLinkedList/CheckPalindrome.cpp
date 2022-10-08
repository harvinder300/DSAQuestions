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

Node *ReverseLinked(Node *&head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *nextNode = NULL;
    while (curr != NULL)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}
Node *GetMid(Node *&head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL and fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
bool isPalindrome(Node *&head)
{
   /* Node *mid = GetMid(head);
    Node *temp = mid->next;
    mid->next = ReverseLinked(temp);
    Node *head1 = head;
    Node *head2 = mid->next;

    while (head2 != NULL)
    {
        if (head1->data != head2->data)
            return false;
        head1=head1->next;
        head2=head2->next;
    }*/
    Node *curr=head;
    Node* temp=new Node(-1);
    Node* head2=temp;
    head2->next=ReverseLinked(curr);

    Node* head1=head;
    Node* head3=head2->next;
    
    while(head3!=NULL)
    {
        if(head3->data!=head1->data)
           return false;
        head1=head1->next;
        head3=head3->next;
    }
    return true;
}
int main()
{

    // created a new node
    Node *node1 = new Node(2);

    // head pointed to node1
    Node *head = node1;
    Node *tail = node1;
    // print(head);
    // insertAtHead(head, 1);
    insertAtTail(tail, 1);
    // print(head);
    insertAtTail(tail, 2);
    print(head);
    // insertAtTail(tail, 4);
    // insertAtTail(tail, 5);
    cout << isPalindrome(head);
    return 0;
}