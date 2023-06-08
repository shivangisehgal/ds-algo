//Heap is a Complete binary tree: each level should be completely filled except the last one where the filling is done from L to R.

//Max heap: parent >= children. 
//Min heap: parent <= children,

//Problem in Binary Tree representation: O(N) is required to find out where node is inserted and then O(logN) time for insertion => O(N)
//In arrays, we can do it in O(1) time
//Parent: i -> left child: 2i, right child: 2i + 1 | linearly (level-order) filled in array | child: i -> parent: i / 2

//Insertion: compare with each parent. TC: O(height) => O(logN) for CBT.
//Pop: Remove minimum element. Swap min element with last node/element. delete last element. sort/place the first element in its correct position O(logN)
//Heapify: sort/place the element in its correct position.
//top: return min element
//empty

//MIN HEAP: MINIMUM ELEMENT IS THE ROOT NODE

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class minHeap
{
    vector<int> v;
    
    public:
    
    void heapify(int i) //place ith node element at the right position
    {
        int left = 2 * i;
        int right = 2 * i + 1;
        
        int minIdx = i;
        
        if(left < v.size() and v[left] < v[i])
            minIdx = left;
        
        if(right < v.size() and v[right] < v[minIdx])
            minIdx = right;
            
        if(minIdx != i)
        {
			swap(v[i], v[minIdx]);
			
			heapify(minIdx);
		}
    }
    
    minHeap(int default_size = 10)
    {
        v.reserve(default_size + 1);
        v.push_back(-1); //or INT_MAX/INT_MIN
    }
    
    void push(int d)
    {
        v.push_back(d);
        int i = v.size() - 1;
        int child = i;
        int parent = i / 2;
        
        while(parent > 0 and v[child] < v[parent])
        {
            swap(v[child], v[parent]);
            child = parent;
            parent = parent / 2;
        }
    }
    
    int top() //return minimum element
    {
        return v[1]; 
    }
    
    void pop() //remove minimum element
    {
        swap(v[1], v[v.size() - 1]);
        v.pop_back();
        heapify(1);
    }
    
    bool empty()
    {
        return v.size() == 1;
    }
};

int main(){

	int marks[] = {90,80,12,13,15,56,94};

	minHeap h;

	for(int x:marks){
		h.push(x); //logn
	}

	while(!h.empty()){
		cout<< h.top() <<endl;
		h.pop(); //logn
	}

	return 0;
}



//MAXHEAP

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class maxHeap
{
    vector<int> v;
    
public:
    void heapify(int i) //place ith node element at the right position
    {
        int left = 2 * i;
        int right = 2 * i + 1;
        
        int maxIdx = i;
        
        if (left < v.size() && v[left] > v[maxIdx])
            maxIdx = left;
        
        if (right < v.size() && v[right] > v[maxIdx])
            maxIdx = right;
            
        if (maxIdx != i)
        {
            swap(v[i], v[maxIdx]);
            heapify(maxIdx);
        }
    }
    
    maxHeap(int default_size = 100)
    {
        v.reserve(default_size + 1);
        v.push_back(-1); //or INT_MAX/INT_MIN
    }
    
    void push(int d)
    {
        v.push_back(d);
        int i = v.size() - 1;
        int child = i;
        int parent = i / 2;
        
        while (child > 1 && v[child] > v[parent])
        {
            swap(v[child], v[parent]);
            child = parent;
            parent = parent / 2;
        }
    }
    
    int top() //return maximum element
    {
        return v[1]; 
    }
    
    void pop() //remove maximum element
    {
        swap(v[1], v[v.size() - 1]);
        v.pop_back();
        heapify(1);
    }
    
    bool empty()
    {
        return v.size() == 1;
    }
};

int main() {
    int marks[] = {12, 80, 90, 15, 56, 10};

    maxHeap h;

    for (int x : marks) {
        h.push(x);
    }

    while (!h.empty()) {
        cout << h.top() << endl;
        h.pop();
    }

    return 0;
}

