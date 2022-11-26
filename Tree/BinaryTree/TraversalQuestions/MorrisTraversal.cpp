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
node *FindPre(node *root, node *current)
{
    while (root->right != NULL and root->right != current)
        root = root->right;

    return root;
}
void MorrisTraversal_InOrder(node *root)
{
    node *current = root;
    node *pre;
    if (root == NULL)
        return;
    while (current != NULL)
    {
        if (current->left == NULL)
        {
            cout << current->data << " ";
            current = current->right;
        }
        else
        {
            pre = current->left;
            pre = FindPre(pre, current);

            if (pre->right == NULL)
            {
                pre->right = current;
                current = current->left;
            }
            else
            {
                pre->right = NULL;
                cout << current->data << " ";
                current = current->right;
            }
        }
    }
}
void MorrisTraversal_PreOrder(node *root)
{
    node *current = root;
    node *pre;
    if (root == NULL)
        return;
    while (current != NULL)
    {
        if (current->left == NULL)
        {
            cout << current->data << " ";
            current = current->right;
        }
        else
        {
            pre = current->left;
            pre = FindPre(pre, current);

            if (pre->right == current)
            {
                pre->right = NULL;
                current = current->right;
            }
            else
            {
                cout << current->data << " ";
                pre->right = current;
                current = current->left;
            }
        }
    }
}
void MorrisTraversal_PostOrder(node *root)
{
    node *current = root;
    node *pre;
    if (root == NULL)
        return;
    while (current != NULL)
    {
        if (current->left == NULL)
        {
            cout << current->data << " ";
            current = current->right;
        }
        else
        {
            pre = current->left;
            pre = FindPre(pre, current);

            if (pre->right == current)
            {
                pre->right = NULL;
                current = current->right;
            }
            else
            {
                cout << current->data << " ";
                pre->right = current;
                current = current->left;
            }
        }
    }
}

int main()
{
    node *root = NULL;
    root = BuildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout << "Morris Traversal InOrder :-" << endl;
    MorrisTraversal_InOrder(root);
    cout << endl;
    cout << "Morris Traversal PreOrder :-" << endl;
    MorrisTraversal_PreOrder(root);
    cout << endl;
    cout << "Morris Traversal PostOrder :-" << endl;
    MorrisTraversal_PostOrder(root);

    return 0;
}