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
vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);
    vector<int> res;
    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();

        if (temp == NULL)
        {                   // Previous level was completed
            if (!q.empty()) // queue still has some child nodes
                q.push(NULL);
            ans.push_back(res);
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
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    TreeNode *root = NULL;
    root = BuildTree(root);
    vector<vector<int>> ans = levelOrder(root);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    } // 3 9 -1 -1 20 15 -1 -1 7 -1 -1
    return 0;
}