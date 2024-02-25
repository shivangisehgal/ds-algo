//BRUTE
//TC: O(m * nlogn)
//SC: O(n)

//Store nums[l-r] in a vector, sort the vector, check d for each adj. pair
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        int n = nums.size();
        int m = l.size();
        
        vector<bool> ans;
        
        for(int i = 0; i < m; i++)
        {
            int low = l[i];
            int high = r[i];
            
            if(high == low || high - low == 1)
            {
                ans.push_back(true);
                continue;
            }
            
            vector<int> v;
            
            for(int ind = low; ind <= high; ind++)
                v.push_back(nums[ind]);
            
            sort(v.begin(), v.end());
            
            int d = v[1] - v[0];
            
            bool flag = false;
            
            for(int ind = 1; ind < v.size() - 1; ind++)
            {
                if(v[ind + 1] - v[ind] != d)
                {
                    ans.push_back(false);
                    flag = true;
                    break;
                }
            }
            
            if(!flag)
                ans.push_back(true);
        }
        
        
        return ans;
        
    }
};

//BRUTE-BETTER
//O(m * n) (or O(m * nlogn) //hashset
//Store all nums[l-r] in a hashset
//Find d as (An - A) / (n - 1)
//Check if any Ai does not exist.
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        int n = nums.size();
        int m = l.size();
        
        vector<bool> ans;
        
        for(int i = 0; i < m; i++)
        {
            int low = l[i];
            int high = r[i];
            
            if(high == low || high - low == 1)
            {
                ans.push_back(true);
                continue;
            }
            
            unordered_set<int> hashSet;
            
            int a = INT_MAX;
            int a_n = INT_MIN;
            
            for(int ind = low; ind <= high; ind++)
            {
                a = min(a, nums[ind]);
                a_n = max(a_n, nums[ind]);
                
                hashSet.insert(nums[ind]);
            }
            
            int sz = hashSet.size();
            
            if(sz == 1)
            {
                ans.push_back(true);
                continue;
            }
               
            if(sz < high - low + 1)
            {
                ans.push_back(false);
                continue;
            }
            
            if((a_n - a) % (sz - 1) != 0)
            {
                ans.push_back(false);
                continue;
            }
            
            int diff = (a_n - a) / (sz - 1);
            int a_i = a + diff;
            cout << a_i << " ";
            bool flag = false;
            
            while(a_i < a_n)
            {
                if(hashSet.find(a_i) == hashSet.end())
                {
                    
                    ans.push_back(false);
                    flag = true;
                    break;
                }
                
                a_i += diff;
            }
            
            if(!flag)
                ans.push_back(true);
        
        }
        
        return ans;
    }
};
