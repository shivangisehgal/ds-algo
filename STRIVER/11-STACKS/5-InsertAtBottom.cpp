//Recursive Solution

// TC: O(N)
// SC: O(N)

#include <bits/stdc++.h> 

void helper(stack<int>& s, int x)
{
    if(s.empty())
    {
        s.push(x);
        return;
    }


    int top = s.top();
    s.pop();


    helper(s, x);


    s.push(top);
}


stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    helper(myStack, x);
    return myStack;
}
