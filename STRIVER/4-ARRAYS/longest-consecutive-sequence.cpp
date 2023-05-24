//BRUTE
//SORT, then find length
//TC: O(NlogN + N)
//SC: O(1)
int longestConsecutive(vector<int> nums) 
{
        if(nums.size() == 0 ){
            return 0;
        }
        
        sort(nums.begin(),nums.end());
        
        int ans = 1;
        int prev = nums[0];
        int cur = 1;
        
        for(int i = 1;i < nums.size();i++){
            if(nums[i] == prev+1){
                cur++;
            }
            else if(nums[i] != prev){
                cur = 1;
            }
            prev = nums[i];
            ans = max(ans, cur);
        }
        return ans;
}

//BETTER (LESS TC)
//STORE ELEMENTS IN HASHSET, COUNT THE LENGTH OF EVERY SEQUENCE FROM ITS START USING THE HASHSET
//TC: O(N + 2N) (every number will be iterated max twice in second loop) (assuming HashSet takes O(1) to search)
//SC: O(N) 

/*
Intuition:
The logic behind using a HashSet for solving the longest consecutive sequence problem comes from the observation that for any given element, if we can find its consecutive elements (i.e., the element - 1, element - 2, element - 3, and so on) in the array, we can form a longer consecutive sequence.

Let's consider an example:

Input: [100, 4, 200, 1, 3, 2]

If we iterate over the array and start with the element 4, we can see that the elements 3, 2, and 1 are present in the array. Thus, we have a sequence [4, 3, 2, 1] with a length of 4.

Now, if we encounter the element 3, we can notice that we have already processed it when we started with 4. So, there is no need to repeat the same computation for 3. Similarly, the elements 2 and 1 have also been processed before.

This observation leads us to the idea of using a HashSet to store all the elements from the array. The HashSet provides constant-time look-up, allowing us to quickly check if an element is present in the set or not.
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
        unordered_set<int> s;
        
        for(int num : nums)
            s.insert(num);
        
        int maxlength = 0;
        int length = 0;
        for(int num : nums)
        {
            if(s.find(num - 1) != s.end()) //this number is not the start of the sequence
                continue;
            
            //else
            int currNum = num; //start of the sequence
            length = 0;
            
            while(s.find(currNum) != s.end())
            {
                length++;
                currNum++;
            }
            
            maxlength = max(length, maxlength);
        }
        
        return maxlength;
    }
};
