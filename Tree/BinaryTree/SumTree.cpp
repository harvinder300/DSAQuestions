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

pair<bool, int> Solve(node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    //Checking leaf node
    if (root->left == NULL and root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> leftAns = Solve(root->left);
    pair<bool, int> rightAns = Solve(root->right);

    bool left = leftAns.first;
    bool right = rightAns.first;
    bool condition = root->data == (leftAns.second + rightAns.second);

    pair<bool, int> ans;
    if (left and right and condition)
    {
        ans.first = true;
        ans.second = 2 * root->data; //(root->data+leftAns.second+rightAns.second)
    }
    else
        ans.first = false;
        
    return ans;
}
bool isSumTree(node *root)
{
    return Solve(root).first;
}
/*
A SumTree is a Binary Tree where the value of a node is equal to the sum of the nodes present in its left subtree and right subtree.
An empty tree is SumTree and the sum of an empty tree can be considered as 0. A leaf node is also considered as SumTree.
*/
int main()
{
    node *root1 = NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root1 = BuildTree(root1);
    cout << isSumTree(root1);
    return 0;
}