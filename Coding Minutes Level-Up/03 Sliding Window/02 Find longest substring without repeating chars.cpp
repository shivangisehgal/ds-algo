class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int i = 0;
        int j = 0;
        
        int maxLen = 0;
        int maxStart = 0;
        int maxEnd = 0;
        
        int n = s.length();
        
        unordered_map<char, int> map;
        
        while(j < n)
        {
            if(map.find(s[j]) != map.end() && map[s[j]] >= i)
            {
                if(maxLen < j - i)
                {
                    maxLen = j - i;
                    maxStart = i;
                    maxEnd = j - 1;
                }
                
                i = map[s[j]] + 1;
            }
            
            map[s[j]] = j;
            
            j++;
        }
        
        if(maxLen < j - i)
        {
           maxLen = j - i;
           maxStart = i;
           maxEnd = j - 1;
        }
        
        for(int k = maxStart; k <= maxEnd; k++)
            cout << s[k];
        
        cout << endl;
        
        return maxLen;
    }
};
