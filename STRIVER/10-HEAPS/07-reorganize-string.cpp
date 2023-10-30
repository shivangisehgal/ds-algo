//APPROACH 1
//Max Heap
//store frequency of each character. if any character has frequency > [n/2] => cannot be arranged in that way
//Else, push {frequency and char} in maxHeap.
//At a time, take two from the string, add to answer, then store them back in max heap after decreasing frequency by 1
//If only one element left, if its frequency is > 1 => cannot be arranged
//                          else, add to answer

//TC: O(KlogK) => O(NlogN)
//SC: O(N)

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

//APPROACH 2
