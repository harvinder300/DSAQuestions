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
void InOrder(Node *root, vector<int> &v)
{
    if (root == NULL)
        return;

    InOrder(root->left, v);
    v.push_back(root->data);
    InOrder(root->left, v);
}
Node *Flatten(Node *root)
{
    vector<int> inOrder;
    InOrder(root, inOrder);
    int n = inOrder.size();

    Node *NewRoot = new Node(inOrder[0]);
    Node *curr = NewRoot;

    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node(inOrder[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }
    curr->left = NULL;
    curr->right = NULL;
    return NewRoot;
}
// 50 20 70 10 30 90 -1
int main()
{
    Node *root = NULL;
    cout << "Enter the data for BST " << endl;
    TakeInputBST(root);
    cout << "Printing the BST " << endl;
    LevelOrderTraversal(root);

    return 0;
}