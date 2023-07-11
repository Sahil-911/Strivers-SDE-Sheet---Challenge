#include <bits/stdc++.h>
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

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    bool isBalanced(TreeNode *root)
    {
        if (!root)
            return true;

        int left = 0;
        int right = 0;

        if (root->left)
            left = maxDepth(root->left);
        if (root->right)
            right = maxDepth(root->right);

        return abs(left - right) < 2 && isBalanced(root->left) && isBalanced(root->right);
    }
};