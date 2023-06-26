//TC: O(1) per operation
//SC: O(N)
#include <bits/stdc++.h> 
class TwoStack {
int top1;
int top2;
int *arr;
int size;
public:


    // Initialize TwoStack.
    TwoStack(int s) {
        // Write your code here.
        top1 = -1;
        top2 = s;
        size = s;
        arr = new int[size];
    }
    
    // Push in stack 1.
    void push1(int num) {
        // Write your code here.
        if(top1 + 1 >= top2)
            return;
            
        top1++;
        arr[top1] = num;
    }


    // Push in stack 2.
    void push2(int num) {
        // Write your code here.
        if(top2 - 1 <= top1)
            return;
        
        top2--;
        arr[top2] = num;
    }


    // Pop from stack 1 and return popped element.
    int pop1() {
        // Write your code here.
        if(top1 < 0)
            return -1;
        
        int x = arr[top1];
        top1--;
        return x;
    }


    // Pop from stack 2 and return popped element.
    int pop2() {
        // Write your code here.
        if(top2 >= size)
            return -1;
        int x = arr[top2];
        top2++;
        return x;
    }
};
