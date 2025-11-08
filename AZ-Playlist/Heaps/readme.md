
### Time Complexities for Some DS & Why Heap?

| Data Structure | Insert   | Search   | Find Min/Max | Delete Min/Max |
| -------------- | -------- | -------- | ------------ | -------------- |
| Unsorted Array | O(1)     | O(N)     | O(N)         | O(N)           |
| Sorted Array   | O(N)     | O(log N) | O(1)         | O(N)           |
| Linked List    | O(1)     | O(N)     | O(N)         | O(N)           |
| Min/Max Heap   | O(log N) | O(N)     | O(1)         | O(log N)       |

**Why Heap over arrays / linked lists?**

* Fast insert and delete of min/max → **O(log N)** using heapify.
* Arrays:

  * Unsorted: insert fast but delete/search slow.
  * Sorted: search fast but insert/delete slow.
* Heap = best trade-off for priority-based operations.
* Used in: Priority Queue, Dijkstra, Scheduling, Heap Sort, Top-K elements, Median stream, etc.

---

### Intro to Heap

 //// Complete Binary Tree: a. perfect BT, b. almost complete BT.

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


* Total nodes = N
* Leaf nodes index range     = floor(N/2)  to  N-1
* Internal nodes index range = 0 to floor(N/2) - 1


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

### Heapify Algorithm O(logN)

---

### Build Heap Algorithm O(N)

---

### Heap Methods Implementation (Max heap)
#### Extract Max (Pop) / Find + Delete Max
#### Insert Max
#### Increase a value
#### Decrease a value

---

### Heap Sort

---

## Heap Implementation (HEAP_PUSH, HEAP_POP, HEAP_TOP)
