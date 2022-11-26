#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode *BuildTree(TreeNode *root)
{

    cout << "Enter the data :" << endl;

    int data;
    cin >> data;

    root = new TreeNode(data);

    if (data == -1)
        return NULL;

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = BuildTree(root->left);

    cout << "Enter data for inserting in right of " << data << endl;
    root->right = BuildTree(root->right);

    return root;
}
vector<int> largestValues(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);
    vector<int> res;
    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            if (!q.empty())
                q.push(NULL);
            int x = *max_element(res.begin(), res.end());
            ans.push_back(x);
            res.clear();
        }
        else
        {
            res.push_back(temp->data);
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    return ans;
}
int main()
{
    TreeNode *root = NULL;
    root = BuildTree(root);
    cout << "Printing Level Order Traversal :- " << endl;
    vector<int> ans = largestValues(root);
    for (auto i : ans)
        cout << i << " ";
    // 3 9 -1 -1 20 15 -1 -1 7 -1 -1
    return 0;
}