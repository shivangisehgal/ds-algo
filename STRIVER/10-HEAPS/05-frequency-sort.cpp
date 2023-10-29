//Sort chars by frequency
//BRUTE - bucket sort

class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char, int> map;
        
        for(auto ch : s)
            map[ch]++;
        
        int n = s.length();
        
        vector<vector<char>> bucket(n + 1);
        
        
        for(auto m : map)
        {
            int freq = m.second;
            char ch = m.first; 
            bucket[freq].push_back(ch);
        }
        
        string ans = "";
        
        for(int freq = n; freq >= 0; freq--)
        {
            vector<char> chars = bucket[freq];
            
            for(int i = 0; i < chars.size(); i++)
            {
                char ch = chars[i];
                string l = "";
                for(int j = 0; j < freq; j++)
                {
                    l += ch;
                }
                ans += l;
            }
        }
        
        return ans;
    }
};

//OPTIMAL?
//PRIORITY QUEUE
//TC: O(NlogN)
//SC: O(N)
class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char, int> map;
        
        for(auto ch : s)
            map[ch]++;
        
        int n = s.length();
        
        priority_queue<pair<int, char>> maxHeap;
        
        for(auto m : map)
        {
            int freq = m.second;
            char ch = m.first; 
            maxHeap.push({freq, ch});
        }
        
        string ans = "";
        
        while(!maxHeap.empty())
        {
            auto p = maxHeap.top();
            int freq = p.first;
            char ch = p.second;
            
            for(int f = 0; f < freq; f++)
                ans += ch;
            
            maxHeap.pop();
        }
        
        return ans;
    }
};
