//BRUTE
/*
check all possible quadruplets using 4 loops(as we did in the 3-sum problem)
among them, consider the ones whose sum is equal to the given target. 
And before considering them as our answer, sort the quadruplets in ascending order.
*/
//TC: O(N^4)
//SC: O(2 * No. of quadrouplets)

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    set<vector<int>> st;

    //checking all possible quadruplets:
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                for (int l = k + 1; l < n; l++) {
                    // taking bigger data type
                    // to avoid integer overflow:
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if (sum == target) {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}


//BETTER - like 3 sum, Use 3 nested loops with hashset
//TC: O(N^3 logM) //M = no. of elements in the set.
//SC: O(2 * No. of quadrouplets) + O(N) // for vector<vector<int> and set<vector<int>> + unordered hashset
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        int n = nums.size();
        set<vector<int>> ans_set;

        for (int i = 0; i < n; i++) 
        {
            int p = nums[i];

            for (int j = i + 1; j < n; j++) 
            {
                int q = nums[j];
                
                //Run two - sum
                unordered_set<long long> map;
                for (int k = j + 1; k < n; k++) 
                {
                    int r = nums[k];
                    
                    //taking care of overflow
                    long long sum = p + q;
                    sum += r;
                    long long s = target - sum;

                    if (map.find(s) != map.end()) 
                    {
                        vector<int> temp = {p, q, r, (int)s};
                        sort(temp.begin(), temp.end()); //sorting will not lead to arrays with same numbers but different combos
                        ans_set.insert(temp); //set will remove duplicate arrays
                    }

                    map.insert(r);
                }
            }
        }

        vector<vector<int>> ans_vector(ans_set.begin(), ans_set.end());
        return ans_vector;
    }
};


//Optimizing - getting rid of internal hashset to look-up s and external set to store arrays
//OPTIMAL
//Similar to 3-sum approach - 3 NESTED LOOPS AND TWO POINTER
/*
Choose first element, ensure that its not duplicate
Choose second element, ensure its not duplicate
For next two elements, use two pointer approach.
To avoid duplicates, go to the last occurences of these two numbers
*/
//TC: O(n^3)
//SC: O(no. of quadruplets)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        if(nums.size() < 4)
            return {};
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++)
        {
            if(i > 0 and nums[i] == nums[i - 1])
                continue;
            
            
            int p = nums[i];
            
            for(int j = i + 1; j < n; j++)
            {
                
                if(j > i + 1 and nums[j] == nums[j - 1])
                    continue;
                
                int q = nums[j];
                
                int lo = j + 1;
                int hi = n - 1;
                
                
                while(lo < hi)
                {
                    
                    long long sum = p + q;
                    sum += nums[lo];
                    sum += nums[hi];
                    
                    if(sum == target)
                    {
                        ans.push_back({p, q, nums[lo], nums[hi]});
                        
                        while(lo < hi and nums[lo] == nums[lo + 1])
                            lo++;
                        
                        while(lo < hi and nums[hi] == nums[hi - 1])
                            hi--;
                        
                        lo++;
                        hi--;
                    }
                    
                    else if (sum < target)
                        lo++;
                    else
                        hi--;
                }
            }
        }
        
        return ans;
    }
};
