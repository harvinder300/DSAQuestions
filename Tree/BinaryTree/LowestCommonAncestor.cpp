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
node *lca(node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;
    if (root->data == n1 or root->data == n2)
        return root;

    node *leftAns = lca(root->left, n1, n2);
    node *rightAns = lca(root->right, n1, n2);

    if (leftAns != NULL and rightAns != NULL)
        return root;
    else if (leftAns != NULL and rightAns == NULL)
        return leftAns;
    else if (leftAns == NULL and rightAns != NULL)
        return rightAns;
    else
        return NULL;
}
int main()
{
    node *root1 = NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout << "Build Tree 1 :- " << endl;
    root1 = BuildTree(root1);
    int n1,n2;
    cin>>n1>>n2;
    
    cout<<lca(root1,n1,n2);
    return 0;
}