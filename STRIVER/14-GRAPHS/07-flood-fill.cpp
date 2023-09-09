//TC: O(4*N*M)
//SC:  O(N*M)
class Solution {
public:
    
    void rec(int i, int j, int prevColor, int color, vector<vector<int>>& image, int m, int n)
    {
        
        if(i < 0 || j < 0 || i >= m || j >= n)
            return;
        
        if(image[i][j] == prevColor && image[i][j] != color)
        {
            image[i][j] = color;
            
            rec(i - 1, j, prevColor, color, image, m, n);
            rec(i, j - 1, prevColor, color, image, m, n);
            rec(i + 1, j, prevColor, color, image, m, n);
            rec(i, j + 1, prevColor, color, image, m, n);
        }
        
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        rec(sr, sc, image[sr][sc], color, image, image.size(), image[0].size());
        return image;
    }
};
