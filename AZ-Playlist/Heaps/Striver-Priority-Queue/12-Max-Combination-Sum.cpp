// BRUTE:
// Generate all N*N sums A[i] + B[j], sort, pick top K.
// TC: O(N^2 log N), SC: O(N^2)
//
// BETTER:
// Min-heap of size K; push all N*N sums, pop when size > K.
// TC: O(N^2 log K) — still too slow.
//
// OPTIMAL:
// Sort A and B.
// Largest sum = A[n-1] + B[n-1].
// Use max-heap storing (sum, i, j) starting from (n-1, n-1).
//
// From (i, j), next valid candidates are:
//   (i-1, j)  // decrease A index
//   (i, j-1)  // decrease B index
// These represent the "frontier" of next best sums.
// Use a set to avoid duplicate (i, j) pushes.
//
// Pop K times → gives top K sums without generating all pairs.
// TC: O(K log K), SC: O(K)

class Solution {
public:
    vector<int> kMaxSumCombination(vector<int>& A, vector<int>& B, int K) {
        int n = A.size();
        
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        priority_queue< vector<int> > maxHeap; 
        // stores {sum, i, j}

        set<pair<int,int>> used;

        // push max pair (n-1, n-1)
        maxHeap.push({A[n-1] + B[n-1], n-1, n-1});
        used.insert({n-1, n-1});

        vector<int> result;

        while (K-- > 0 && !maxHeap.empty()) {
            auto top = maxHeap.top();
            maxHeap.pop();

            int sum = top[0];
            int i   = top[1];
            int j   = top[2];

            result.push_back(sum);

            // next candidate 1: (i-1, j)
            if (i - 1 >= 0 && !used.count({i-1, j})) {
                maxHeap.push({A[i-1] + B[j], i-1, j});
                used.insert({i-1, j});
            }

            // next candidate 2: (i, j-1)
            if (j - 1 >= 0 && !used.count({i, j-1})) {
                maxHeap.push({A[i] + B[j-1], i, j-1});
                used.insert({i, j-1});
            }
        }

        return result;
    }
};
