//BRUTE
//SORT the array 
//TC: O(NlogN), AS: O(1) 

//BETTER
//Map or frequency array, refill the array accordingly
//TC: O(N), AS: O(1) (only if n is large)

//OPTIMAL
//DNF SORT 
//At any point, every element before low is 0, every element after high is 2, 
//every element in between are either 0, 1 or 2 i.e. unprocessed.
//TC: O(N), AS: O(1)
void sortColors(vector<int>& nums) {
        
        // initialize variables:
        int low = 0, mid = 0, high = nums.size() - 1;
        
        // logic:
        while(mid <= high)
        {
            switch(nums[mid])
            {
                case 0: swap(nums[low++], nums[mid++]); break;
                
                case 1: mid++; break;
                
                case 2: swap(nums[mid], nums[high--]); break;
            }
        }
    }
