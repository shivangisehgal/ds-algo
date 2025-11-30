//AKA DIVIDE ARRAY IN SETS OF K CONCECUTIVE NUMBERS

// APPROACH 1: Min-Heap
// Count frequencies, push (card, freq) into a min-heap to always pick the smallest card.
// For each group, pop 'groupSize' smallest cards and CHECK WHETHER THEY ARE CONSECUTIVE
// Decrement their frequencies and THEN PUSH BACK if still remaining.
// If at any point cards are not consecutive or heap has fewer than groupSize elements, return false.
// TC: O(N log N) due to heap operations.

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize)
            return false;

        unordered_map<int, int> freq;

        for(int& val : hand){
            freq[val]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for(auto p : freq){
            minHeap.push({p.first, p.second}); //NOT FREQ, INT => IT SHOULD BE INT, FREQ
        }

        while(!minHeap.empty()){
            if(minHeap.size() < groupSize)
                return false;
            
            vector<int> temp(groupSize);
            for(int i = 0; i < groupSize; i++){
                auto p = minHeap.top();
                minHeap.pop();

                if(i > 0 && p.first != temp[i - 1] + 1)
                    return false; //IMP: CONSECUTIVE

                temp[i] = p.first;
                freq[p.first]--;
            }

            for(int i = 0; i < groupSize; i++){
                if(freq[temp[i]] > 0){
                    minHeap.push({temp[i], freq[temp[i]]});
                }
            }
        }

        return true;
    }
};

// APPROACH 2: Ordered Map
// Use a sorted map<int,int> so the smallest card is always at map.begin().
// Repeatedly start a group from the smallest available card and check if the next (groupSize - 1) consecutive cards exist. 
// Decrement freq.
// If any required card is missing => return false.
// TC: O(N log N).

class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0)
            return false;

        map<int, int> freq; // ordered map

        for (int x : hand)
            freq[x]++;

        while (!freq.empty()) {

            int start = freq.begin()->first; // smallest available number

            for (int i = 0; i < groupSize; i++) {

                int card = start + i;

                if (freq.find(card) == freq.end())
                    return false;

                freq[card]--;

                if (freq[card] == 0)
                    freq.erase(card);
            }
        }

        return true;
    }
};