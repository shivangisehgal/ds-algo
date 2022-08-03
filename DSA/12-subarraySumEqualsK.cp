//HASHMAP


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int, int> map;
        int sum = 0;
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            
            if(sum == k)
                count++;
            //prefix[i] - prefix[j] = k
            //i.e, sum - (sum - k) => k
            if(map.find(sum - k) != map.end())
                count += map[sum - k]; //increasing the count equal number of occurences of this sum (eg p) so that we can form p subarrays
            map[sum]++;
        }
        
        return count;
    }
};