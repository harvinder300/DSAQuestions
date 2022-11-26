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
int burnTree(Node *root, map<Node *, Node *>& nodeToParent)
{
    queue<Node *> q;

    map<Node *, bool> visited;
    int ans = 0;
    q.push(root);
    visited[root] = true;

    while (!q.empty())
    {
        int size = q.size();
        bool flag = 0;
        for (int i = 0; i < size; i++)
        {
            Node *front = q.front();
            q.pop();

            if (front->left and !visited[front->left])
            {
                q.push(front->left);
                visited[front->left] = 1;
                flag = 1;
            }
            if (front->right and !visited[front->right])
            {
                q.push(front->right);
                visited[front->right] = 1;
                flag = 1;
            }
            if (nodeToParent[front] and !visited[nodeToParent[front]])
            {
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = 1;
                flag = 1;
            }
        }
        if (flag == 1)
            ans++;
    }
    return ans;
}
Node *createParentMapping(Node *root, int target, map<Node *, Node *> &nodeToParent)
{
    queue<Node *> q;
    Node *res = NULL;
    q.push(root);
    nodeToParent[root] = NULL;

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        if (front->data == target)
            res = front;
        if (front->left)
        {
            nodeToParent[front->left] = front;
            q.push(front->left);
        }
        if (front->right)
        {
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    return res;
}
int minTime(Node *root, int target)
{
    map<Node *, Node *> nodeToParent;
    Node *targetNode = createParentMapping(root, target, nodeToParent);
    int ans = burnTree(targetNode, nodeToParent);
    return ans;
}
int main()
{
    Node *root = NULL;
    root = BuildTree(root);

    // 3 9 -1 -1 20 15 -1 -1 7 -1 -1
    return 0;
}