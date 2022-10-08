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

void deleteNode(int position, Node *&head)
{

    // deleting first or start node
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        // memory free start ndoe
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

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
Node *Floyd_detectLoop(Node *&head)
{
    if (head == NULL)
        return NULL;
    Node *slow = head;
    Node *fast = head;

    while (slow != NULL and fast != NULL)
    {

        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;

        slow = slow->next;
        if (slow == fast) 
            return slow;
    }
    return NULL;
}
Node *gettingStartNode(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *interSectionPoint = Floyd_detectLoop(head); // Where slow meets fast pointer in floyd detection algo
    if (interSectionPoint == NULL)
        return NULL;
    Node *slow = head;
    while (slow != interSectionPoint)
    {
        slow = slow->next;
        interSectionPoint = interSectionPoint->next;
    }
    return slow;
}
Node *RemoveLoop(Node *&head)
{

    if (head == NULL)
        return;

    Node *startOfLoop = gettingStartNode(head);
    if (startOfLoop == NULL)
        return;
    Node *temp = startOfLoop;

    while (temp->next != startOfLoop)
        temp = temp->next;
    temp->next = NULL;
   
    return head;
}
int main()
{

    // created a new node
    Node *node1 = new Node(1);

    // head pointed to node1
    Node *head = node1;
    Node *tail = node1;

    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);
    tail->next = head->next;
    if (Floyd_detectLoop(head) != NULL)
        cout << "Loop is Detected" << endl;
    else
        cout << "Loop is not present" << endl;

    Node *loopStart = gettingStartNode(head);
    cout << "Start At :- " << loopStart->data << endl;

    cout << "Loop is Removed" << endl;
    RemoveLoop(head);
    Floyd_detectLoop(head);
    if (Floyd_detectLoop(head) != NULL)
        cout << "Loop is Detected" << endl;
    else
        cout << "Loop is not present" << endl;

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