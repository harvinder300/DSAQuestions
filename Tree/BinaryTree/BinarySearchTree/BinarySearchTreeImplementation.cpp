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
void InOrderTraversal(Node *root)
{
    if (root == NULL)
        return;

    InOrderTraversal(root->left);
    cout << root->data << " ";
    InOrderTraversal(root->right);
}
void PreOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}
void PostOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout << root->data << " ";
}
int main()
{
    Node *root = NULL;
    cout << "Enter the data for BST " << endl;
    TakeInputBST(root);
    cout << "Printing the BST " << endl;
    LevelOrderTraversal(root);
    cout << "InOrder :- " << endl;
    InOrderTraversal(root);
    cout << endl;
    cout << "PreOrder :- " << endl;
    PreOrderTraversal(root);
    cout << endl;
    cout << "PostOrder" << endl;
    PostOrderTraversal(root);

    return 0;
}