class Solution {
public:
    bool isPal(string s, int start, int end)
    {
        while(start < end)
        {
            if(s[start] != s[end])
                return false;
            
            start++;
            end--;
        }
        
        return true;
    }
    
    void helper(int i, string s, vector<string>& v, vector<vector<string>>& ans)
    {
        if(i >= s.length())
        {
            ans.push_back(v);
            return;
        }
        
        for(int ind = i; ind < s.length(); ind++)
        {
            if(isPal(s, i, ind))
            {
                v.push_back(s.substr(i, ind - i + 1));
                helper(ind + 1, s, v, ans);
                v.pop_back();
            }
        }
        
    }
    
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> ans;
        vector<string> v;
        helper(0, s, v, ans);
        return ans;
    }
};
