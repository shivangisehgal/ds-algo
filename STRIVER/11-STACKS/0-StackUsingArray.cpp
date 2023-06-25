#include<bits/stdc++.h>
using namespace std;

class Stack{
    
    int size;
    int *arr;
    int top; //index of top
    
    public:
    Stack(){
        top = -1;
        size = 1000;
        arr = new int[size];
    }
    
    Stack(int size)
    {
        top = -1;
        this->size = size;
        arr = new int[size];
    }
    
    void push(int x){
        if(top < size - 1)
        {
            top++;
            arr[top] = x;
        }
        else
        cout << "Stack Overflow" << endl;
    }
    
    void pop(){
        if(top >= 0)
        {
            top--;
        }
        
        else
        cout << "Stack is empty" << endl;
    }
    
    int Top(){
        if(top >= 0)
            return arr[top];
        else
        {
            cout << "Stack is empty" << endl;
        }
    }
    
    bool isEmpty(){
        return (top == -1);
    }
    
    int Size(){
        return (top + 1);
    }
};

int main() {

  Stack s;
  s.push(4);
  s.push(3);
  s.push(2);
  s.push(1);
  s.pop();
  
  while(!s.isEmpty()){
      cout << "Top: " << s.Top() << " | Size: " << s.Size() << endl;
      s.pop();
  }
  return 0;
}
