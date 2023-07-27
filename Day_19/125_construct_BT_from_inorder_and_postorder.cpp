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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        vector<int> inorder1, inorder2, postorder1, postorder2;
        if(postorder.empty())
            return NULL;
        int rootVal = postorder.back();
        TreeNode* root = new TreeNode(rootVal);
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
        int j=0;
        while(j<inorder1.size())
        {
            postorder1.push_back(postorder[j]);
            j++;
        }
        while(j<postorder.size()-1)
        {
            postorder2.push_back(postorder[j]);
            j++;
        }
        root->left = buildTree(inorder1,postorder1);
        root->right = buildTree(inorder2,postorder2);
        return root;

    }
};