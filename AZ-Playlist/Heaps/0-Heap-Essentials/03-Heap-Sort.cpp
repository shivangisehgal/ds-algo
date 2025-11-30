

class Solution {
    vector<int> heap;
    int n;
    
    int parent(int ind){
        return (ind - 1) / 2;
    } 
    int left(int ind){
        return 2 * ind + 1;
    }
    int right(int ind){
        return 2 * ind + 2;
    }
    
    void heapify(int i){
        
        if(i >= n || heap.size() == 1)
            return;
        
        int leftchild = left(i);
        int rightchild = right(i);
        
        int minVal = heap[i];
        int minInd = i;
        
        if(leftchild < n && heap[leftchild] < minVal){
            minVal = heap[leftchild];
            minInd = leftchild;
        }
        
         if(rightchild < n && heap[rightchild] < minVal){
            minVal = heap[rightchild];
            minInd = rightchild;
        }
        
        if(minInd != i){
            swap(heap[minInd], heap[i]);
            heapify(minInd);
        }
    
    }
    
    int extractMin(){
        if(heap.size() == 0)
            return -1;
            
        int minVal = heap[0];
        int lastInd = heap.size() - 1;
        
        swap(heap[0], heap[lastInd]);
        heap.pop_back();
        n--;
        
        heapify(0);
        
        return minVal;
    }
  public:
    // Function to sort an array using Heap Sort.
    void heapSort(vector<int>& arr) {
        // code here
        //1. build heap array
        //2. extract max.
        
        n = arr.size();
        heap = arr;
        
        //1. BUILD HEAP
        //only heapify internal nodes
        
        for(int i = n / 2 - 1; i >= 0; i--){
            heapify(i);
        } 
        
        // for(int i = 0; i < n; i++)
        //     cout << heap[i] << " ";
        //now that i have heap.
        //extrcct min for furst n - 1 elements.
        
        int k = 0;
        int N = n;
        for(int i = 0; i < N - 1; i++){
            int val = extractMin();
            // cout << val << " ";
            arr[k++] = val;
        }
          
            
        
        arr[N - 1] = heap[0];
        

            
            
        
    }
};