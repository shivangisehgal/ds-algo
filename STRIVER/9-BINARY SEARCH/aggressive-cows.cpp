//BRUTE
//Instead of using binary search to check for a min-distance, use a for-loop and check for each distance, find max distance.
//TC: O(N*M)
//SC: O(1)

bool isCompatible(vector < int > inp, int dist, int cows) {
  int n = inp.size();
  int k = inp[0];
  cows--;
  for (int i = 1; i < n; i++) {
    if (inp[i] - k >= dist) {
      cows--;
      if (!cows) {
        return true;
      }
      k = inp[i];
    }
  }
  return false;
}
int main() {
  sort(inp.begin(), inp.end());
  int maxD = inp[n - 1] - inp[0];
  int ans = INT_MIN;
  for (int d = 1; d <= maxD; d++) {
    bool possible = isCompatible(inp, d, m);
    if (possible) {
      ans = max(ans, d);
    }
  }
}

//OPTIMAL
//We have to place k couse such that minimum distance between any two cows is as large as possible.
//so, if maximum value of minimum distance between two cows in an arrangemenr of k cows cannot be 4, then definitely it cannot be 5, 6, 7 etc.
//first we'll have to sort the array so that the stalls are represented at number line
//assume first cow is at 0 index, start trying to place other cow at the next index.
//WE WANT THE MIN-DISTANCE BETWEEN THEM TO BE EQUAL TO MID (I.E, DISTANCE BETWEEN THEM SHOULD AT LEAST BE 4)
//if yes, place the cow there, then check whether we're able to place another cow s.t. distance between them is at least mid.
//if we're able to place k cows, then mid can be potential answer, and since we have to maximize min-distance, we'll move right.

//TC: O(N*log(M)) n: size of array, M is the search space = maxEl - minEl
//SC: O(1)

class Solution {
public:

    bool isPossible(int mid, int n, int k, vector<int> &stalls)
    {
        int cowCount = 1; 
        int lastCowPos = stalls[0]; //let one cow be placed at the 0th position
        
        //find whether we're able to place k or more cows in the stalls
        for(int i = 1; i < n; i++)
        {
            if(stalls[i] - lastCowPos >= mid) //distance between the two cows shoud be a minimum of mid
            {
                cowCount++;
                lastCowPos = stalls[i];
            }
        }
        
        if(cowCount >= k) //if we're able to place k cows
            return true;
        else
            return false;
    }


    int solve(int n, int k, vector<int> &stalls) {
        
        if(k > n)
            return 0;
            
        sort(stalls.begin(), stalls.end());
        
    //min cows can be = 2;
    //min distance b/w cows = 1
    //max distance b/w cows = max - min element
    
        int s = 1;
        int e = stalls[n - 1] - stalls[0];
        
        int mid;
        int ans = 0;
        
        while(s <= e)
        {
            mid = (s + e) / 2;
            
            if(isPossible(mid, n, k, stalls))
            {
                ans = mid; //if we're able to place k cows, it could be our potential answer
                s = mid + 1; //but since we need to find max, we can search in the right half as well
            }
            
            else
                e = mid - 1;
        }
        
        return ans;
        
    }
};
