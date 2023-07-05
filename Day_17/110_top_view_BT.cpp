#include<bits/stdc++.h>
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

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        if(!root)
            return {};

        map<int,Node*> um;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        um[0]=root;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                Node* n = q.front().first;
                int line = q.front().second;
                q.pop();
                if(n->left)
                {
                    q.push({n->left,line-1});
                    if(um.find(line-1)==um.end())
                        um[line-1]=n->left;
                }
                if(n->right)
                {
                    q.push({n->right,line+1});
                    if(um.find(line+1)==um.end())
                        um[line+1]=n->right;
                }
            }
        }
        vector<int> ans;
        for(auto i:um)
            ans.push_back(i.second->data);
        return ans;
    }
};