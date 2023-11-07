//TC: O(N)
//SC: O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int maxArea = 0;
        
        int s = 0;
        int e = height.size() - 1;
        
        while(s < e)
        {
            int minHeight = min(height[s], height[e]);
            int area = minHeight * (e - s);
            
            maxArea = max(area, maxArea);
            
            if(height[s] == height[e])
            {
                s++;
                e--;
            }
            
            else if(height[s] < height[e])
                s++;
            
            else
                e--;
        }
        
        return maxArea;
    }
};
