#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *BuildTree(Node *root)
{

    cout << "Enter the data :" << endl;

    int data;
    cin >> data;

    root = new Node(data);

    if (data == -1)
        return NULL;

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = BuildTree(root->left);

    cout << "Enter data for inserting in right of " << data << endl;
    root->right = BuildTree(root->right);

    return root;
}
void solve(Node *root, vector<int> &ans, int level)
{
    if (root == NULL)
        return;

    if (level == ans.size())
        ans.push_back(root->data);
    solve(root->right, ans, level + 1);
    solve(root->left, ans, level + 1);
}
vector<int> RightView(Node *root)
{
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}

int main()
{
    Node *root = NULL;
    root = BuildTree(root);
    vector<int> ans;
    ans = RightView(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    // 3 9 -1 -1 20 15 -1 -1 7 -1 -1
    return 0;
}