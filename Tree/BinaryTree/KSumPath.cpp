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

void solve(node *root, int &count, vector<int> path, int k)
{
    if (root == NULL)
        return;

    path.push_back(root->data);

    solve(root->left, count, path, k);
    solve(root->right, count, path, k);

    int size = path.size();
    int sum = 0;
    for (int i = size; i >= 0; i--)
    {
        sum += path[i];
        if (sum == k)
            count++;
    }
    path.pop_back();
}
bool sum(node *root, int k)
{
    vector<int> path;
    int count=0;
    solve(root,count,path,k);
    return count;
    //5 4 11 7 -1 -1 2 -1 -1 -1 8 13 -1 -1 4 -1 1 -1 -1
}
int main()
{
    node *root1 = NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout << "Build Tree 1 :- " << endl;
    root1 = BuildTree(root1);
    int k;
    cin >> k;
    cout << sum(root1, k);
    return 0;
}