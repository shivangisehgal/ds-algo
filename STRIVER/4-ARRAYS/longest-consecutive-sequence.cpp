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
