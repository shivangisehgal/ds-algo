//DNF SORT
/*
we have three partions, left of i should contain 0s, right of k should contain 2s.
j is the unknow iterator.
If nums[j] = 2, swap it with the kth element, so that 2's go to extreme right.
Now the element that we've brought from the right, could be a 0 or 1 or 2.
So we won't move j.
Left of j will thus always contain 0 or 1, since nums[j] will always be checked for 2, and would get swapped if it is.
Thus, if nums[j] = 0, we'll swap with the ith element so that 0's go to extreme left.


*/

//TC: O(N)
//SC: O(1)

class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int n = nums.size();
        int i = 0, j = 0, k = n - 1;
        //1 0 1 1 2 0
        
        while(j <= k)
        {
            if(nums[j] == 0)
            {
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
            else if(nums[j] == 2)
            {
                swap(nums[k], nums[j]);
                k--;
            }
            else
                j++;
        }
    }
};

