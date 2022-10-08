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
vector<int> levelOrder(TreeNode *root)
{
    vector<int> res;
    if (root == NULL)
        return res;
    queue<TreeNode *> q;
    q.push(root);

    bool flag = true;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> temp(size);
        for (int i = 0; i < size; i++)
        {
            TreeNode *frontNode = q.front();
            q.pop();
            int index = flag ? i : size - i-1;
            temp[index] = frontNode->data;

            if (frontNode->left)
                q.push(frontNode->left);
            if (frontNode->right)
                q.push(frontNode->right);
        }

        for (auto i : temp)
            res.push_back(i);
        flag = !flag;
    }
    return res;
}
int main()
{
    TreeNode *root = NULL;
    root = BuildTree(root);
    vector<int> ans = levelOrder(root);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    // 3 9 -1 -1 20 15 -1 -1 7 -1 -1
    return 0;
}