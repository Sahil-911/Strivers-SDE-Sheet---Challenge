#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    for(int i=0;i<matrix.size();i++)
	    {
	        for(int j=0;j<matrix.size();j++)
	        {
	            if(matrix[i][j]==-1)
	                matrix[i][j] = 1e9; 
                if(i==j)
                    matrix[i][j] = 0;
	        }
	    }
	    for(int k=0;k<matrix.size();k++)
	    {
	        for(int i=0;i<matrix.size();i++)
	        {
	            for(int j=0;j<matrix.size();j++)
	            {
	                matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
	            }
	        }
	    }
	    for(int i=0;i<matrix.size();i++)
	    {
	        for(int j=0;j<matrix.size();j++)
	        {
	            if(matrix[i][j]==1e9)
	                matrix[i][j] = -1; 
	        }
	    }
	}
};