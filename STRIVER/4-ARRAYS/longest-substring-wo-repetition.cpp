//TC: O(2N) worst case : abcdefghh, i will have to traverse the entire string in one time
//SC: O(N)
//if char has not occured yet, add it into set, calc. len -> this becomes part of our current substr
//if char has occured before, our new subs will start from this char, remove all elements from set 
//till we this char, calc. len, insert this char in map


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_set<char> map;
        int i = 0, j = 0;
        int maxlen = 0;
        int len = 0;
        while(j < s.length() and i <= j)
        {
            // if(map.find(s[j]) == map.end()) simply calculate substr length and insert char
            
            //else, erase all elements of substr from set, till this char dne in set
            //insert, calc length of new substr
            while(map.find(s[j]) != map.end())
            {
                    map.erase(s[i]);
                    i++;
            }
            
            map.insert(s[j]);
            len = j - i + 1;
            
            maxlen = max(maxlen, len);
            j++;
        }
        
        return maxlen;
    }
};


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int start = 0, end = 0;
        int len = 0, maxlen = 0;
        
        unordered_map<char, int> hashMap;
        
        while(end < s.length() and start <= end)
        {
            //repeated and is in current substring
            if(hashMap.find(s[end]) != hashMap.end() && start <= hashMap[s[end]])
            {
                start = hashMap[s[end]] + 1; //start of new substr from the next element of the index where it first occured
            }
            
            hashMap[s[end]] = end; //insert or update index
            
            len = end - start + 1;
            maxlen = max(maxlen, len);
            
            end++;
        }
        
        return maxlen;
    }
};




