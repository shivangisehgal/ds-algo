//for each element, the level of water filled is actually 
//the minimum of the (greatest number greater than it to the left) and 
//therefore, amount is = level of water - height of element

//TC: O(N), AS: O(N)

class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        vector<int> left(n);
        vector<int> right(n);
        
        int leftmax = 0;
        int rightmax = 0;
        
        int total_height = 0;
        //greatest element on the left
        //iterate towards right
        for(int i = 0; i < n; i++)
        {
            leftmax = max(leftmax, height[i]);
            left[i] = leftmax;
        }
        //0
        //0 1
        for(int i = n - 1; i >= 0; i--)
        {
            rightmax = max(rightmax, height[i]);
            right[i] = rightmax;
        }
        
        for(int i = 0; i < n; i++)
        {
            total_height += min(left[i], right[i]) - height[i];
        }
        
        return total_height;
    }
};