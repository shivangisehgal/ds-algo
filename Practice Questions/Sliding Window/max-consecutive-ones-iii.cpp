// BETTER: two pointers
// TC: O(2N)
 class Solution {
 public:
     int longestOnes(vector<int>& nums, int k) {
         //max consecutive subarray with at most K zeroes
         int zeroes = 0;
         int l = 0, r = 0;
         int n = nums.size();

        int maxlen = 0;

        while(l <= r && r < n){
            if(nums[r] == 0)
                zeroes++;

            while(zeroes > k){
                if(nums[l] == 0)
                    zeroes--;
                l++;
            }
            maxlen = max(r - l + 1, maxlen);
            r++;
        }

        return maxlen;
    }
};

// OPTIMAL
// TWO PTR + SLIDING WINDOW.

// TC: O(N)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // max consecutive subarray with at most K zeroes

        int zeroes = 0;
        int l = 0, r = 0;
        int n = nums.size();

        int maxlen = 0;

        while (l <= r && r < n) {
            if(nums[r] == 0)
                zeroes++;
            
            if(zeroes > k){
                if(nums[l] == 0)
                    zeroes--;
                l++;
            }

            if(zeroes <= k){
                maxlen = max(r - l + 1, maxlen);
            }

            r++;
        }

        return maxlen;
    }
};
