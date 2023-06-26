#include <bits/stdc++.h> 
class CircularQueue{

    int size;
    int* arr;
    int front;
    int rear;

    public:

    CircularQueue(int n){
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        if(front == ((rear + 1) % size))
            return false;
        else if(front == -1) //first element
        {
            front = 0;
            rear = 0;
        }
        
        else
        {
            rear = (rear + 1) % size;
        }
        arr[rear] = value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){

        if(front == -1)
            return -1;

        int top = arr[front];
        arr[front] = -1;

        if(front == rear)
        {
            front = -1;
            rear = -1;
        }

        else
        {
            front = (front + 1) % size;
        }

        return top;
    }
};
