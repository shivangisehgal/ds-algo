//1. brute - generate all subsets nested loop
//2. better using two pointer
//3. optimal using hashmap

//2. TWO POINTER

class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        if(t.length() < s.length())
            return false;
        
        int i = 0;
        int j = 0;
        
        int slen = s.length();
        int tlen = t.length();
        
        while(i < slen && j < tlen)
        {
            if(s[i] == t[j])
                i++;
            
            j++;
        }
        
        if(i == slen)
            return true;
        
        return false;
    }
};

//3. HASHMAP
//FOLLOW UP: OPTIMAL (for multiple strings)
//HASHMAP

/*
    each element in the subsequence should come after the previous one in the main string too.
    i.e, if index of s[i] <= s[i - 1] in main string, it is not a subsequnce.
*/

//TC: O(length of s * length of t) 
//IF YOU USE UPPER BOUND STL FUNCTION: TC: O(length of s * log(length of t))
//SC: O(length of t)

class Solution {
public:
    bool isSubsequence(string s, string t) {
    
        if(t.length() < s.length())
            return false;
            
        unordered_map<char, vector<int>> indices;  //store the indices of occurances of each character
        
        for(int i = 0; i < t.length(); i++)
            indices[t[i]].push_back(i);
        
        int ind_from_big = -1;
        
        for(int j = 0; j < s.length(); j++)
        {
            if(indices.find(s[j]) == indices.end())
                return false;
            
            vector<int> v = indices[s[j]];
            int prev_ind_from_big = ind_from_big;
            
            for(int i = 0; i < v.size(); i++)
            {
                int ind = v[i];
                
                if(ind > ind_from_big)
                {
                   ind_from_big = ind;
                   break;
                }
            }
            
            if(ind_from_big == prev_ind_from_big)
                return false;
        }
        
        return true;
    }
};
