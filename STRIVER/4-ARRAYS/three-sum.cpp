//BRUTE
//3 NESTED LOOPS
//TC: O(N^3)
//SC: O(3K)
using namespace std;
vector < vector < int >> threeSum(vector < int > & nums) {
  vector < vector < int >> ans;
  vector < int > temp;
  int i, j, k;
  for (i = 0; i < nums.size() - 2; i++) {
    for (j = i + 1; j < nums.size() - 1; j++) {
      for (k = j + 1; k < nums.size(); k++) {
        temp.clear();
        if (nums[i] + nums[j] + nums[k] == 0) {
          temp.push_back(nums[i]);
          temp.push_back(nums[j]);
          temp.push_back(nums[k]);
        }
        if (temp.size() != 0)
          ans.push_back(temp);
      }
    }
  }

  return ans;
}


//BETTER
//TWO POINTER + HASHSET
/*
Sort the array,
if the first element is poisitive, that means entire arrays is positive. stop there. Return empty vector of vectors.
else, 
select the element. for the rest of the elements ahead it, use two pointer approach. 
If sum = 0, insert the vector of three elements in answer set. move both pointers | sum < 0, move left pointer | else move right
Duplication is avoided using a set of vectors
*/
//TC: O(N^2 logN + NlogN)
//SC: O(N)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        set<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(), nums.end());
        if(nums.size() < 3){                // Base Case 1
            return {};
        }
        if(nums[0] > 0){                    // Base Case 2
            return {};
        }
        for(int i = 0; i < n; i++)
        {
            int x = nums[i];
            int s = i + 1;
            int e = n - 1;
            
            while(s < e)
            {
                int y = nums[s];
                int z = nums[e];
                
                if(y + z == -x)
                {
                    v = {x, y, z};
                    ans.insert(v);
                    
                    s++;
                    e--;
                }
                
                else if(y + z < -x)
                    s++;
                else
                    e--;
            }
            
        }
        
        vector<vector<int>> result(ans.begin(), ans.end());
        sort(result.begin(), result.end());
        
        return result;
        
    }
};

//OPTIMAL
// ONLY TWO-POINTER
/*
Sort the array,
select the element. for the rest of the elements ahead it, use two pointer approach. 
If sum = 0, insert the vector of three elements in answer set. move both pointers | sum < 0, move left pointer | else move right
//But, to avoid duplicate triplets, we are not using answer of set of vectors.
//we have to navigate to last occurences of num[low] and num[high] respectively. 
//Update the low and high with last occurences of low and high.
*/
//TC: O(N^2 + logN)
//SC: O(3 * K) K = no. of triplets


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums.size() < 3)
            return {};
        int n = nums.size();
        vector<vector<int>> ans;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0)
                break; // Numbers from this element would be positive, hence sum can't be 0
            
            if (i > 0 && nums[i] == nums[i - 1]) // Repeated number, ignore this iteration
                continue;
            
            int lo = i + 1;
            int hi = n - 1;
            
            // Search for remaining two numbers
            while (lo < hi) {
                int sum = nums[lo] + nums[hi];
                
                if (sum + nums[i] == 0) {
                    ans.push_back({nums[i], nums[lo], nums[hi]});
                    
                    while (lo < hi && nums[lo] == nums[lo + 1]) // Go to last occurrence of nums[lo]
                        lo++;
                    
                    while (lo < hi && nums[hi] == nums[hi - 1]) // Go to last occurrence of nums[hi]
                        hi--;
                    
                    lo++;
                    hi--;
                }
                else if (sum + nums[i] < 0)
                    lo++;
                else
                    hi--;
            }
        }
        
        return ans;
    }
};
