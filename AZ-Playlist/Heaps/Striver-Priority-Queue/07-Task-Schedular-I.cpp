// BETTER: PQ + Greedy

// We always want to execute the task with the highest remaining frequency first,
// while ensuring that the same task is separated by at least `n` intervals.
// So we use a maxHeap to always pick the most frequent tasks.
//
// In every cycle (or bucket) of size (n + 1):
// - We pick max till (n + 1) most frequent available tasks.
// - Reduce their frequency and store them temporarily.
// - AND THEN push the remaining frequencies into the heap.
//
// If fewer than (n + 1) tasks were picked AND heap is not empty,
// we must fill the rest of the cycle with idle intervals.
//
// TC: O(N log 26) ≈ O(N) since heap size ≤ 26
// SC: O(1) (freq array + heap of max size 26)

// class Solution {
// public:
//     int leastInterval(vector<char>& tasks, int n) {
//         vector<int> freq(26, 0);

//         for(char& ch : tasks){
//             freq[ch - 'A']++;
//         }

//         priority_queue<pair<int, int>> maxHeap;

//         for(int i = 0; i < 26; i++)
//             if(freq[i] > 0)
//                 maxHeap.push({freq[i], i});
        
//         int tasksCount = 0;
        
//         while(!maxHeap.empty()){
            
//             int sz = maxHeap.size();
//             vector<int> temp(n + 1); //max size of temp can be (n + 1)
//             int taken = 0;

//             for(int i = 0; i <= n && i < sz; i++){

//                 //all these elements will go in my current bucket
//                 pair<int, int> t = maxHeap.top();
//                 maxHeap.pop();

//                 temp[i] = t.second;
//                 freq[t.second]--;

//                 tasksCount++;
//                 taken++;
//             }

//             for(int i = 0; i <= n && i < sz; i++){
//                 if(freq[temp[i]] > 0){
//                     maxHeap.push({freq[temp[i]], temp[i]});
//                 }
//             }

//             if(maxHeap.empty()) //all are processed, no task is remaining
//                 return tasksCount;
            
//             else //that means bucket will have places of idleness
//                 tasksCount += (n + 1 - taken);
//         }

//         return tasksCount;
//     }
// };

// OPTIMAL: Formula based Greedy
// Let maxFreq = highest frequency of a task.
// A _ _ A _ _ A
// We will have (maxFreq - 1) FULL buckets + 1 last bucket (for maxChar).
// Each full bucket must have min. size (n + 1): [task, idle, idle, ..., idle].
// So initial empty slots = (maxFreq - 1) * n.

// However, if multiple tasks have the same highest frequency, we will place ALL of
// them in the final bucket. 
// Let countMax = number of tasks having freq == maxFreq.

// So the constructed schedule length becomes:
//      (maxFreq - 1) * (n + 1) + countMax

// Now, IMPORTANT
// This was for, If countMax <= (n + 1):
//      Buckets define the shape -> there may be idle time.
//
// If countMax > (n + 1):
//      There are TOO MANY max-frequency tasks to fit per bucket.
//      They naturally fill all slots WITHOUT idle time (e.g., A B C A B C ...).
//      In such cases, total time simply equals tasks.size().
//
// Final answer must never be less than the total number of tasks:
//      ans = max(tasks.size(), (maxFreq - 1)*(n + 1) + countMax)

// TC: O(26 log 26) → O(1) since task types ≤ 26.
// SC: O(1)

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char t : tasks) freq[t - 'A']++;

        sort(freq.begin(), freq.end());

        int maxFreq = freq[25];  // highest frequency
        int countMax = 1;

        // count how many tasks have the same max frequency
        for (int i = 24; i >= 0; i--) {
            if (freq[i] != maxFreq) break;
            countMax++;
        }

        // formula:
        // (maxFreq - 1) * (n + 1) + countMax
        int constructedLength = (maxFreq - 1) * (n + 1) + countMax;

        // final answer must be at least tasks.size()
        return max((int)tasks.size(), constructedLength);
    }
};
