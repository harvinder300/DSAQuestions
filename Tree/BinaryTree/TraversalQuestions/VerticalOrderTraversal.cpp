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
vector<int> VerticalOrderTraversal(TreeNode *root)
{
    vector<int> ans;

    if (root == NULL)
        return ans;
    map<int, map<int, vector<int>>> nodes;
    // map< horizontalDistance , map<level,vector<list of node>>>
    
    queue<pair<TreeNode *, pair<int, int>>> q;
    // queue< pair< TreeNode*, pair< horizontalDistance,level>>>

    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty())
    {
        pair<TreeNode *, pair<int, int>> temp = q.front();
        q.pop();

        TreeNode *frontNode = temp.first;
        int horizontalDistance = temp.second.first;
        int level = temp.second.second;
        
        nodes[horizontalDistance][level].push_back(frontNode->data);
        if (frontNode->left)
            q.push(make_pair(frontNode->left, make_pair(horizontalDistance - 1, level + 1)));
        if (frontNode->right)
            q.push(make_pair(frontNode->right, make_pair(horizontalDistance + 1, level + 1)));
    }

    for (auto i : nodes)
        for (auto j : i.second)
            for (auto k : j.second)
                ans.push_back(k);
                
    return ans;
}
// 1 2 4 -1 -1 5 -1 -1 3 6 -1 8 -1 -1 7 -1 9 -1 -1
int main()
{
    TreeNode *root = NULL;
    root = BuildTree(root);
    
    vector<int> ans = VerticalOrderTraversal(root);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    cout << endl;
    // 3 9 -1 -1 20 15 -1 -1 7 -1 -1
    return 0;
}