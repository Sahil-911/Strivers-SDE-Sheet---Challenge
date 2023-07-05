#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

void find(TreeNode *root, int x, vector<int> &path) {
    if (root == NULL)
        return;

    path.push_back(root->data);

    if (root->data == x)
        return;

    if (root->left)
        find(root->left, x, path);
    if (root->right)
        find(root->right, x, path);

    if (path.back() != x)
        path.pop_back();
}

vector<int> pathInATree(TreeNode *root, int x) {
    vector<int> path;
    find(root, x, path);
    return path;
}
