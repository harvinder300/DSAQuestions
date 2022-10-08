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

void insertAtPosition(Node *&tail, Node *&head, int position, int d)
{

    // insert at Start
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // inserting at Last Position
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    // creating a node for d
    Node *nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;

    temp->next = nodeToInsert;
}
Node *FindMid(Node *head)
{
    Node *slow = head;
    Node *fast = slow->next;

    while (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node *MergerList(Node *head1, Node *head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    Node *ans = new Node(0);
    Node *temp = ans;
    while (head1 != NULL and head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            temp->next = head1;
            temp = head1;
            head1 = head1->next;
        }
        else
        {
            temp->next = head2;
            temp = head2;
            head2 = head2->next;
        }
    }

    while (head1 != NULL)
    {
        temp->next = head1;
        temp = head1;
        head1 = head1->next;
    }
    while (head2 != NULL)
    {
        temp->next = head2;
        temp = head2;
        head2 = head2->next;
    }
   
    return ans->next;
}
Node *MergeSort(Node *&head)
{
    if (head == NULL or head->next == NULL)
        return head;
    Node *mid = FindMid(head);
    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    left = MergeSort(left);
    right = MergeSort(right);

    Node *result = MergerList(left, right);
    return  result;
}
int main()
{

    // created a new node
    Node *node1 = new Node(5);

    // head pointed to node1
    Node *head = node1;
    Node *tail = node1;
    insertAtTail(tail, 4);
    insertAtTail(tail, 3);
    insertAtTail(tail, 2);
    insertAtTail(tail, 1);
    cout << "Before Sorting :- " << endl;
    print(head);
    cout << "After Sorting :- " << endl;
    head=MergeSort(head);
    print(head);

    return 0;
}
/*

bool isCircularList(Node *head)
{
    // empty list
    if (head == NULL)
    {
        return true;
    }

    Node *temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }

    if (temp == head)
    {
        return true;
    }

    return false;
}

bool detectLoop(Node *head)
{

    if (head == NULL)
        return false;

    map<Node *, bool> visited;

    Node *temp = head;

    while (temp != NULL)
    {

        // cycle is present
        if (visited[temp] == true)
        {
            cout << "Present on element " << temp->data << endl;
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

Node *floydDetectLoop(Node *head)
{

    if (head == NULL)
        return NULL;

    Node *slow = head;
    Node *fast = head;

    while (slow != NULL && fast != NULL)
    {

        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }

        slow = slow->next;

        if (slow == fast)
        {
            cout << "present at " << slow->data << endl;
            return slow;
        }
    }

    return NULL;
}

Node *getStartingNode(Node *head)
{

    if (head == NULL)
        return NULL;

    Node *intersection = floydDetectLoop(head);
    Node *slow = head;

    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

void removeLoop(Node *head)
{

    if (head == NULL)
        return;

    Node *startOfLoop = getStartingNode(head);
    Node *temp = startOfLoop;

    while (temp->next != startOfLoop)
    {
        temp = temp->next;
    }

    temp->next = NULL;
}

*/