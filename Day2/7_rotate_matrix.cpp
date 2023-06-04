#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        for(int i=0;i<matrix.size();i++)
        {
            vector<int> x;
            for(int j=0;j<matrix[0].size();j++)
            {
                x.push_back(matrix[j][i]);
            }
            ans.push_back(x);
        }
        matrix=ans;
    }
};