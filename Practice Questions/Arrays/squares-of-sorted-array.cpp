//OPTIMAL 1
//go to the first positive index.
//now the problem is actually merge sorted array, just left mein you have to traverse backwards (as negative, -4 -3 -1 <--- )

//TC: O(N)
//SC: O(N)

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        //given in increasing order
        
        int j = 0;
        int n = nums.size();
        
        while(j < n && nums[j] < 0)
            j++;

        vector<int> ans(n, 0);
        
        int k = 0;
        int i = j - 1;
        
        while(i >= 0 && j < n)
        {
            if(abs(nums[i]) < nums[j])
            {
                ans[k++] = nums[i] * nums[i];
                i--;
            }
            
            else
            {
                ans[k++] = nums[j] * nums[j];
                j++;
            }
        }
        
        while(i >= 0)
        {
            ans[k++] = nums[i] * nums[i];
            i--;
        }
        
        while(j < n)
        {
            ans[k++] = nums[j] * nums[j];
            j++;
        }
        
        return ans;
    }
};

//OPTIMAL 2
//ONE PASS

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        //given in increasing order
        //abs: BIG...small...BIG
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        
        vector<int> ans(n);
        int k = n - 1;
        
        while(k >= 0)
        {
            if(abs(nums[j]) > abs(nums[i]))
            {
                ans[k--] = nums[j] * nums[j];
                j--;
            }
            
            else
            {
                ans[k--] = nums[i] * nums[i];
                i++;
            }
        }
        
        return ans;
    
    }
};
