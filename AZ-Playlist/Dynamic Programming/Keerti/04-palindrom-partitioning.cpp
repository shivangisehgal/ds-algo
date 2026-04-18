//The condition to partition at ind2 is that, ind1...ind2 is a palindrome
//try to "add a" partition at each step after adding the last => recursion + dp.

//i.e., 
//  Precompute all palindromic substrings (Gap Method/Interval DP),
// then use backtracking to find all ways to partition s such that
// every substring in the partition is a palindrome.

// TC: O(n^2) precomputation + O(n * 2^n) backtracking
//                  => O(n * 2^n) overall
// SC: O(n^2) for dp table + O(n) recursion 

class Solution {
    vector<vector<bool>> dp;
    vector<vector<string>> ans;

    void findAllPal(string& s){
        int n = s.length();
        dp.resize(n, vector<bool>(n, false));

        for (int len = 1; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;

                if (s[i] == s[j]) {
                    if (len <= 2)
                        dp[i][j] = true;
                    else
                        dp[i][j] = dp[i + 1][j - 1];
                } else
                    dp[i][j] = false;
            }
        }
    }

    void addPartition(int ind1, vector<string>& res, string& s){
        if(ind1 == s.length()){
            //successfully reached the end.
            ans.push_back(res);
            return;
        }

        for(int ind2 = ind1; ind2 < s.length(); ind2 ++){ //try all ways to add partition after ind1
            if(dp[ind1][ind2]){ //isPal
                res.push_back(s.substr(ind1, ind2 - ind1 + 1));
                addPartition(ind2 + 1, res, s);
                res.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        findAllPal(s);
        vector<string> res;
        addPartition(0, res, s);

        return ans;
    }
};
