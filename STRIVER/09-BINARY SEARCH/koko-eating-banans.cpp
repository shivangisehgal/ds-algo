//USE BINARY SEARCH
//k can be minimum 1 /hr or max = no. of piles. /hr
//if time taken when eating speed is k > h, then that means we have to decrease time => increase speed (k) => s = mid + 1
//else, mid can be potential answer, move left so as to know if we can increase our time to the time limit h
//TC: O(N * log W)
//SC: O(1)

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int m = *max_element(piles.begin(), piles.end());
        
        int s = 1;
        int e = m;
        int mid;
        int k = m;
        
        while(s <= e)
        {
            mid = (s + e) / 2;
            
            int sum = 0;
            
            for(int i = 0; i < piles.size(); i++)
            {
                sum += (piles[i] / mid);
                
                if((piles[i] % mid) != 0)
                    sum++;
            }
            
            if(sum <= h) // beacuse we have to find minimum value. so it might be possible that
                //smaller values of k also satisfy sum <= h
            {
                k = min(k, mid);
                e = mid - 1;
            }
            
            else //if sum > h, then we need to choose a bigger value of k as pile / k is large rn
                s = mid + 1;
            
        }
        
        
        return k;
    }
};

