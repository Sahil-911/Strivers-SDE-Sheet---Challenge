#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

vector<int> leftview(Node *root)
{
    if (!root)
        return {};

    queue<Node *> q;
    q.push(root);
    vector<int> ans;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> temp;
        while (size--)
        {
            Node *n = q.front();
            q.pop();
            temp.push_back(n->data);
            if (n->left)
                q.push(n->left);
            if (n->right)
                q.push(n->right);
        }
        ans.push_back(temp[0]);
    }
    return ans;
}