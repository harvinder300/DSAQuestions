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
void PostOrderTraversal(node *root)
{
    if (root == NULL)
        return;
    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout << root->data << " ";
}
void createMapping(int inOrder[], map<int, int> &nodeToIndex, int n)
{
    for (int i = 0; i < n; i++)
        nodeToIndex[inOrder[i]] = i;
}
node *solve(int inOrder[], int preOrder[], int &index, int inOrderStart, int inOrderEnd, int n, map<int, int> &nodeToIndex)
{
    if (index >= n or inOrderStart > inOrderEnd)
        return NULL;
    int element=preOrder[index++];
    node* root=new node(element);
    int position=nodeToIndex[element];

    root->left=solve(inOrder,preOrder,index,inOrderStart,position-1,n,nodeToIndex);
    root->right=solve(inOrder,preOrder,index,position+1,inOrderEnd,n,nodeToIndex);
    return root; 
}
node *buildTree(int inOrder[], int preOrder[], int n)
{

    int preOrderIndex = 0;
    map<int, int> nodeToIndex;

    createMapping(inOrder, nodeToIndex, n);
    node *ans = solve(inOrder, preOrder, preOrderIndex, 0, n - 1, n, nodeToIndex);
    return ans;
}
int main()
{
    /*node *root1 = NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout << "Build Tree 1 :- " << endl;
    root1 = BuildTree(root1);*/
    int n;
    cin >> n;
    int inOrder[n];
    int preOrder[n];
    cout<<"Enter InOrder array"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin >> inOrder[i];
    }
    cout<<"Enter PreOrder array"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin >> preOrder[i];
    }
    node *newTree = buildTree(inOrder, preOrder, n);
    cout<<"PostOrder :- "<<endl;
    PostOrderTraversal(newTree);
    return 0;
}