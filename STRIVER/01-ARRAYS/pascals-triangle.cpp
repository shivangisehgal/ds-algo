//TC: O(N^2)
//SC: O(N^2)

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans;
        
        for(int r = 0; r < numRows; r++)
        {
            vector<int> v;
            
            for(int c = 0; c <= r; c++)
            {
                if(c == 0 || c == r)
                    v.push_back(1);
                else
                    v.push_back(ans[r - 1][c] + ans[r - 1][c - 1]);
            }
            
            ans.push_back(v);
        }
        
        return ans;
        
    }
};
