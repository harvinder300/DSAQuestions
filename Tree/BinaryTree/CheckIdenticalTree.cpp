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

void InOrderTraversal(node *root, int &count)
{
    if (root == NULL)
        return;

    InOrderTraversal(root->left, count);
    if (root->left == NULL and root->right == NULL)
        count++;
    InOrderTraversal(root->right, count);
}

bool CheckIdentical(node *root1, node *root2)
{
    if (root1 == NULL and root2 == NULL)
        return true;
    if (root1 == NULL and root2 != NULL)
        return false;
    if (root1 != NULL and root2 == NULL)
        return false;
    bool left = CheckIdentical(root1->left, root2->left);
    bool right = CheckIdentical(root1->right, root2->right);
    bool currVal = root1->data == root2->data;

    if (left and right and currVal)
        return true;
    return false;
}

int main()
{
    node *root1 = NULL;
    node *root2 = NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout << "Build Tree 1 :- " << endl;
    root1 = BuildTree(root1);
    cout << "Build Tree 2 :- " << endl;
    root2 = BuildTree(root2);
    cout << CheckIdentical(root1, root2);
    return 0;
}