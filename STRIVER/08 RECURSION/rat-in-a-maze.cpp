// TC: O(3^(m*n)), because on every cell we need to try 4 different directions, 
//but the place from where the mouse has came, it can not go back at that same place back, so in conclusion, we have 3 directions.

//SC:  O(m * n), Maximum Depth of the recursion tree (auxiliary space).

class Solution {
public:
    void helper(int row, int col, string& s, vector<string>& ans, int n, vector<vector<int>>& m) {
        // Check if current position is out of bounds or the cell value is not 1
        if (row < 0 || col < 0 || row > n - 1|| col > n - 1 || m[row][col] != 1) {
            return;
        }

        // Reached destination (bottom-right cell)
        if (row == n - 1 && col == n - 1) {
            ans.push_back(s);
            return;
        }

        // Mark current cell as visited by changing its value 
        //It is mentioned In a path, no cell can be visited more than one time
        m[row][col] = -1;

        // Explore all valid directions (down, right, up, left)
        s += 'D';
        helper(row + 1, col, s, ans, n, m);
        s.pop_back();
        
        //m[row][col] = -1;
        
        // m[row][col] = 1;
        s += 'R';
        helper(row, col + 1, s, ans, n, m);
        s.pop_back();
        
        //m[row][col] = -1;
        
        // m[row][col] = 1;
        
        s += 'U';
        helper(row - 1, col, s, ans, n, m);
        s.pop_back();
        
        //m[row][col] = -1;
        
        // m[row][col] = 1;
        s += 'L';
        helper(row, col - 1, s, ans, n, m);
        s.pop_back();

        // Mark current cell as unvisited before returning
        m[row][col] = 1;
    }

    vector<string> findPath(vector<vector<int>>& m, int n) {
        string s = "";
        vector<string> ans;
        helper(0, 0, s, ans, n, m);
        return ans;
    }
};
