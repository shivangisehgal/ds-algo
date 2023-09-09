
//TC: O(NlogN) + O(N)
//SC: O(N) ; N = no. of intervals

/*
create merged intervals while iterating. store the merged interval temporarily in a vartiable vector (intially the vector at 0-index).
condition for merging: two intervals will be merged if the end of one interval is greater than the start of the other interval.
-thus, we have to check if the end of our temporary merged is greater than the start of the encountered interval, if yes, they'll be merged. the new end of temporary merged interval would be the maximum of the temprory and encountered interval.
-If its false, then we have our final merged interval and the two intervals cannot be merged. we'll add it to the vector of merged intervals, and this encountered interval will be our new temporary interval.
*/


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       
        vector<vector<int>> mergedIntervals; 
        if(intervals.size() == 0)
            return mergedIntervals;
    
        sort(intervals.begin(), intervals.end());
        vector<int> tempMergedInterval = intervals[0];
        for(auto inter : intervals)
        {
            if(tempMergedInterval[1] >= inter[0]) 
            {
                tempMergedInterval[1] = max(tempMergedInterval[1], inter[1]);
            }
            else
            {
                mergedIntervals.push_back(tempMergedInterval);
                tempMergedInterval = inter;
            }
        }
        
        mergedIntervals.push_back(tempMergedInterval);
        
        return mergedIntervals;
    }
};

