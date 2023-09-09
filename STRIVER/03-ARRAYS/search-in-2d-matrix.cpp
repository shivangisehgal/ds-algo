//BRUTE
//Traverse through every element and return true if found
// Time complexity: O(m*n)
// Space complexity: O(1)

//OPTIMAL
//binary Search
// Time complexity: O(log(m*n))
// Space complexity: O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int s = 0;
        int e = (m * n) - 1;
        int mid;
        
        while(s <= e)
        {
            mid = (s + e) / 2;
            
            if(matrix[mid / n][mid % n] == target)
                return true;
            
            else if(target < matrix[mid / n][mid % n])
            {
                e = mid - 1;
            }
            
            else
                s = mid + 1;
        }
        
        return false;
    }
};
