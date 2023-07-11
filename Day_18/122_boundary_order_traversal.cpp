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

bool isLeaf(TreeNode* root)
{
    return !root->left && !root->right;
}

void leftT(TreeNode* root, vector<int> &ans)
{
    TreeNode* curr=root->left;
    while(curr)
    {
        if(!isLeaf(curr))
            ans.push_back(curr->data);
        if(curr->left)
            curr = curr->left;
        else
            curr = curr->right;    
    }
}

void rightT(TreeNode* root, vector<int> &ans)
{
    TreeNode* curr=root->right;
    vector<int> temp;
    while(curr)
    {
        if(!isLeaf(curr))
            temp.push_back(curr->data);
        if(curr->right)
            curr = curr->right;
        else
            curr = curr->left;    
    }
    for(int i=temp.size()-1;i>=0;i--)
        ans.push_back(temp[i]);
}

void inorder(TreeNode* root, vector<int> &ans)
{
    if(isLeaf(root))
    {
        ans.push_back(root->data);
        return;
    }
    
    if(root->left)
        inorder(root->left,ans);
    if(root->right)
        inorder(root->right,ans);
}

vector<int> traverseBoundary(TreeNode* root){
    vector<int> ans;
    // if(!root)
    //     return ans;

    if(!isLeaf(root))
        ans.push_back(root->data);

    leftT(root,ans);
    inorder(root,ans);
    rightT(root,ans);

    return ans;
}