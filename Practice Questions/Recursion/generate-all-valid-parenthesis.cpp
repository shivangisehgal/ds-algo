class Solution {
    
    void rec(string s, int i, int n, int openCount, int closeCount, vector<string>& ans)
    {
        if(i == 2 * n)
        {
            ans.push_back(s);
            return;
        }
        
        if(openCount < n)
            rec(s + '(', i + 1, n, openCount + 1, closeCount, ans);
        
        if(openCount > 0 && closeCount < openCount)
            rec(s + ')', i + 1, n, openCount, closeCount + 1, ans);
    }
    
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        int openCount = 0;
        
        rec(s, 0, n, 0, 0, ans);
        
        return ans;
    }
};
