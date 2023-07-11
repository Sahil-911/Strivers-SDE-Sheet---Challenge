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
    int widthOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        queue<pair<TreeNode *, pair<long long, long long>>> q;
        q.push({root, {1, 0}});
        long long ans = 1;

        while (!q.empty())
        {
            int size = q.size();
            int mini = q.front().second.first;
            long long first;
            long long last;

            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front().first;
                long long num = q.front().second.first - mini;
                long long lev = q.front().second.second;
                q.pop();

                if (i == 0)
                    first = num;
                if (i == size - 1)
                    last = num;

                if (node->left)
                    q.push({node->left, {num * 2 + 1, lev + 1}});

                if (node->right)
                    q.push({node->right, {num * 2 + 2, lev + 1}});
            }
            ans = max(ans, last - first + 1);
        }

        return ans;
    }
};