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
void Solve(node *root, int sum, int &maxSum, int len, int &maxLen)
{
    if (root == NULL)
    {
        if (len > maxLen)
        {
            maxLen = len;
            maxSum = sum;
        }
        else if (len == maxLen)
        {
            maxSum = max(maxSum, sum);
        }
        return;
    }

    sum = sum + root->data;
    Solve(root->left, sum, maxSum, len + 1, maxLen);
    Solve(root->right, sum, maxSum, len + 1, maxLen);
}
int SumOfLongRootToLeafPath(node *root)
{
    int len = 0;
    int maxLen = 0;

    int sum = 0;
    int maxSum =INT16_MIN;

    Solve(root, sum, maxSum, len, maxLen);
    return maxSum;
}
int main()
{
    node *root1 = NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout << "Build Tree 1 :- " << endl;
    root1 = BuildTree(root1);
    cout<<SumOfLongRootToLeafPath(root1);
    return 0;
}