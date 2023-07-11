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

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};

        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        int lev=0;
        while(!q.empty())
        {
            int size = q.size();
            vector<int> temp(size);
            for(int i=0;i<size;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                int idx = (lev%2==0) ? i:size-i-1;
                temp[idx]=node->data;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            lev++;
            ans.push_back(temp);
        }
        return ans;
    }
};