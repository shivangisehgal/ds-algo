//TC: O(N * logN)
//SC: O(N)

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool cmp(pair<int, int> a, pair<int, int> b)
    {
        return a.second < b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> meetings;
        
        for(int i = 0; i < n; i++)
        {
            meetings.push_back(make_pair(start[i], end[i]));
        }
        
        sort(meetings.begin(), meetings.end(), cmp);
        
        int currEnd = meetings[0].second;
        int count = 1;
        
        for(int i = 1; i < n; i++)
        {
            if(meetings[i].first > currEnd)
            {
                count++;
                currEnd = meetings[i].second;
            }
        }
        
        return count;
    }
};
