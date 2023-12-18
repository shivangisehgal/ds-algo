//given an array of numbers, make a string by arranging them in such a manner that it is the largest
//sorting should be: 

//9 
//5  

//355 
//35  => yeh dekhna hai ki string 35535 bada ya 35355 lexicographically (baaki sab lexicographically anyway ho jaayenge, 95 > 5001 even if we use condition 955001 bada ya 500195)
//351 
//350 
//3501

// 34 
// 3400 

// 3 
// 30


class Solution {
public:
    
    static bool comp(int a, int b)
    {
        string s1 = to_string(a);
        string s2 = to_string(b);
        
        string s1s2 = s1 + s2;
        string s2s1 = s2 + s1;
        
        return s1s2 > s2s1;
    }
    
    string largestNumber(vector<int>& nums) {
        
        string ans = "";
        
        sort(nums.begin(), nums.end(), comp);
        
        int i = 0;
        
        while(i < nums.size() && nums[i] == 0)
            i++;
        
        while(i < nums.size())
        {
            ans += to_string(nums[i]);
            i++;
        }
        
        return ans == "" ? "0" : ans;
    }
};
