#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *InsertIntoBST(Node *root, int d)
{
    // base case
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }
    if (d > root->data) // Right part
        root->right = InsertIntoBST(root->right, d);
    else // left Part
        root->left = InsertIntoBST(root->left, d);
    return root;
}
void TakeInputBST(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = InsertIntoBST(root, data);
        cin >> data;
    }
}
void LevelOrderTraversal(Node *root) // or Breadth first search (BFS    )
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        { // Previous level was completed
            cout << endl;
            if (!q.empty()) // queue still has some child nodes
                q.push(NULL);
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}
void convertIntoSortedDLL(Node *&root, Node *&head)
{
    if (root == NULL)
        return;

    convertIntoSortedDLL(root->right, head);
    root->right = head;
    if (head != NULL)
        head->left = root;
    head = root;
    convertIntoSortedDLL(root->left, head);
}
Node *mergeLinkedList(Node *&head1, Node *&head2)
{
    Node *head = NULL;
    Node *tail = NULL;

    while (head1 != NULL and head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            if (head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            if (head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }
    while (head1 != NULL)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
    while (head2 != NULL)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    return head;
}
int countNodes(Node *&head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->right;
    }
    return cnt;
}
Node *sortedLLToBST(Node *&head, int n)
{
    if (n <= 0 or head == NULL)
        return NULL;

    Node *left = sortedLLToBST(head, n / 2);
    Node *root = head;
    root->left = left;
    head = head->right;
    root->right = sortedLLToBST(head, n - (n / 2 - 1));
    return root;
}
// 50 20 70 10 30 90 -1
Node *MergeTwoBst(Node *root1, Node *root2)
{
    Node *head1 = NULL;
    convertIntoSortedDLL(root1, head1);
    head1->left = NULL;

    Node *head2 = NULL;
    convertIntoSortedDLL(root2, head2);
    head2->left = NULL;

    Node *head = mergeLinkedList(head1, head2);

    return sortedLLToBST(head, countNodes(head));
}
int main()
{
    Node *root1 = NULL;
    Node *root2 = NULL;
    cout << "Enter the data for BST 1" << endl;
    TakeInputBST(root1);
    cout << "\nEnter the data for BST 2" << endl;
    TakeInputBST(root2);
    Node *head = MergeTwoBst(root1, root2);
    /*Node *head1 = NULL;
    convertIntoSortedDLL(root1, head1);
    head1->left = NULL;

    Node *head2 = NULL;
    convertIntoSortedDLL(root2, head2);
    head2->left = NULL;

    Node *head = mergeLinkedList(head1, head2);

    head = sortedLLToBST(head, countNodes(head));*/
    cout << "Printing Merged BSTs " << endl;
    LevelOrderTraversal(head);
    return 0;
}
