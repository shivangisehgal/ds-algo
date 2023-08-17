

#include <bits/stdc++.h> 
int rec(vector<int> v, int i, vector<int> &arr, int target)
{
    if(i >= arr.size())
    {
        if(target == 0)
            return 1;
        else
            return 0;
    }

    //pick
	int pick = 0;
	
    if(target >= arr[i])
    {
        v.push_back(arr[i]);
        pick = rec(v, i + 1, arr, target - arr[i]);
        v.pop_back();
    }

    int notpick = rec(v, i + 1, arr, target);
    
    return pick + notpick;
}



int findWays(vector<int>& arr, int k){
    // Write your code here.

    vector<int> v;
    return rec(v, 0, arr, k);
}
