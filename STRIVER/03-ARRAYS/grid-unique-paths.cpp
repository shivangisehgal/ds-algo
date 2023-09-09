//BRUTE
//RECURSION
//TC: exponential
//SC: exponential (considering recursive stack space)

class Solution {
public:
    
    int helper(int i, int j, int m, int n)
    {
        if(i >= m or j >= n)
            return 0;
        else if(i == (m - 1) and j == (n - 1))
            return 1;
        
        int path = helper(i + 1, j, m, n) + helper(i, j + 1, m, n);
        return path;
    }
    
    int uniquePaths(int m, int n) {
        return helper(0, 0, m, n);
    }
};

//TODO:
//BETTER
//DP 
//TC: O(N*M)
//SC: O(N*M)

//OPTIMAL
//using PnC 
//TC: O(m) or O(n)
//SC: O(1)

/*
    For m = 3, n = 2, we'll have D R R, R R D, R D R
    we'll always have 2 R's and 1 D's => (m - 1) Rs and (n - 1) Ds
    total number of directions = (m - 1 + n - 2) = m + n.- 2
    Thus, out of all combinations of Rs and Ds, if we take the number of ways to get
    2Rs -> 3C2 or if we take the number of ways to get 1 Ds -> 3C1
    => (m + n - 2)C(m - 1)
    
    
*/

class Solution {
public:
    
    int nCr(int N, int r)
    {
        double res = 1;
            
        for (int i = 1; i <= r; i++)
            res = res * (N - r + i) / i;
        
        return (int)res;
    }
    
    int uniquePaths(int m, int n) {
        return nCr(m + n - 2, m - 1);
    }
};
