//Return subsets with sum = k, duplicates allowed.

//METHOD 1
//using pick-not-pick
void helper(vector<vector<int>>& ans, vector<int>& v, int& sum, int i, vector<int>& arr, int n, int k)
{
    if(i >= n)
    {
        if(sum == k)
            ans.push_back(v); 
        return;
    }
    
    sum += arr[i];
    v.push_back(arr[i]);
    helper(ans, v, sum, i + 1, arr, n, k);
    sum -= arr[i];
    v.pop_back();

    helper(ans, v, sum, i + 1, arr, n, k);
}


//METHOD 2
//using recursion with iterative loop.

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>> ans;
    vector<int> v;
    int sum = 0;
    helper(ans, v, sum, 0, arr, n, k);
    return ans;
}

void helper(vector<vector<int>>& ans, vector<int>& v, int& sum, int i, vector<int>& arr, int n, int k)
{
    if(sum == k)
    {
        ans.push_back(v);
        //return;
    }
    
    for(int ind = i; ind < n; ind++)
    {
        
        sum += arr[ind];
        v.push_back(arr[ind]);
        helper(ans, v, sum, ind + 1, arr, n, k);
        sum -= arr[ind];
        v.pop_back();
    }
}


vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>> ans;
    vector<int> v;
    int sum = 0;
    helper(ans, v, sum, 0, arr, n, k);
    return ans;
}
