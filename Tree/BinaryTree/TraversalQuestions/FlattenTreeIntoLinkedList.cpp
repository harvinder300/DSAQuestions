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
void FlattenTree(node *root)
{
    node *current = root;
    while (current != NULL)
    {
        if (current->left)
        {
            node *pre = current->left;
            while (pre->right)
                pre = pre->right;

            pre->right = current->right;
            current->right = current->left;
            current->left = NULL;
        }
        current = current->right;
    }
}
int main()
{
    node *root = NULL;
    root = BuildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout << "Flatten the Tree Into LinkedList :- " << endl;
    FlattenTree(root);
    return 0;
}