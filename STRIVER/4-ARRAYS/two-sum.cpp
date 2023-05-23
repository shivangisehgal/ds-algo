//BRUTE
//use nested loops
//TC: O(N*N)
//SC: O(1)

//BETTER - 1
//USE HASHMAP
//TC: O(N)
//SC: O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> hashtable;
        vector<int> ans(2);
        for(int i = 0; i < nums.size(); i++)
        {
            int x = target - nums[i];
            if(hashtable.count(x) != 0)
            {
                ans[0] = i;
                ans[1] = hashtable[x];
            }
            
            hashtable[nums[i]] = i;
        }
        
        return ans;
    }
};

//BETTER - 2 (CONST EXTRA SPACE)
//SORT, USE TWO POINTERS
//TC: O(N + NlogN)
//SC: O(1) //if index not asked, O(N) if index asked.
class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) 
    {
        
        if(v.size() == 0 || v.size() == 1)
            return {};
        
        vector<pair<int, int>> nums;
        
        for(int i = 0; i < v.size(); i++)
        {
            nums.push_back(make_pair(v[i], i));
        }
        
        sort(nums.begin(), nums.end());
        
        int s = 0;
        int e = nums.size() - 1;
        
        while(s < e)
        {
            int sum = nums[s].first + nums[e].first;
            if(sum == target)
                return {nums[s].second, nums[e].second};
            else if(sum < target)
                s++;
            else
                e--;
        }
        
        return {};
    }
};
