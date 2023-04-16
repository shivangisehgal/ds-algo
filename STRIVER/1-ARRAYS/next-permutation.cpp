//BRUTE
// Find all possible permutations of elements present and store them.
// Search input from all possible permutations.
// Print the next permutation present right after it.
//TC: O(N!xN)
//SC: O(1) not considering stack space



//OPTIMAL
/*
    Find the first index from the last where, a[i + 1] > a[i]
    Find the next bigger to a[i] from the numbers scanned till now
    replace a[i] with its next bigger number scanned till
    now you just need the sorted sequence of number after i.
    it will already be sorted but in reverse order, since we checked for the point where sortedness breaks and replace that number with its next bigger number, thus maintaining the increasing order
    so just reverse the sequence after i.
*/
// TC: O(N + N + N) 
// Finding the break-point, finding the next greater element, and reversal at the end takes O(N) for each, where N is the number of elements in the input array. This sums up to 3*O(N) which is approximately O(3N).
// SC: O(1)

class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int n = nums.size();
        
        if(n <= 1)
            return;
        
        bool flag = false;
        
        for(int i = n - 2; i >= 0 ; i--)
        {
            if(nums[i + 1] > nums[i])
            {
                flag = true;
                //ith to be swapped
                for(int j = n - 1; j > i; j--)
                {
                    if(nums[j] > nums[i]) //jth just greater than ith
                    {
                        swap(nums[j], nums[i]);
                        break; //now, will still be in sorted order, because we swapped with just 'greater' that means all numbers encountered till now are smaller.
                    }
                }
                
                reverse(nums.begin() + i + 1, nums.end()); 
                break;
            }
        }
        
        if(!flag)
            reverse(nums.begin(), nums.end());
    }
};
