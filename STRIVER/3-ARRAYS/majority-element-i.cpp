//BRUTE
//count occurance of each element, find max.
//TC: O(N^2)
//SC: O(1)

//BETTER
//use a DS like hashmap, store occurances in that hashmap, find max value, return the key.
// TC: O(N*logN) + O(N), where N = size of the given array.
// Reason: We are using a map data structure. Insertion in the map takes logN time. And we are doing it for N elements. So, it results in the first term O(N*logN). The second O(N) is for checking which element occurs more than floor(N/2) times.
// If we use unordered_map instead, the first term will be O(N) for the best and average case and for the worst case, it will be O(N2).
//SC: O(N)

//OPTIMAL
//Moore's Voting algorithm
//keep a count variable and a variable for ans, if the element encountered is ans, count++, else count--, if count < 0 => change ans;
//tc: O(N)
//SC: O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int count = 0;
        int majorityElement = nums[0];
        
        for(auto element : nums)
        {
            if(count == 0)
                majorityElement = element;
            if(element == majorityElement)
                count += 1;
            else
                count -= 1;
        }
        
        return majorityElement;
    }
};

//another method of recn:
class Solution {
public:
    
    int countElement(int target, vector<int>& nums, int s, int e)
    {
        int count = 0;
        for(int i = s; i <= e; i++)
        {
            if(nums[i] == target)
                count++;
        }
        return count;
    }
    
    
    int helper(vector<int>& nums, int s, int e)
    {
        // base case; the only element in an array of size 1 is the majority
        // element.
        
        if(s == e)
            return nums[s];
        
        // recurse on left and right halves of this slice.
        int mid = (s + e) / 2;
        
        int leftMajority = helper(nums, s, mid);
        int rightMajority = helper(nums, mid + 1, e);
        
         // if the two halves agree on the majority element, return it.
        if(leftMajority == rightMajority)
            return (leftMajority | rightMajority);
        
        // otherwise, count each element and return the "winner".
        int leftMajorityCount = countElement(leftMajority, nums, s, e);
        int rightMajorityCount = countElement(rightMajority, nums, s, e);
        
        if(leftMajorityCount > rightMajorityCount)
            return leftMajority;
        else
            return rightMajority;
    }
    
    
    
    
    int majorityElement(vector<int>& nums) 
    {
        int s = 0;
        int e = nums.size() - 1;
        return helper(nums, s, e);
    }
    
};
