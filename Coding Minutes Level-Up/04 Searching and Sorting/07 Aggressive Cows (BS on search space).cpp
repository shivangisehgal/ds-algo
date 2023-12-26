//Problem type is distribute m items, such that minimum distance between them is as large as possible.
//Return the largest value of this min distance possible

//binary search, where distance between each bird is (at least) mid.
//if can, arrange all -> answer, go aage
//else go peechhe.

//TC: O(N * log(Xmax - Xmin))
//SC: O(1)
class Solution {
private:
    
    bool isPossible(int minDistance, int m, vector<int>& position)
    {
        int ballCount = 1;
        int prevPos = position[0];
        
        for(int i = 1; i < position.size(); i++)
        {
            if(position[i] - prevPos >= minDistance)
            {
                ballCount++;
                prevPos = position[i];
            }
            
            if(ballCount == m)
                return true;
        }
        
        return ballCount >= m;
    }
    
public:
    int maxDistance(vector<int>& position, int m) {
        
        sort(position.begin(), position.end());
        
        int low = 0;
        int high = position[position.size() - 1] - position[0];
        
        int mid;
        
        int ans = low;
        
        while(low <= high)
        {
            mid = low + (high - low) / 2;
            
            if(isPossible(mid, m, position))
            {
                ans = mid;
                low = mid + 1;
            }
            
            else
                high = mid - 1;
        }
        
        return ans;
        
    }
};
