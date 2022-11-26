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
vector<TreeNode *> Reverse(int size, vector<TreeNode *> &level)
{
    int l = 0, r = level.size() - 1;
    while (l < r)
    {
        int x = level[l]->data;
        int y = level[r]->data;
        level[l]->data = y;
        level[r]->data = x;
        l++, r--;
    }
    return level;
}
TreeNode *reverseOddLevels(TreeNode *root)
{

    queue<TreeNode *> q;
    q.push(root);

    bool reverse = false;

    while (!q.empty())
    {
        int size = q.size();
        vector<TreeNode *> level;
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
            level.push_back(node);
        }

        if (reverse)
        {
            Reverse(size, level);
            reverse = false;
        }

        else
            reverse = true;
    }
    return root;
}
// 2 3 8 -1 -1 13 -1 -1 5 21 -1 -1 34 -1 -1
vector<int> levelOrder(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);
    vector<int> res;
    vector<int> ans;
    while (!q.empty())
    {
        TreeNode *temp = q.front();

        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            // Previous level was completed
            if (!q.empty()) // queue still has some child nodes
                q.push(NULL);
        }
        else
        {
            cout << temp->data << " ";
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
    cout << "ReverseOddLevels" << endl;
    root = reverseOddLevels(root);
    cout << "Printing Level Order Traversal :- " << endl;
    vector<int> ans = levelOrder(root);
    for (auto i : ans)
        cout << i << " ";
    // 3 9 -1 -1 20 15 -1 -1 7 -1 -1
    return 0;
}