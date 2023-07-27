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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        vector<int> inorder1,inorder2;
        vector<int> preorder1,preorder2;
        if(preorder.empty())
            return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        int rootVal = preorder[0];
        int i=0;
        while(inorder[i]!=rootVal)
        {
            inorder1.push_back(inorder[i]);
            i++;
        }
        i++;
        while(i<inorder.size())
        {
            inorder2.push_back(inorder[i]);
            i++;
        }
        int j=1;
        for(;j<=inorder1.size();j++)
            preorder1.push_back(preorder[j]);
        while(j<preorder.size())
        {
            preorder2.push_back(preorder[j]);
            j++;
        }
        root->left = buildTree(preorder1,inorder1);
        root->right = buildTree(preorder2,inorder2);
        return root;
    }
};