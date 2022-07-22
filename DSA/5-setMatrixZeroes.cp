//BRUTE 
//Make another matrix 
//TC: O(M * N)
//SC: O(M * N)

//BETTER
//Keep a row and column vector each
//TC: O(M * N)
//SC: O(M + N)

//OPTIMAL
//Modification of 'Better' - In Place
//to differentiate between first row and first column - 
//keep a variable for either one of them, for the other a[0][0] would be 0
//TC: O(M * N)
//SC: O(1)

class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        
        int n = a.size();
        int m = a[0].size();

          int firstRowZero = false;

          for(int r = 0; r < n; r++)
            {
                for(int c = 0; c < m; c++)
                {
                      if(a[r][c] == 0)
                      {
                          //if element is from first col, only then a[0][0] = 0
                          a[0][c] = 0;
                          
                          //otherwise, if element is from first row, keep a variable to say a[0][0] = 0
                          if(r == 0)
                          {
                              firstRowZero = true;
                          }
                          
                          //if element is not from the first row
                          else
                          a[r][0] = 0;
                          
                      }
                }
            }

            for(int r = 1; r < n; r++)
            {
                for(int c = 1; c < m; c++)
                {
                    if(a[0][c] == 0 || a[r][0] == 0)
                    {
                        a[r][c] = 0;
                    }
                }
            }
        
        //if a[0][0], that means any element in first col was zero
            if(a[0][0] == 0)
            {
                for(int r = 0; r < n; r++)
                {
                    for(int c = 0; c < m; c++)
                    {
                        a[r][0] = 0;
                    }
                }
            }    
        //if firstRowZero is true, that means any element in first row was zero
            if(firstRowZero == true)
            {
                for(int r = 0; r < n; r++)
                {
                    for(int c = 0; c < m; c++)
                    {
                        a[0][c] = 0;
                    }
                }
            }
    }
};