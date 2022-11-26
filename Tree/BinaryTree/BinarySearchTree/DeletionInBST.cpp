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
int MinVal(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
        temp = temp->left;

    return temp->data;
}
int MaxVal(Node *root)
{
    Node *temp = root;
    while (temp->right != NULL)
        temp = temp->right;

    return temp->data;
}

Node *DeletionBST(Node *root, int val)
{
    if (root == NULL)
        return root;
    if (root->data == val)
    {
        // 0 child
        if (root->left == NULL and root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // 1 child , left vaala
        if (root->left != NULL and root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // 1 child , right vaala
        if (root->left == NULL and root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // 2 child
        if (root->left != NULL and root->right != NULL)
        {
            int mini = MinVal(root->right);
            root->data = mini;
            root->right = DeletionBST(root->right, mini);
            return root;
        }
    }
    else if (root->data > val)
    {
        root->left = DeletionBST(root->left, val);
        return root;
    }
    else
    {
        root->right = DeletionBST(root->right, val);
        return root;
    }
    return root;
}
//[5,3,6,2,4,-1,7]

void InOrderTraversal(Node *root)
{
    if (root == NULL)
        return;

    InOrderTraversal(root->left);
    cout << root->data << " ";
    InOrderTraversal(root->right);
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
    cout << "Enter the data you want to delete in BST " << endl;
    cin >> data;
    root = DeletionBST(root, data);
    cout << endl;
    cout << "After Deletion of " << data << " :- " << endl;
    LevelOrderTraversal(root); 
    cout << endl;
    cout << "InOrder :- " << endl;
    InOrderTraversal(root);

    return 0;
}