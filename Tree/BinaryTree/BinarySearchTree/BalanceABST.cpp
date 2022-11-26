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
void LevelOrderTraversal(Node *root) // or Breadth first search (BFS)
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
Node *InOrderToBST(vector<int> &InOrder, int s, int e)
{
    if (s > e)
        return NULL;

    int mid = s + (e - s) / 2;
    Node *root = new Node(InOrder[mid]);
    root->left = InOrderToBST(InOrder, s, mid - 1);
    root->right = InOrderToBST(InOrder, mid + 1, e);
    return root;
}
void InOrderTraversal(Node *root, vector<int> &InOrder)
{
    if (root == NULL)
        return;

    InOrderTraversal(root->left, InOrder);
    InOrder.push_back(root->data);
    InOrderTraversal(root->right, InOrder);
}

Node *balanceBST(Node *root)
{
    vector<int> InOrder;
    InOrderTraversal(root, InOrder);

    return InOrderToBST(InOrder, 0, InOrder.size() - 1);
}

// 50 20 70 10 30 90 -1
int main()
{
    Node *root = NULL;
    cout << "Enter the data for BST " << endl;
    TakeInputBST(root);
    cout << "Printing the BST " << endl;
    LevelOrderTraversal(root);
    cout << endl;
    return 0;
}