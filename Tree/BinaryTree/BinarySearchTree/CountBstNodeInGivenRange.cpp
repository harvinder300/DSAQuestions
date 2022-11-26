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
void solve(Node *root, int l, int h, int &count)
{
    if (root == NULL)
        return;

    solve(root->left, l, h, count);
    if (root->data >= l and root->data <= h)
        count++;
    solve(root->right, l, h, count);
}
int getCount(Node *root, int l, int h)
{
    // your code goes here
    int count = 0;
    solve(root, l, h, count);
    return count;
}

// 50 20 70 10 30 90 -1
// 40 30 32 35 80 90 100 120
int main()
{
    Node *root = NULL;
    cout << "Enter the data for BST " << endl;
    TakeInputBST(root);
    cout << "Printing the BST " << endl;
    InOrderTraversal(root);
    int l, h;
    cout << "\nEnter Low and high value ";
    cin >> l >> h;
    cout << "Count = " << getCount(root, l, h);
    return 0;
}