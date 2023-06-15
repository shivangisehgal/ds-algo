//BRUTE 
//store all permutations, sort the array of string, find the kth perm.
//TC: O(N! * N) + O(N! Log N!)
//SC: O(N) //not considering stack space

class Solution {
public:
    void helper(int i, vector<string>& ans, string &s)
    {
        
        if(i == s.length())
        {
            ans.push_back(s);
            return;
        }
        
        for(int ind = i; ind < s.length(); ind++)
        {
            swap(s[ind], s[i]);
            helper(i + 1, ans, s);
            swap(s[ind], s[i]);
        }
    }
    
    string getPermutation(int n, int k) {
        
        string s = "";
        for(int i = 1; i <= n; i++)
        {
            s += to_string(i);
        }
        vector<string> ans;
        helper(0, ans, s);
        sort(ans.begin(), ans.end());
        return ans[k - 1];
    }
};


