//TC: O(N)
//SC: O(N)

#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> s;
    vector<int> ans(n);


    for(int i = n - 1; i >= 0; i--)
    {
        int x = arr[i];


        while(!s.empty() && x <= s.top())
            s.pop();
        
        if(s.empty())
            ans[i] = -1;
        else
            ans[i] = s.top();
        
        s.push(x);
    }


    return ans;
}
