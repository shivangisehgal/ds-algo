//OPTIMAL
//Prefix XOR with hashMap / Variable Sliding Window
//TC: O(N)
//SC: O(N)
int Solution::solve(vector<int> &nums, int B) 
{
    unordered_map<int, int> prefixXORmap;
    int xorSum = 0;
    int count = 0;
    prefixXORmap[xorSum]++;
    for(int i = 0; i < nums.size(); i++)
    {
        xorSum ^= nums[i];
        
        if(prefixXORmap.find(xorSum^B) != prefixXORmap.end())
        {
            count += prefixXORmap[xorSum^B];
        }
        
        prefixXORmap[xorSum]++;
    }
    
    return count;
}
