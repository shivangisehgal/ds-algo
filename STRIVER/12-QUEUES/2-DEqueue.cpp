//TC: O(1) per operation
//SC: O(N) 

class Deque
{
    int size;
    int* arr;
    int front;
    int rear;

public:
    // Initialize your data structure.
    Deque(int n)
    {
        // Write your code here.
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        // Write your code here.
        if(front == (rear + 1) % size)
            return false;
        
        if(front == -1)
        {
            front = 0;
            rear = 0;
        }
        
        else if(front == 0)
            front = size - 1;
        else
            front = (front - 1) % size;
        
        arr[front] = x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        // Write your code here.
        if(front == (rear + 1) % size)
            return false;
        
        if(front == -1)
        {
            front = 0;
            rear = 0;
        }

        else
            rear = (rear + 1) % size;
        
        arr[rear] = x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if(front == -1)
            return -1;
        
        int top = arr[front];
        arr[front] = -1;

        if(front == rear) //it was only one element in the queue.
        {
            front = -1;
            rear = -1;
        }

        else
            front = (front + 1) % size;
        
        return top;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        // Write your code here.
        if(front == -1)
            return -1;

        int top = arr[rear];
        arr[rear] = -1;

        if(front == rear)
        {
            front = -1;
            rear = -1;
        }

        else
            rear = (rear - 1) % size;
        
        return top;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        // Write your code here.
        if(front == -1)
            return -1;
        
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        // Write your code here.
        if(front == -1)
            return -1;
        
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        // Write your code here.
        return (front == -1);
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        return (front == (rear + 1) % size);
    }
};
