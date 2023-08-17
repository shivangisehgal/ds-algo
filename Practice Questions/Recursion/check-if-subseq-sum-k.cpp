#include <bits/stdc++.h> 
bool rec(vector<int> v, int i, vector<int> &arr, int target)
{
    if(i >= arr.size())
    {
        if(target == 0)
            return true;
        else
            return false;
    }

    //pick
    if(target >= arr[i])
    {
        v.push_back(arr[i]);
        bool pick = rec(v, i + 1, arr, target - arr[i]);
        
        if(pick)
            return true;
            
        v.pop_back();
    }

    bool notpick = rec(v, i + 1, arr, target);
    
    if(notpick)
        return true;
    
    return false;
}



bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.

    vector<int> v;
    return rec(v, 0, arr, k);
}
