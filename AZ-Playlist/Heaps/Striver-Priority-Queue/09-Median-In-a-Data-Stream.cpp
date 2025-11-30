// BRUTE:
// Store all numbers in an array.
// Sort on every addNum() OR sort on every findMedian().
// TC: addNum = O(1) or O(n), findMedian = O(n log n).

// OPTIMAL (2 Heaps):
// Maintain:
//   left_maxHeap  -> max-heap for smaller half
//   right_minHeap -> min-heap for larger half
//
// Always keep sizes balanced:
//   left.size() == right.size()      (even count)
//   left.size() == right.size() + 1  (odd count, median in left)
//
// Intuition:
// If new num <= left.top() → goes to left half (smaller numbers).
// Else → goes to right half (larger numbers).
//
// After insertion, heaps may become unbalanced.
// Fix by moving top element from the larger heap to the other heap.
// Ensures size diff never > 1.

// Left should always stay just 1 greater than right OR equal.
//  e.g, [3, 5, 4]
// left = {5,3,4}   → size = 3
// right = {}       → size = 0 XXXX
// so, when condition not true, pop n push to right. true for vice versa as well.

// Median rule:
//   If equal sizes → avg of both tops.
//   Else → top of left (since we keep left 1 element bigger).
//
// TC: addNum = O(log n), findMedian = O(1).


class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> right_maxHeap;
    priority_queue<int> left_maxHeap;
    MedianFinder() {}

    void addNum(int num) {
        if (left_maxHeap.empty() or left_maxHeap.top() > num) //condition to go to left half
            left_maxHeap.push(num);
        else
            right_maxHeap.push(num);

        if (left_maxHeap.size() > right_maxHeap.size() + 1) { 
            right_maxHeap.push(left_maxHeap.top());
            left_maxHeap.pop();
        } else if (right_maxHeap.size() > left_maxHeap.size()) {
            left_maxHeap.push(right_maxHeap.top());
            right_maxHeap.pop();
        }
    }

    double findMedian() {
        if (left_maxHeap.size() == right_maxHeap.size()) {
            double avg = (left_maxHeap.top() + right_maxHeap.top()) / 2.0;
            return avg;
        }
        else 
            return left_maxHeap.top();
    }
};
