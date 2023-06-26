// TC: O(N / 2)
// SC: O(N / 2), considering stack space

#include <bits/stdc++.h> 
void helper(stack<int>&s, int count, int N)
{
   //base condition
   if(count == N / 2)
   {
      s.pop(); //pop (first encountered) middle element.
      //task done, return
      return;
   }


   int topEl = s.top();
   s.pop();


   helper(s, count + 1, N);


   s.push(topEl);
}


void deleteMiddle(stack<int>&inputStack, int N){
   
   //if size is even, we have to delete first middle OBSERVED in stack, so we have to go shallower.
   //if size is even -> N is odd.
   //if size is odd, N / 2 would be equal to size / 2
   //if size is even, N / 2 would be 1 less than size / 2, which we want.
   
   helper(inputStack, 0, N);
}


