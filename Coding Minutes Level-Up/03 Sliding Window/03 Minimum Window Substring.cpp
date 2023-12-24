//sliding window approach
//keep expanding the window size, untill you have all the characters (with at least >= their freq) in the window
//now, once you have all, try contracting from left
//keep expaning

//TC: O(2N)
//SC: O(N + M)

class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char, int> FT;
        unordered_map<char, int> FS;
        
        for(auto ch : t)
            FT[ch]++;
        
        int n = s.length();
        
        int i = 0;
        int j = 0;
        
        int size = 0;
        
        int minStart = -1;
        int minLen = INT_MAX;
        
        while(j < n)
        {
            char ch = s[j];

            FS[ch]++;
            
            //EXPANSION
            //if char exists in t AND freq of char in substring is greater than freq in t => size++;
            if(FT[ch] != 0 && FS[ch] <= FT[ch]) //helllo | elo => second l shouldn't be included
                size++;
            
            if(size == t.length()) //t found in substring -> start contraction, also find min length
            {
                //CONTRACTION
                while(FT[s[i]] == 0 || FS[s[i]] > FT[s[i]])
                {
                    FS[s[i]]--;
                    i++;
                }
                
                if(j - i + 1 < minLen)
                {
                    minLen = j - i + 1;
                    minStart = i;
                }
            }
            
            j++;
            
        }
        
        if(minStart == -1)
            return "";
        
        return s.substr(minStart, minLen);
    }
};
