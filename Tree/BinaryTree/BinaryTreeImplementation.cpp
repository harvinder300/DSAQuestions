#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *BuildTree(node *root)
{

    cout << "Enter the data :" << endl;

    int data;
    cin >> data;

    root = new node(data);

    if (data == -1)
        return NULL;

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = BuildTree(root->left);

    cout << "Enter data for inserting in right of " << data << endl;
    root->right = BuildTree(root->right);

    return root;
}
void buildFromLevelOrder(node *root)
{
    queue<node *> q;
    cout << "Enter the data :- " << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        
        cout << "Enter left node for " << temp->data << endl;
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }
        
        cout << "Enter right node for " << temp->data << endl;
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            temp->left = new node(rightData);
            q.push(temp->right);
        }
    }
}
void LevelOrderTraversal(node *root) // or Breadth first search (BFS    )
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
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
void InOrderTraversal(node *root)
{
    if (root == NULL)
        return;

    InOrderTraversal(root->left);
    cout << root->data << " ";
    InOrderTraversal(root->right);
}
void PreOrderTraversal(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}
void PostOrderTraversal(node *root)
{
    if (root == NULL)
        return;
    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout << root->data << " ";
}
int main()
{
    node *root = NULL;
    root = BuildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout << "LevelOrderTraversal : -" << endl;
    LevelOrderTraversal(root);
    cout << "InOrderTraversal :- " << endl;
    InOrderTraversal(root);
    cout << endl;
    cout << "PreOrderTraversal :- " << endl;
    PreOrderTraversal(root);
    cout << endl;
    cout << "PostOrderTraversal" << endl;
    PostOrderTraversal(root);
    return 0;
}