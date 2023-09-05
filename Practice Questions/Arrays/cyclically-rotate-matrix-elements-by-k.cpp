class Solution {
public:
    
    
    vector<vector<int>> rotateGrid(vector<vector<int>>& mat, int k) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        int startRow = 0, startCol = 0, endRow = n - 1, endCol = m - 1;
        int prev, curr;

        while(startRow < endRow && startCol < endCol)
        {

            //IMPORTANT, EK HI BAAR MEIN K TIME ROTATE KARDO!
            
            int num =  2 * (endCol - startCol + endRow - startRow);
            
            int temp_k = k % num;
            
            while(temp_k--)
            {
                int prev = mat[startRow + 1][endCol];

                //move elements of first row

                for(int i = endCol; i >= startCol; i--)
                {
                    int curr = mat[startRow][i];
                    mat[startRow][i] = prev;
                    prev = curr;
                }

                //now prev = first element of first row

                //move elements of first column

                for(int i = startRow + 1; i <= endRow; i++)
                {
                    int curr = mat[i][startCol];
                    mat[i][startCol] = prev;
                    prev = curr;
                }

                //move elements of last row

                for(int i = startCol + 1; i <= endCol; i++)
                {
                    int curr = mat[endRow][i];
                    mat[endRow][i] = prev;
                    prev = curr;
                }

                //move elements of the last col

                for(int i = endRow - 1; i >= startRow + 1; i--)
                {
                    int curr = mat[i][endCol];
                    mat[i][endCol] = prev;
                    prev = curr;
                }

            }
            
            startRow = startRow + 1;
            startCol = startCol + 1;
            endRow = endRow - 1;
            endCol = endCol - 1;
        }
        
        return mat;
    }
};
