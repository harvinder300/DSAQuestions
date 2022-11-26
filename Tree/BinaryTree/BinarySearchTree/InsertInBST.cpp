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
Node *insertIntoBST(Node *root, int val)
{
    if (root == NULL)
        return NULL;
    Node *temp = root;
    while (temp != NULL)
    {
        if (temp->data < val)
        {
            if (temp->right)
                temp = temp->right;
            else
            {
                temp->right = new Node(val);
                break;
            }
        }
        else if (temp->data >= val)
        {
            if (temp->left)
                temp = temp->left;
            else
            {
                temp->left = new Node(val);
                break;
            }
        }
    }
    return root;
}
int main()
{
    Node *root = NULL;
    cout << "Enter the data for BST " << endl;
    TakeInputBST(root);
    cout << "Printing the BST " << endl;
    LevelOrderTraversal(root);
    cout << endl;
    int data;
    cout << "Enter the data you want to Insert in BST " << endl;
    cin >> data;
    root = insertIntoBST(root, data);
    cout << "Printing the BST after Insertion " << endl;
    LevelOrderTraversal(root);

    return 0;
}