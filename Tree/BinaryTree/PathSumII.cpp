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
void solve(node *root, int targetSum, vector<vector<int>> &ans,vector<int> temp)
{
    if (root == NULL)
        return;

    temp.push_back(root->data);
    if (!root->left && !root->right)
        if (root->data == targetSum)
            ans.push_back(temp);
    
    solve(root->left, targetSum - root->data, ans, temp);
    solve(root->right, targetSum - root->data, ans, temp);
    temp.pop_back();
}
vector<vector<int>> pathSum(node *root, int targetSum)
{
    vector<vector<int>> ans;
    vector<int> temp;
    solve(root, targetSum, ans,temp);
    return ans;
    // 5 4 11 7 -1 -1 2 -1 -1 -1 8 13 -1 -1 4 5 -1 -1 1 -1 -1
}
int main()
{
    node *root1 = NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout << "Build Tree 1 :- " << endl;
    root1 = BuildTree(root1);
    int targetSum;
    cin >> targetSum;
    vector<vector<int>> ans = pathSum(root1, targetSum);
    cout<<"Path :-"<<endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}