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
pair<int,int> Solve(node* root)
{
    if(root==NULL)
    {
        pair<int,int> p=make_pair(0,0);
        return p;
    }

    pair<int,int> left=Solve(root->left);
    pair<int,int> right=Solve(root->right);
   //First represent diameter
   //Second represent height
    int leftDia=left.first;
    int rightDia=right.first;
    int leftDiaRightDia=left.second+right.second+1;
   
    pair<int,int> ans;
    ans.first=max(leftDia,max(rightDia,leftDiaRightDia));
    ans.second=max(left.second,right.second)+1;
    return ans;
}
int Diameter(node *root)
{
    return Solve(root).first;
}

int main()
{
    node *root = NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = BuildTree(root);
    cout << Diameter(root);
    return 0;
}