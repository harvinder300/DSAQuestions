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
int ans = 0;
void solve(node *root, int number)
{

    if (!root)
        return;
    number = number * 10 + root->data;
    if (root->left == NULL and root->right == NULL)
    {
        ans += number;
        return;
    }
    solve(root->left, number);
    solve(root->right, number);
}
int sumNumbers(node *root)
{
    solve(root, 0);
    return ans;
}

int main()
{
    node *root1 = NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout << "Build Tree 1 :- " << endl;
    root1 = BuildTree(root1);
    cout << sumNumbers(root1);
    return 0;
}