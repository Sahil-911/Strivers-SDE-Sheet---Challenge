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

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    
    Node* dfs(Node* root)
    {
        if(!root)
            return  root;
            
        Node* left = dfs(root->left);
        Node* right = dfs(root->right);
        
        if(left && right)
        {
            Node* temp = left;
            root->left = root->right;
            root->right = temp;
        }
        else if(left && !right)
        {
            root->right = root->left;
            root->left = NULL;
        }
        else if(!left && right)
        {
            root->left = root->right;
            root->right = NULL;
        }
        
        return root;
        
    }
    
    void mirror(Node* node) {
        dfs(node);
    }
};