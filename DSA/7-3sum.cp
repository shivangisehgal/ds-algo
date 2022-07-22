//TWO-POINTER

//sort the array, for each element x, find the two numbers such that the sum of the numbers = target - x
//use two pointer approach for each elemnt, and store the three numbers in a vector, and store those vectors in a set to avoid duplicacy
//convert set to vector
//TC: O(N^2), AS: O(N) (?)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        set<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i++)
        {
            int x = nums[i];
            int s = i + 1;
            int e = n - 1;
            
            while(s < e)
            {
                int y = nums[s];
                int z = nums[e];
                
                if(y + z == -x)
                {
                    v = {x, y, z};
                    ans.insert(v);
                    
                    s++;
                    e--;
                }
                
                else if(y + z < -x)
                    s++;
                else
                    e--;
            }
            
        }
        
        vector<vector<int>> result(ans.begin(), ans.end());
        sort(result.begin(), result.end());
        
        return result;
        
    }
};



//HASHMAP 
//????