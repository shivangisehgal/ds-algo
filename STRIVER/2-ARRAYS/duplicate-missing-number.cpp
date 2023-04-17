#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &temp, int n)
{
    
    int ans = 0;
    int duplicateNumber = 0;
    for(int i = 0; i < n; i++)
    {
        ans ^= abs(temp[i]);
        ans ^= (i + 1);
        int idx = abs(temp[i]);
        if(temp[idx] < 0)
        {
            duplicateNumber = idx;
            ans ^= duplicateNumber;
        }
        else
            temp[idx] = -temp[idx];
    }
    
    return make_pair(ans, duplicateNumber);

	
}
