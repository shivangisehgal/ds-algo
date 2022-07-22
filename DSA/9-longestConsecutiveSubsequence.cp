//BRUTE
//Sort the array, calculate length of longest consecutive subsequence
//TC: O(NlogN), SC: O(1)

//OPTIMAL
//Using a map, find out the possible start points of a consecutive subsequence
//if a[i] - 1 exists in map, then its not a start point, else it is.
//the calculate its length.
//TC: O(N), SC: O(N)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int> map;
        
        for(int x : nums)
            map.insert(x);
        int length = 0;
        int max_length = 0;
        for(int x : nums)
        {
            if(map.count(x - 1) == 0)
            {
                //x is the start of the sub sequence
                length = 0;
                int y = x;
                while(map.count(y) != 0)
                {
                    length++;
                    y++;
                }
                
                max_length = max(length, max_length);
            }
        }
        
        return max_length;
    }
};
