BASIC IMPLEMENTATIVE EXAMPLE OF PICK- NOT PICK RECURSION

//TC: O(2^N)
//SC: O(2^N)

class Solution
{
  public:

void helper(int i, int sum, vector<int>& v, vector<int>& arr, int N)
{
    if(i >= N)
    {
        v.push_back(sum);
        return;
    }
        
    //pick
    sum += arr[i];
    helper(i + 1, sum, v, arr, N);
    
    //don't pick
    sum -= arr[i];
    helper(i + 1, sum, v, arr, N);
    
}
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> v;
        helper(0, 0, v, arr, N);
        return v;
    }
};
