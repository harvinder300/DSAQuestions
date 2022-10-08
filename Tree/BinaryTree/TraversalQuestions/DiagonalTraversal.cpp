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
void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    vector<int> res;
    while (!q.empty())
    {
        Node *temp = q.front();
        
        q.pop();

        if (temp == NULL)
        {   cout<<endl;        
                    // Previous level was completed
            if (!q.empty()) // queue still has some child nodes
                q.push(NULL);
        }
        else
        {   cout<<temp->data<<" ";
            res.push_back(temp->data);
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}
vector<int> DiagonalTraversal(Node *root)
{ // 8 3 1 -1 -1 6 4 -1 -1 7 -1 -1 10 -1 14 13 -1 -1 -1
    vector<int> ans;

    if (root == NULL)
        return ans;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *FrontNode = q.front();
        q.pop();
        while (FrontNode != NULL)
        {
            if (FrontNode->left != NULL)
                q.push(FrontNode->left);
            ans.push_back(FrontNode->data);
            FrontNode = FrontNode->right;
        }
    }
    return ans;
}
// 1 2 4 -1 -1 5 -1 -1 3 6 -1 8 -1 -1 7 -1 9 -1 -1
int main()
{
    Node *root = NULL;
    root = BuildTree(root);
    levelOrder(root);

    cout <<"\nPrinting Level Order Traversal :- " << endl;
    cout<<"Diagonal Traversal :- "<<endl;
    vector<int> ans = DiagonalTraversal(root);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    cout << endl;
    // 3 9 -1 -1 20 15 -1 -1 7 -1 -1
    return 0;
}