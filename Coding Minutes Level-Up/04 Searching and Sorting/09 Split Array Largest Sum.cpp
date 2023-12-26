//Smallest sum:
//Q. given an array, split into k subarrays such that the subaray with minimum sum has the largest value possible

using namespace std;

bool isPossible(int minSum, int k, vector<int> coins)
{
    int sum = 0;
    
    int subarrCount = 0;
    
    for(int i = 0; i < coins.size(); i++)
    {
        // if(coins[i] > minSum)
        //     return false;
            
        sum += coins[i];
        
        if(sum >= minSum)
        {
            sum = 0;
            subarrCount++;
        }
        
    }
    
    return subarrCount >= k;
    
}


int getCoins(vector<int> arr, int k){
    //return the max coins that you can win!
    
    int low = 0;
    int high = 0;
    
    for(auto coin : arr)
        high += coin;
        
    int mid;
    int ans;
    
    while(low <= high)
    {
        mid = (low + high) / 2;
        
      if(isPossible(mid, k, arr))
        {
            ans = mid;
            low = mid + 1;
        }
            
        else
            high = mid - 1;
    }
        
    return ans;
}

//LC
//Largest Sum
//Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest subarray sum is as low as possible.
class Solution {
public:
    
    //their sum should at max be mid, only then they can be divided into k or more
    bool isPossible(int maxSum, int k, vector<int>& nums)
    {
        int sum = 0;
        int subarrCount = 1;
        
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            
            if(sum > maxSum)
            {
                sum = nums[i];
                subarrCount++;
            }
        }
        
        return subarrCount <= k;
    }
    
    int splitArray(vector<int>& nums, int k) {
        
        int low = 0;
        int high = 0;
            
        for(int i = 0; i < nums.size() ; i++)
        {
            low = max(low, nums[i]);
            high += nums[i];
        }
        
        int mid;
        int ans;
        
        while(low <= high)
        {
            mid = low + (high - low) / 2;
            
            if(isPossible(mid, k, nums))
            {
                ans = mid;
                high = mid - 1;
            }
            
            else
                low = mid + 1;
        }
        
        return ans;
    }
};
