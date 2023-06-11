//BRUTE
//TC: O(n*m*(n + m))
//SC: O(1)

/*
whenever we encounter a 0, mark the entire row and column for that element as -1. 
(don't change zero, as it will take in consideration false values as well)
now if element i -1 or 0, make it 0.
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int r = 0; r < m; r++)
        {
            for(int c = 0; c < n; c++)
            {
                if(matrix[r][c] == 0)
                {
                    //row = 0
                    for(int j = 0; j < n; j++)
                    {
                        if(matrix[r][j] != 0)
                            matrix[r][j] = -1;
                    }
                    
                    for(int j = 0; j < m; j++)
                    {
                        if(matrix[j][c] != 0)
                            matrix[j][c] = -1;
                    }
                }
            }
        }
        
        
        for(int r = 0; r < m; r++)
        {
            for(int c = 0; c < n; c++)
            {
                if(matrix[r][c] == -1)
                    matrix[r][c] = 0;
            }
        }
        
    }
};


//BETTER
//TC: O(m*n)
//SC: O(m + n)
/*
choose two vectors for row and col, mark row and col corresponsing to each zero,
if row or col at that index is marked, make the element at that index as 0.
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> row(m, 0);
        vector<int> col(n, 0);
        
        for(int r = 0; r < m; r++)
        {
            for(int c = 0; c < n; c++)
            {
                if(matrix[r][c] == 0)
                {
                   row[r] = -1;
                   col[c] = -1;
                }
            }
        }
        
        
        for(int r = 0; r < m; r++)
        {
            for(int c = 0; c < n; c++)
            {
                if(row[r] == -1 || col[c] == -1)
                    matrix[r][c] = 0;
            }
        }
        
        return;
    }
};


//OPTIMAL
//TC: O(n*m)
//SC: O(1)
/*
use the first coumn and row for marking zeroes.
corner cases: element in first col or first row is zero.
If an element in first row is zero, that woud mean a[0][0] would become zero, which would imply that our first col will always become zero.
But, this will be wrong in case our first col doesn't contain any zero. Its also true vice versa.
Take a variable to indicate the first row has 0, and a[0][0] = 0 would thus mean that first col has zero.
(firstRowZero for first row, a[0][0] for first column)
Now, mark all the elements, barring first row and col, as 0 if their corresponding index in first row/first col is 0.
Then if a[0][0] is zero, make all elements in first col as 0
Then if first row variable is true, make all elements in first row as 0
*/

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
        //NOTE, THIS SHOULD COME FIRST, OR ELSE, IF FIRST ROW IS ZERO, IT'LL MAKE MATRIX[0][0] AS ZERO
            if(a[0][0] == 0)
            {
                for(int r = 0; r < n; r++)
                {
                        a[r][0] = 0;
                }
            }    
        //if firstRowZero is true, that means any element in first row was zero
            if(firstRowZero == true)
            {
                for(int c = 0; c < m; c++)
                    {
                        a[0][c] = 0;
                    }
            }
    }
};


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


