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
void PreOrderTraversal(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}
void createMapping(int inOrder[], map<int, int> &nodeToIndex, int n)
{
    for (int i = 0; i < n; i++)
        nodeToIndex[inOrder[i]] = i;
}
node *solve(int inOrder[], int postOrder[], int &index, int inOrderStart, int inOrderEnd, int n, map<int, int> &nodeToIndex)
{
    if (index < 0 or inOrderStart > inOrderEnd)
        return NULL;
    int element = postOrder[index--];
    node *root = new node(element);
    int position = nodeToIndex[element];

    // In case of Post order the call for right comes first
    root->right = solve(inOrder, postOrder, index, position + 1, inOrderEnd, n, nodeToIndex);
    root->left = solve(inOrder, postOrder, index, inOrderStart, position - 1, n, nodeToIndex);

    return root;
}
//Build Tree from postOrder and InOrder
node *buildTree(int inOrder[], int postOrder[], int n)
{

    int postOrderIndex = n-1;
    map<int, int> nodeToIndex;

    createMapping(inOrder, nodeToIndex, n);
    node *ans = solve(inOrder, postOrder, postOrderIndex, 0, n - 1, n, nodeToIndex);
    return ans;
}
int main()
{
    int n;
    cout<<"Enter the size : -"
    cin >> n;
    int inOrder[n];
    int postOrder[n];
    cout << "Enter InOrder array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> inOrder[i];
    }
    cout << "Enter PostOrder array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> postOrder[i];
    }
    node *newTree = buildTree(inOrder, postOrder, n);
    cout << "PreOrder :- " << endl;
    PreOrderTraversal(newTree);
    return 0;
}