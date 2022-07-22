//BRUTE
//Nested loop for calculating sum of each pair
//TC: O(N^2), AS: O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                if((nums[i] + nums[j]) == target)
                {
                    return {i, j}
                }
            }
        }
        
        return {};
    }
};

//BETTER
//Sort then use Two Pointer
//TC: O(N * logN), SC : O(1) (if only values are to be returned) OR O(N) (if index is to be returned)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int n = nums.size();
        //create a vector of pairs to store value with its original index
        vector<pair<int, int>> numsWithIndex(n);
        
        for(int i = 0; i < n; i++)
        {
            numsWithIndex[i] = make_pair(nums[i], i);
        }
        //sort this vector of pairs (based on value)
        sort(numsWithIndex.begin(), numsWithIndex.end());
        
        int s = 0;
        int e = n - 1;
        
        //use two pointer approach
        while(s < e)
        {
            if(numsWithIndex[s].first + numsWithIndex[e].first == target)
            {
                return {numsWithIndex[s].second, numsWithIndex[e].second};
            }
            
            else if (numsWithIndex[s].first + numsWithIndex[e].first < target)
                s++;
            
            else
                e--;
        }
        
        return {};
    }
};

//OPTIMAL
//Use Hashtable
//TC: O(N), SC: O(N)
vector<int> twoSum(vector<int> &numbers, int target)
{
    //Key is the number and value is its index in the vector.
	unordered_map<int, int> hash;
	vector<int> result(2);
	
	for (int i = 0; i < numbers.size(); i++) {
		int numberToFind = target - numbers[i];

        //if numberToFind is found in map, return them
		if (hash.find(numberToFind) != hash.end()) {
			result.push_back(hash[numberToFind]);
			result.push_back(i);			
			return result;
		}

        //number was not found. Put it in the map.
		hash[numbers[i]] = i;
	}
	
	return result;
}