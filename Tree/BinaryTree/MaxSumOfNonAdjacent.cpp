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
pair<int, int> solve(node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> leftAns = solve(root->left);
    pair<int, int> rightAns = solve(root->right);

    pair<int, int> res;

    res.first = root->data + leftAns.second + rightAns.second;
    res.second = max(leftAns.first, leftAns.second) + max(rightAns.first, rightAns.second);

    return res;
}
int getMaxSum(node *root)
{
    pair<int, int> ans;
    ans = solve(root);
    return max(ans.first, ans.second);
}
int main()
{
    node *root1 = NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout << "Build Tree 1 :- " << endl;
    root1 = BuildTree(root1);

    return 0;
}