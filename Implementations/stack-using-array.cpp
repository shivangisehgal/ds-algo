// Stack class.
class Stack {
    vector<int> arr;
    int maxSize;
    int t;
public:
    
    Stack(int capacity) {
        // Write your code here.
        maxSize = capacity;
        arr.resize(capacity);
        t = -1;
    }

    void push(int num) {
        // Write your code here.
        if(t < maxSize - 1)
        {
            arr[++t] = num;
        }
    }

    int pop() {
        // Write your code here.
        if(t == -1)
            return -1;

        return arr[t--];
    }
    
    int top() {
        // Write your code here.

        if(t == -1)
            return -1;

        return arr[t];
    }
    
    int isEmpty() {
        // Write your code here.
        return t == -1;
    }
    
    int isFull() {
        // Write your code here.
        return t == (maxSize - 1);
    }
    
};
