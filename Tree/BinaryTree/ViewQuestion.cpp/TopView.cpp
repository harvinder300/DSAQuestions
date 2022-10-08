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
vector<int> topView(Node *root)
{
    //Basically the approach is same as vertical order traversal
    //in map we make entry for a level , and if there is more than one entry for same level we discard it 
    vector<int> ans;
    if (root == NULL)
        return ans;
    queue<pair<Node *, int>> q;
    // queue<pair<Node*,horizontal distance>>
    map<int, int> topNode;
    //map<horizontal distance,node->Data>
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();
        Node *frontNode = temp.first;
        int horizontalDistance = temp.second;
        // if value is present for a Horizontal Distance then do nothing
        if (topNode.find(horizontalDistance) == topNode.end())
            topNode[horizontalDistance] = frontNode->data;

        if (frontNode->left)
            q.push(make_pair(frontNode->left,horizontalDistance-1));
       
        if (frontNode->right)
            q.push(make_pair(frontNode->right,horizontalDistance+1));
    }

    for(auto i:topNode)
        ans.push_back(i.second);
    return ans;
}
int main()
{
    Node *root = NULL;
    root = BuildTree(root);
    vector<int> ans;
    ans = topView(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    // 3 9 -1 -1 20 15 -1 -1 7 -1 -1
    return 0;
}