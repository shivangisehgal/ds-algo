
//BETTER
//USE MAP
//TC: O(N) / O(NlogN)
//SC: O(N)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> map;
        vector<int> ans;
        for(int num : nums)
            map[num]++;
        
        for(auto i : map)
        {
            if(i.second > (n / 3))
                ans.push_back(i.first);
        }
        
        return ans;
    }
};

//OPTIMAL
//EXTENDED MOORE'S VOTING
/*
    https://takeuforward.org/data-structure/majority-elementsn-3-times-find-the-elements-that-appears-more-than-n-3-times-in-the-array/
*/
//TC: O(N)
//SC: O(1)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
      int sz = nums.size();
      int num1 = INT_MIN, num2 = INT_MIN, count1 = 0, count2 = 0, i;
        
      for (i = 0; i < sz; i++) 
      {
        if (nums[i] == num1)
          count1++;
          
        else if (nums[i] == num2)
          count2++;
          
        else if (count1 == 0) 
        {
          num1 = nums[i];
          count1 = 1;
        } 
          
        else if (count2 == 0) 
        {
          num2 = nums[i];
          count2 = 1;
        } 
        
        else 
        {
          count1--;
          count2--;
        }
          
      }
      //this will give us two elements that occur more than others, but it might not be that they occur more than n / 3 times
      vector <int> ans;
      count1 = count2 = 0;
        
      for (i = 0; i < sz; i++) 
      {
        if (nums[i] == num1)
          count1++;
          
        else if (nums[i] == num2)
          count2++;
      }
        
      if (count1 > sz / 3)
        ans.push_back(num1);
      if (count2 > sz / 3)
        ans.push_back(num2);
        
      return ans;
        
    }
};
