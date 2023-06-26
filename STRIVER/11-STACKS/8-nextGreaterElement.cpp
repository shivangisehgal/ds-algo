//Brute,
//For each element, find the first greater element
//TC: O(N^2)
//SC: O(N)

//Optimal
//Start from the last (rightmost), we need to find first greater, so in case we have a small value, it can be first greater for elements lying on its left -> push it to stack
//However, if we have a bigger element, we’re sure elements in the stack smaller than it can now never be first greater elements to the elements lying on the left, hence pop them, and stop popping (and assign) when top element is the first greater. push this to stack.

//TC: O(N)  
//SC: O(N + N) // In Leetcode question, they’ve give a subset array and we have to return the next greater element of each element in the given subset, and the question has asked to solve this in a time complexity of O(N + n), hence, using hashMap to map. 

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int> s;
        unordered_map<int, int> hashMap;
        
        for(int i = nums2.size() - 1; i >= 0; i--)
        {
            int x = nums2[i];
            
            while(!s.empty() && x >= s.top())
                s.pop();
            
            if(s.empty())
                hashMap[nums2[i]] = -1;
            
            else
                hashMap[nums2[i]] = s.top();
            
            s.push(x);
        }
        
        for(int j = 0; j < nums1.size(); j++)
        {
            nums1[j] = hashMap[nums1[j]];
        }
        
        return nums1;
    }
};
