//BRUTE
//Calculate area for all pairs of heights using nested for loop
//TC:O(N^2), AS: O(1)

//BETTER
//TWO-POINTER
//start with maximum width, keep on decreasing width -> to right if left height is smaller. or left if right height is smaller, or from both if equal
//TC: O(N), AS: O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n = height.size();
        int h;
        int area = 0;
        int maxarea = 0;
        
        int i = 0;
        int j = n - 1; //because we need to maximise width
        
        
        while(i < j)
        {
            h = min(height[j], height[i]);
            area = h * (j - i);
            maxarea = max(maxarea, area);
            
            if(height[i] < height[j])
                i++; //we want h to be maximum and h is the minimum of height[i] and height[j]
            else if(height[j] < height[i])
                j--;
            else
            {
                i++;
                j--;
            }
        }
        return maxarea;
        
    }
};