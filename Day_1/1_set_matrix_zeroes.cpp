#include <bits/stdc++.h>
using namespace std;

void setZeros(vector<vector<int>> &matrix)
{
	unordered_set<int> rows,cols;
	for(int i=0;i<matrix.size();i++)
	{
		for(int j=0;j<matrix[0].size();j++)
		{
			if(matrix[i][j]==0)
			{
				rows.insert(i);
				cols.insert(j);
			}
		}
	}
	for(int i=0;i<matrix.size();i++)
	{
		for(int j=0;j<matrix[0].size();j++)
		{
			if(rows.count(i) || cols.count(j))
			{
				matrix[i][j]=0;
			}
		}
	}
}