// BRUTE:
// Generate all permutations and check if adjacent chars differ.
// TC: O(n!) — impossible.
//
// BETTER:
// Count freq; try greedy placing of most frequent char first, fill gaps.
// Hard to maintain correctness.
//
// OPTIMAL (Max-Heap):
// Count freq of each char.
// If any freq > (n+1)/2 → impossible.
//
// Use a max-heap (freq, char).
// Always pick top two most frequent different chars and append them.
// Decrease freq and push back if still > 0.
// This ensures no two adjacent chars are same.
// If one char remains at end, it must have freq == 1.
// TC: O(n log k), SC: O(k)
// k = distinct characters.

class Solution {
public:
    string reorganizeString(string s) {
        
        int n = s.length();
        
        priority_queue<pair<int, char>> maxHeap;
        unordered_map<char, int> map;
        
        for(auto ch : s)
        {
            map[ch]++;
            if(map[ch] > (n + 1) / 2)
                return "";
        }
        
        for(auto m : map)
        {
            int freq = m.second;
            char ch = m.first;
            maxHeap.push({freq, ch});
        }
        
        string ans = "";
        
        while(maxHeap.size() > 1)
        {
            auto p1 = maxHeap.top();
            char ch1 = p1.second;
            int freq1 = p1.first;
            
            maxHeap.pop();
            
            auto p2 = maxHeap.top();
            char ch2 = p2.second;
            int freq2 = p2.first;
            
            maxHeap.pop();
            
            ans += ch1;
            ans += ch2;
            
            if(freq1 > 1)
                maxHeap.push({freq1 - 1, ch1});
            
            if(freq2 > 1)
                maxHeap.push({freq2 - 1, ch2});
        }
        
        if(!maxHeap.empty())
        {
            auto p1 = maxHeap.top();
            char ch1 = p1.second;
            int freq1 = p1.first;
            
            if(freq1 == 1)
                ans += ch1;
            else
                return "";
        }
        
        return ans;
    }
};