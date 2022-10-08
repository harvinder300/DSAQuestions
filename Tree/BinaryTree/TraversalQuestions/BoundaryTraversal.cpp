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
void TraverseRight(Node *root, vector<int> &ans)
{

    if (root == NULL or (root->left == NULL and root->right == NULL))
        return;
    if (root->right)
        TraverseRight(root->right, ans);
    else
        TraverseRight(root->left, ans);
    // Wapas aagye to pushback
    ans.push_back(root->data);
}
void TraverseLeafNode(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    if (root->left == NULL and root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }
    TraverseLeafNode(root->left, ans);
    TraverseLeafNode(root->right, ans);
}
void TraverseLeft(Node *root, vector<int> &ans)
{
    if (root == NULL or (root->left != NULL and root->right != NULL))
        return;

    ans.push_back(root->data);
    if (root->left)
        TraverseLeft(root->left, ans);
    else
        TraverseLeft(root->right, ans);
}
vector<int> BoundaryTraversal(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    ans.push_back(root->data);
    // Left part
    TraverseLeft(root->left, ans);
    // Left Subtree
    TraverseLeafNode(root->left, ans);
    // Right Subtree
    TraverseLeafNode(root->right, ans);
    // Right Part
    TraverseRight(root->right, ans);

    return ans;
} // 1 2 4 -1 -1 5 8 -1 -1 9 -1 -1 7 -1 -1
int main()
{
    Node *root = NULL;
    root = BuildTree(root);
    vector<int> ans;
    ans = BoundaryTraversal(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    // 3 9 -1 -1 20 15 -1 -1 7 -1 -1
    return 0;
}