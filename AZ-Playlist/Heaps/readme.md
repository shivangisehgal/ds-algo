
### Time Complexities for Some DS & Why Heap?

| Data Structure | Insert   | Search   | Find Min/Max | Delete Min/Max |
| -------------- | -------- | -------- | ------------ | -------------- |
| Unsorted Array | O(1)     | O(N)     | O(N)         | O(N)           |
| Sorted Array   | O(N)     | O(log N) | O(1)         | O(N)           |
| Linked List    | O(1)     | O(N)     | O(N)         | O(N)           |
| Min/Max Heap   | O(log N) | O(N)     | O(1)         | O(log N)       |

**Why Heap over arrays / linked lists?**

> * **Fast insert and delete of min/max → **O(log N)** using heapify.**
* Arrays:

  * Unsorted: insert fast but delete/search slow.
  * Sorted: search fast but insert/delete slow.
* Heap = best trade-off for priority-based operations.
* Used in: Priority Queue, Dijkstra, Scheduling, Heap Sort, Top-K elements, Median stream, etc.

---

### Intro to Heap

> Complete Binary Tree: a. perfect BT (all levels completely filled), b. almost complete BT (all levels except possibly last and second last completely filled from L to R).

* Tree-based data structure
* **Complete Binary Tree**

  * **All levels completely filled, except possibly last**
  * **Last level filled left to right**
* Follows **heap property**

  * Max-Heap: parent >= children
  * Min-Heap: parent <= children
* Types:

  * Min-Heap
  * Max-Heap

#### Valid heap shape (complete):

```
         A
       /   \
      B     C
     / \   /
    D   E F
```

Reason: all levels filled, last level filled **left → right**.

#### Invalid (NOT a heap shape, not complete):

```
         A
       /   \
      B     C
         \
          D
```

Gap on left side → cannot be stored in array properly → not a heap.


A full (perfect) tree is a *special case* of complete tree.

---

### Representation of Heap

#### Why array?

* Heap is always a **complete binary tree**
* Complete ⇒ no gaps ⇒ can store using a simple array
* No pointers or node objects needed, unlike normal trees
* Constant-time parent/child access (i -> 2i, 2i + 1)

#### Why Heap is not stored in Linked List Shape

Bad shape (not complete):

```
 10
   \
    20
      \
       30
```

* Hard to compute children using index math
* Storage wastes space
* Heap operations no longer O(log N)

---

### Index Relations (0-based indexing)

```
parent(i)      = (i - 1) / 2
left child(i)  = 2 * i + 1
right child(i) = 2 * i + 2
```

### Same for 1-based indexing (just for reference)

```
parent(i)      = i / 2
left child(i)  = 2*i
right child(i) = 2*i + 1
```

---

### Example Max-Heap (Array + Tree)

Array (0-based):

```
Index:  0  1  2  3  4  5  6
Value: [1, 2, 3, 4, 5, 6, 7]
```

Tree form:

```
        1
      /   \
     2     3
    / \   / \
   4  5  6   7
```

---

### Height and Node Count

* Height `h` starts at **0** (root level)
* Max nodes at height `h` = `2^h`
* Max nodes in complete tree of height `h` = `(2^(h+1)) - 1`

| Height (h) | Max nodes at level | Max total nodes up to that level |
| ---------- | ------------------ | -------------------------------- |
| 0          | 1                  | 1                                |
| 1          | 2                  | 3                                |
| 2          | 4                  | 7                                |
| 3          | 8                  | 15                               |
| ...        | ...                | ...                              |

Height of heap with N nodes:

```
h = floor(log2(N))
```

---

### Leaf and Internal Node Index Ranges (0-based)

```
* Total nodes = N
* Leaf nodes index range     = floor(N/2)  to  N-1
* Internal nodes index range = 0 to floor(N/2) - 1
```

```
Index:   0   1   2   3   4   5   6
Value:  [50, 30, 20, 10, 5, 15, 2]
```

Tree form:

```
                (0) 50
               /        \
         (1) 30          (2) 20
         /     \         /      \
   (3) 10   (4) 5   (5) 15   (6) 2
```

Total nodes N = 7
floor(N/2) = floor(7/2) = 3

So:

```
Leaf index range     = 3 to 6   (nodes 10, 5, 15, 2)
Internal index range = 0 to 2   (nodes 50, 30, 20)
```

### Key Notes

* Heap always uses **log base 2** because it is a binary tree.
* Array representation works **only** because heap is always complete.

---

### Heapify Algorithm | TC: O(logN), SC: O(logN) {recursive space} | aka PERCOLATE DOWN

> Heapify Algorithm: Assuming that left subtree and right subtree are heaps, correctly position current node ans recursively heapify the child.

---

### Heap Implementation (Max heap)
#### Extract Max (Pop) / Find + Delete Max | TC: O(logN), SC: O(logN)
> swap (root, last leaf) -> percolate down (root) 
#### Insert Key | TC: O(logN), SC: O(1)
> insert at end, percolate up (i)
#### Get Max TC: O(1), SC: O(1)
> heap[0]
#### Increase a value | TC: O(logN), SC: O(1)
> heap[i] += val -> since increased and is max heap, so chances of going up: percolate up (i)
#### Decrease a value | TC: O(logN), SC: O(logN)
> heap[i] -= val -> since decreases and is max heap, so chances of going down: percolate down (i)

