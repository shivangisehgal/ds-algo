### 4 MAJOR CATEGORIES

1. Constant window size [Q. Max sum with k consecutive elements.] => Simple two pointer (**fixed sliding window**)
   
```cpp
int maxSum(vector<int>& arr, int k) {
    int sum = 0, ans = INT_MIN;
    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        if(i >= k) sum -= arr[i - k];
        if(i >= k - 1) ans = max(ans, sum);
    }
    return ans;
}
```

2. Longest Subarray where [Q. ... sum <= K] => **variable sliding window** (i.e. Expand + shrink)
       => for number/length **(count) => can be optimized to two pointer + fixed sliding window**

   ```cpp
   int longestSubarray(vector<int>& arr, int k) {
    int left = 0, sum = 0, ans = 0;
    for(int right = 0; right < arr.size(); right++) {
        sum += arr[right];
        while(sum > k) {
            sum -= arr[left];
            left++;
        }
        ans = max(ans, right - left + 1);
    }
    return ans;
}

also usage of maps in ques. like [Q.... at most K distinct elements] 
```cpp
int longestWithKDistinct(vector<int>& arr, int K) {
    unordered_map<int, int> freq;
    int left = 0, ans = 0;

    for(int right = 0; right < arr.size(); right++) {
        freq[arr[right]]++;

        while(freq.size() > K) {
            freq[arr[left]]--;
            if(freq[arr[left]] == 0) freq.erase(arr[left]);
            left++;
        }
        ans = max(ans, right - left + 1);
    }
    return ans;
}
```
3. Number of Subarrays where [Q. .. = sum]. => X: <= k - 1 | Y: <= k => Ans = Y - X

   ```cpp
   long long countAtMost(vector<int>& arr, int k) {
    int left = 0;
    long long cnt = 0, sum = 0;
    for(int right = 0; right < arr.size(); right++) {
        sum += arr[right];
        while(sum > k) {
            sum -= arr[left];
            left++;
        }
        cnt += (right - left + 1);
    }
    return cnt;
   }
``` cpp
long long countExactlyK(vector<int>& arr, int k) {
    return countAtMost(arr, k) - countAtMost(arr, k - 1);
}
```

4. Minimum Window [Q. .... subarray, subsequence] => **variable sliding window** (i.e. Expand + shrink)

```cpp
string minWindow(string s, string t) {
    unordered_map<char, int> need, have;
    for(char c : t) need[c]++;

    int formed = 0, required = need.size();
    int left = 0, minLen = INT_MAX, start = 0;

    for(int right = 0; right < s.size(); right++) {
        have[s[right]]++;
        if(need.count(s[right]) && have[s[right]] == need[s[right]]) formed++;

        while(formed == required) {
            if(right - left + 1 < minLen) {
                minLen = right - left + 1;
                start = left;
            }
            have[s[left]]--;
            if(need.count(s[left]) && have[s[left]] < need[s[left]]) formed--;
            left++;
        }
    }
    return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
}
```


### Resources & Important Links
https://leetcode.com/discuss/post/5622545/sliding-window-technique-patterns-by-cx1-i8ab/
https://leetcode.com/discuss/post/3722472/sliding-window-technique-a-comprehensive-ix2k/
