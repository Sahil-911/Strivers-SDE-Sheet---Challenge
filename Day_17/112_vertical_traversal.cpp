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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root)
            return {{}};

        map<int,priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>> m;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int cnt=0;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                TreeNode* n = q.front().first;
                int line = q.front().second;
                q.pop();
                m[line].push({cnt,n->val});
                if(n->left)
                    q.push({n->left,line-1});
                if(n->right)
                    q.push({n->right,line+1});
            }
            cnt++;
        }
        vector<vector<int>> ans;
        for(auto i:m)
        {
            vector<int> nodes;
            while(!i.second.empty())
            {
                nodes.push_back(i.second.top().second);
                i.second.pop();
            }
            ans.push_back(nodes);
        }
        return ans;
    }
};