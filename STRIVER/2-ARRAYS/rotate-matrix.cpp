//TC: O(M*N)
//SC: O(1)

//Tanspose and reverse matrix from left to right

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        
        //transpose of matrix
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = i+1; j < matrix.size(); j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        //reverse matrix from left to right
        for(int j = 0; j < matrix.size(); j++)
        {
            reverse(matrix[j].begin(), matrix[j].end());
        }
    }
};
