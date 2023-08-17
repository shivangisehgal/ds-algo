class Solution { 
    
    void rec(string letters, int i, string& digits, vector<string>& ans, vector<string>& phone){
        if(i == digits.length())
        {
            ans.push_back(letters);
            return;
        }
        
        string s = phone[digits[i] - '0'];
        
        for(int ind = 0; ind < s.length(); ind++)
        {
            char let = s[ind];
            rec(letters + let, i + 1, digits, ans, phone);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> phone = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        vector<string> ans;
        
        if(digits == "")
            return {};
        
        rec("", 0, digits, ans, phone);
        
        return ans;
    }
};
