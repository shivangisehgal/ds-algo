//for mountain peak,  a[i - 1] < a[i] > a[i + 1]
//identify a mountain peak, go to the left (nested and count the elements that constitute the mountain subarray
//go to right and elements that constitute the mountain subarray, the can't be elements of another mountain coz it should have a peak.
//TC: O(N), AS: O(1)

class Solution {
public:
    int longestMountain(vector<int>& a) {
        
        int n = a.size();
        int length = 0;
        int max_length = 0;
        
        for(int i = 1; i < n - 1; i++)
        {
            if(a[i]  > a[i + 1] and a[i] > a[i - 1]) //mountain sub array
            {
                int j = i;
                length = 1;
                while(j > 0 and a[j] > a[j - 1])
                {
                    length++;
                    j--;
                }
                
                while(i < n - 1 and a[i] > a[i + 1])
                {
                    length++;
                    i++;
                }
                
                max_length = max(max_length, length);
            }
        }
        
        return max_length;
    }
};