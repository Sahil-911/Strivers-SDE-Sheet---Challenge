#include <bits/stdc++.h>
using namespace std; 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/
int M[101][101] = {};
bool knows(int a,int b);


int findCelebrity(int n) {
	stack<int> st;
	for(int i=0;i<n;i++)
		st.push(i);
	while(st.size()!=1)
	{
		int a = st.top();
		st.pop();
		int b = st.top();
		st.pop();

		if(knows(a,b))
			st.push(b);
		else
			st.push(a);
	}
	bool rowCheck = false;
	int zcnt = 0;
	for(int i=0;i<n;i++)
	{
		if(M[st.top()][i]==0)
			zcnt++;
	}

	if(zcnt==n)
		rowCheck=true;

	bool colCheck = false;
	int ocnt = 0;
	for(int i=0;i<n;i++)
	{
		if(M[i][st.top()]==1)
		ocnt++;
	}
	
	if(ocnt==n-1)
		colCheck=true;
	
	if(rowCheck && colCheck)
		return st.top();
	else
		return -1;	
}