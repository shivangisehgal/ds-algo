//NEGATIVE MARKING
//TC: O(N)
//AS: O(N) / O(1)

class Solution {
    //10 2 5 10 9 1 1 4 3 7
    //
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> v;
        for(int i = 0; i < n; i++)
        {
            int idx = abs(nums[i]) - 1;
            // if(idx == n)
            //     idx = 0;
            if(nums[idx] < 0)
                v.push_back(idx + 1);
            else
                nums[idx] = -nums[idx];
        }
        sort(v.begin(), v.end());
        return v;
    }
    
    
};
