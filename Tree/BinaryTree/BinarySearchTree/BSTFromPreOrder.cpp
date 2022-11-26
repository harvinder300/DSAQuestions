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
Node *InOrderToBST(vector<int> &InOrder, int s, int e)
{
    if (s > e)
        return NULL;

    int mid = s + (e - s) / 2;
    Node *root = new Node(InOrder[mid]);
    root->left = InOrderToBST(InOrder, s, mid - 1);
    root->right = InOrderToBST(InOrder, mid + 1, e);
    return root;
}
void PostOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout << root->data << " ";
}
Node *solve(vector<int> &pre, int low, int high, int &index)
{
    if (index >= pre.size())
        return NULL;
    if (pre[index] < low || pre[index] > high)
        return NULL;
    Node *root = new Node(pre[index++]);
    root->left = solve(pre, low, root->data, index);
    root->right = solve(pre, root->data, high, index);
    return root;
}
Node *bstFromPreorder(vector<int> &preorder)
{
    int i = 0;
    int min = INT_MIN;
    int max = INT_MAX;
    Node *ans = solve(preorder, min, max, i);
    return ans;
}

// 50 20 70 10 30 90 -1
// 40 30 32 35 80 90 100 120
int main()
{
    int n;
    cin >> n;
    int x;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    Node *root = bstFromPreorder(v);
    cout << "BST From PreOrder :- " << endl;
    PostOrderTraversal(root);
    return 0;
}