#include <bits/stdc++.h> 
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void Traversal(Node* root, vector<vector<int>> &orders)
{
    if(root==NULL)
        return;

    orders[1].push_back(root->data);
    Traversal(root->left,orders);
    orders[0].push_back(root->data);
    Traversal(root->right,orders);
    orders[2].push_back(root->data);

}

vector<vector<int>> getTreeTraversal(Node *root){
    vector<vector<int>> orders(3);
    Traversal(root,orders);
    return orders;
}