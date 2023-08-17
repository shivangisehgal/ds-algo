#include <bits/stdc++.h> 
void insertInSortedStack(stack<int> &s, int x)
{
	if(s.empty() || x >= s.top())
	{
		s.push(x);
		return;
	}

	int top = s.top();
	s.pop();
	insertInSortedStack(s, x);
	s.push(top);
}
void helper(stack<int> &s)
{
	if(s.empty())
		return;
		
	int top = s.top();
	s.pop();

	helper(s);

	insertInSortedStack(s, top);
}
void sortStack(stack<int> &stack)
{
	// Write your code here
	helper(stack);
}
