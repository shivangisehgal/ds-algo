//BRUTE
//Make temporary array of all sorted elements, find its median.
//TC: O(M + N)
//SC: O(M + N)

//BETTER
//Instead of temporary array, just keep a counter.
//TC: O(M + N)
//SC: O(1)

//OPTIMAL
//Create a partitions of nums1, nums2 such that total left and right halves of the merged array have (n1 + n2) / 2  elements
//Hence, if we are able to satisfy a condition that l1 <= r2 and l2 <= r1, we'll have the median as min(r1, r2) and max(l1, l2)
//if either og the conditions is not satisfied, shift the cut by one.
//TC: O(logN)
//SC: O(1)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size() > nums2.size())
            nums1.swap(nums2);
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        int s = 0;
        int e = n1;
        
        int cut1, cut2;
        
        int l1, l2, r1, r2;
        
        
        while(s <= e)
        {
            cut1 = (s + e) / 2;
            
            cut2 = ((n1 + n2) / 2) - cut1;
            
            l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            r1 = (cut1 >= n1) ? INT_MAX : nums1[cut1];
            
            l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            r2 = (cut2 >= n2) ? INT_MAX : nums2[cut2];
            
            //note that we're only applying binary search (and hence changes) on nums1
            if(l1 > r2) // go peechhe in nums1
                e = cut1 - 1;
            
            else if(l2 > r1) //of r1 < l2
                s = cut1 + 1;
            
            else
            {
                if((n1 + n2) % 2 == 0)
                    return double (max(l1, l2) + min(r1, r2)) / 2.0;
                else
                    return min(r1, r2);
            }
        }
        
        return -1;
        
    }
};
