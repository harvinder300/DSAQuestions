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
pair<int, int> PreAndSucc(Node *root, int key)
{
    // find Key
    Node *temp = root;
    int pre = -1;
    int succ = -1;
    while (temp->data != key)
    {
        if (temp->data > key)
        {
            succ = temp->data;
            temp = temp->left;
        }
        else
        {
            pre = temp->data;
            temp = temp->right;
        }
    }
    Node *leftTree = temp->left;
    while (leftTree != NULL)
    {
        pre = leftTree->data;
        leftTree = leftTree->right;
    }
    Node *rightTree = temp->right;
    while (rightTree != NULL)
    {
        succ = rightTree->data;
        rightTree = rightTree->left;
    }
    pair<int, int> ans = make_pair(pre, succ);
    return ans;
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
    int key;
    cin >> key;
    pair<int, int> ans = PreAndSucc(root, key);
    cout << ans.first << " " << ans.second;
    return 0;
}