//TC: O(1) per operation
//SC: O(N)

//if rear == size, queue is full, no matter whether array space is vancant or not.

#include <bits/stdc++.h> 
class Queue {

    int size;
    int* arr;
    int qfront;
    int rear;

public:
    Queue() {
        size = 10001;
        arr = new int[size];
        qfront = rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
       return (qfront == rear);
    }

    void enqueue(int data) {
        if(rear == size)
            cout << "Queue is Full.";
        
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        int ans;
        if(qfront == rear)
            return -1;
        else
        {
            ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qfront == rear)
            {
                qfront = 0;
                rear = 0;
            }
        }
        return ans;
    }

    int front() {
        if(qfront == rear)
            return -1;
        
        return arr[qfront];
    }
};
