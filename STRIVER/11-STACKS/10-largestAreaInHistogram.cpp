//length is constant, we need to maximize width
//for each element, check the span of the rectangle, where length can be this element.
//Find area

//Brute
//Find index of first smaller to left and first smaller to right for each element (loop wise)
//Find max area
//TC: O(N^2)
//SC: O(N)

//Optimal
//Do the above using stack
//TC: O(N)
//SC: O(N)

class Solution {
public:
    int largestRectangleArea(vector<int>& hist) 
    {
         int n = hist.size();
        stack<int> s;
 
        vector<int> left(n);
        vector<int> right(n);


        for(int i = n - 1; i >= 0; i--)
        {
            while(!s.empty() and hist[i] <= hist[s.top()])
                s.pop();

            if(s.empty())
                right[i] = n;

            else
                right[i] = s.top();

            s.push(i);
        }

        while(!s.empty())
            s.pop();
  
        for(int i = 0; i < n; i++)
        {
            while(!s.empty() and hist[i] <= hist[s.top()])
                s.pop();

            if(s.empty())
                left[i] = -1;

            else
                left[i] = s.top();

            s.push(i);
        }

        int maxArea = 0;
        int length;
        int width;

        for(int i = 0; i < n; i++)
        {
            width = right[i] - left[i] - 1;
            length = hist[i];

            maxArea = max(maxArea, length * width);
        }

        return maxArea;
    }
};