---

### Build Heap Algorithm | TC: O(N) [IMPORTANT: NOT O(NlogN)], SC: O(logN)

> We know that ```floor(N / 2) to N - 1``` indices should store leaf nodes. So assume that currently they are the leaves, so in order to build subtrees with these as leaves we need to start in reverse from ```last internal node``` index, and then keep ```heapifying```, this was automatically, subtrees -> then trees will form according to our heap property.

> start from last internal node to root ``` i : floor(N / 2) - 1 TO 0 ``` -> percolate down (i)
---

### Heap Sort | TC: O(N * logN)

> Heap Sort Alogrithm: Sort array elements with help of heap DS.

> From array -> build heap ```TC: O(N)``` -> keep extracting maximum for N - 1 indices ```TC: O(N * logN)``` => TC: O(N * logN)

---

### Quick Select Algorithm

---

# Priority Queue (C++) – Quick Notes

Default: max-heap

```cpp
priority_queue<int> pq;
```

Min-heap:

```cpp
priority_queue<int, vector<int>, greater<int>> minH;
```

Time complexities:

* push: O(log N)
* pop: O(log N)
* top: O(1)

Backed by a binary heap stored in an array.

---

## Custom Comparator Patterns in C++

### 1. Struct comparator (most common)

```cpp
struct Comp {
    bool operator()(int a, int b) const {
        return a > b;  // min-heap
    }
};

priority_queue<int, vector<int>, Comp> pq;
```

### 2. Comparator for objects

```cpp
struct Node {
    int val;
    int freq;
};

struct ByFreq {
    bool operator()(const Node &a, const Node &b) const {
        return a.freq > b.freq;  // min-heap on freq
    }
};

priority_queue<Node, vector<Node>, ByFreq> pq;
```

### 3. Comparator for max-heap on objects

```cpp
struct ByValueMax {
    bool operator()(const Node &a, const Node &b) const {
        return a.val < b.val;  // max-heap on val
    }
};
```

### 4. Lambda comparator

```cpp
auto comp = [](int a, int b) { return a > b; };
priority_queue<int, vector<int>, decltype(comp)> pq(comp);
```

### 5. Multiple-field comparator

```cpp
struct Multi {
    bool operator()(const Node &a, const Node &b) const {
        if (a.freq == b.freq)
            return a.val > b.val;  // tie-breaker
        return a.freq < b.freq;     // primary key
    }
};
```

---

# Priority Queue vs multiset vs set (C++)

| Feature                   | priority_queue           | multiset                                | set                       |
| ------------------------- | ------------------------ | --------------------------------------- | ------------------------- |
| Underlying DS             | heap                     | balanced BST (red-black tree)           | balanced BST              |
| Sorted order              | no (only top guaranteed) | yes (full sorted)                       | yes (unique keys, sorted) |
| Iteration in sorted order | no                       | yes                                     | yes                       |
| Duplicate elements        | yes                      | yes                                     | no                        |
| Custom comparator         | yes                      | yes                                     | yes                       |
| Access min/max            | O(1)                     | O(log N)                                | O(log N)                  |
| Insert                    | O(log N)                 | O(log N)                                | O(log N)                  |
| Remove                    | O(log N)                 | O(log N)                                | O(log N)                  |
| Best for                  | Top-K, streaming min/max | maintaining sorted data with duplicates | sorted unique set         |

Notes:

* Use `priority_queue` for repeated top() and push/pop operations.
* Use `multiset` when you need sorted iteration or erase arbitrary elements.
* `priority_queue` cannot erase arbitrary elements efficiently (no iterator access).

---

# Priority Queue (Java) – Quick Notes

Java `PriorityQueue` is a min-heap by default.

```java
PriorityQueue<Integer> pq = new PriorityQueue<>();
```

Max-heap:

```java
PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
```

Time complexities:
add: O(log N)
poll: O(log N)
peek: O(1)

Not thread-safe. Not sorted when iterating.

---

## Custom Comparators in Java

### 1. Lambda comparator

```java
PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> a - b);  // min-heap
```

### 2. Max-heap

```java
PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
```

### 3. Comparator for objects

```java
class Node {
    int val;
    int freq;
}

PriorityQueue<Node> pq =
    new PriorityQueue<>((a, b) -> a.freq - b.freq);
```

### 4. Multi-level comparator

```java
PriorityQueue<Node> pq = new PriorityQueue<>((a, b) -> {
    if (a.freq == b.freq)
        return a.val - b.val;
    return a.freq - b.freq;
});
```

---

# PQ vs TreeSet / TreeMap (Java)

| Feature          | PriorityQueue               | TreeSet / TreeMap                       |
| ---------------- | --------------------------- | --------------------------------------- |
| Underlying DS    | heap                        | red-black tree                          |
| Sorted iteration | no                          | yes                                     |
| Access min/max   | O(1)                        | O(log N)                                |
| Arbitrary remove | no efficient way            | O(log N)                                |
| Duplicate keys   | allowed                     | TreeSet: no, TreeMap: no duplicate keys |
| Best for         | repeated min/max extraction | maintaining sorted data                 |

Notes:

* Use PQ for top-K, Dijkstra, scheduling.
* Use TreeSet/TreeMap when full order matters and you need to traverse in sorted order.
