#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *InsertIntoBST(Node *root, int d)
{
    // base case
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }
    if (d > root->data) // Right part
        root->right = InsertIntoBST(root->right, d);
    else // left Part
        root->left = InsertIntoBST(root->left, d);
    return root;
}
void TakeInputBST(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = InsertIntoBST(root, data);
        cin >> data;
    }
}
void LevelOrderTraversal(Node *root) // or Breadth first search (BFS    )
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        { // Previous level was completed
            cout << endl;
            if (!q.empty()) // queue still has some child nodes
                q.push(NULL);
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}
void InOrderTraversal(Node *root, vector<int> &InOrder)
{
    if (root == NULL)
        return;

    InOrderTraversal(root->left, InOrder);
    InOrder.push_back(root->data);
    InOrderTraversal(root->right, InOrder);
}
bool TwoSumBST(Node *root, int target)
{
    if (root == NULL)
        return false;
    vector<int> InOrder;
    InOrderTraversal(root, InOrder);
    int i = 0, j = InOrder.size() - 1;
    while (i < j)
    {
        if (InOrder[i] + InOrder[j] == target)
            return true;
        else if (InOrder[i] + InOrder[j] < target)
            i++;
        else
            j--;
    }
    return false;
}
// 50 20 70 10 30 90 -1
int main()
{
    Node *root = NULL;
    cout << "Enter the data for BST " << endl;
    TakeInputBST(root);
    cout << "Printing the BST " << endl;
    LevelOrderTraversal(root);
    cout << endl;

    int target;
    cin >> target;

    cout << TwoSumBST(root, target);

    return 0;
}