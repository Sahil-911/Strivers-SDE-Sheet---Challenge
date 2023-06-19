#include <bits/stdc++.h> 
using namespace std;

void insertSorted(stack<int> &stack, int val)
{
	if(stack.empty() || (!stack.empty() && stack.top()<=val))
	{
		stack.push(val);
		return;
	}
	int top=stack.top();
	stack.pop();
	insertSorted(stack,val);
	stack.push(top);
}

void sortStack(stack<int> &stack)
{
	if(stack.empty())
		return;

	int Top = stack.top();
	stack.pop();

	sortStack(stack);

	insertSorted(stack,Top);
}