#include<bits/stdc++.h>
using namespace std;

// function Template for C++
// A binary tree node has data, pointer to left child and a pointer to right child //
struct Node
{
    int data;
    struct Node* left;
    struct Node* right; 

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; 

bool dfs(Node* root)
{
    if(!root)
        return true;

    if(root->left && root->right)
        return root->data == root->left->data + root->right->data && dfs(root->left) && dfs(root->right);
    else if(root->left && !root->right)
        return root->left->data == root->data && dfs(root->left);
    else if(!root->left && root->right)
        return root->right->data == root->data && dfs(root->right);
    return true;
}

bool isParentSum(Node *root){
    return dfs(root);
}