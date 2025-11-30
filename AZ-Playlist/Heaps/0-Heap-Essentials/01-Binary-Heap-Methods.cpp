int MinHeap::extractMin() {
    if (heap_size <= 0)
        return INT_MAX;              // or return -1 based on problem

    if (heap_size == 1) {            // only one element
        heap_size--;
        return harr[0];
    }

    int root = harr[0];              // store min element
    harr[0] = harr[heap_size - 1];   // move last element to root
    heap_size--;                     // reduce heap size
    MinHeapify(0);                   // fix heap

    return root;
}

// delete key at index i
void MinHeap::deleteKey(int i) {
    // best trick: decrease value to -∞, then extractMin()
    decreaseKey(i, INT_MIN);
    extractMin();
}

void MinHeap::insertKey(int k) {
    if (heap_size == capacity)
        return;  // heap full

    // insert at end
    int i = heap_size;
    harr[i] = k;
    heap_size++;

    // bubble up
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}
