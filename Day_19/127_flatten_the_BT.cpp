#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    TreeNode* dfs(TreeNode* root)
    {
        if(!root)
            return root;

        TreeNode* leftTail = dfs(root->left);
        TreeNode* rightTail = dfs(root->right);

        if(root->left)
        {
            leftTail->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }

        if(rightTail)
            return rightTail;
        else if(leftTail)
            return leftTail;
        return root;
    }

    void flatten(TreeNode* root) {
        dfs(root);
    }
};