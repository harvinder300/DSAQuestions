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

node *solve(node *root, int &k, int kode)
{
    if (root == NULL)
        return NULL;
    if (root->data == kode)
        return root;
    node *leftAns = solve(root->left, k, kode);
    node *rightAns = solve(root->right, k,kode);

    if(leftAns!=NULL and rightAns==NULL)
    {
        k--;
        if(k<=0)
        {
            k=INT_MAX;
            return root;
        }
        return leftAns;
    }
    if(leftAns==NULL and rightAns!=NULL)
    {
        k--;
        if(k<=0)
        {
            k=INT_MAX;
            return root;
        }
        return rightAns;
    }
   return NULL;
}
int kthAncestor(node *root, int &k, int kode)
{
    node* ans=solve(root,k,kode);
    if(ans==NULL or ans->data==kode)
     return -1;
    else
    return ans->data;
}
int main()
{
    node *root1 = NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout << "Build Tree 1 :- " << endl;
    root1 = BuildTree(root1);
    int k;
    cin >> k;
    int node;
    cin >> node;
    cout << kthAncestor(root1, k, node);
    return 0;
}