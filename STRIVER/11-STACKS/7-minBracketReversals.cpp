//first, clear all the valid expression from the stack, now,
// s contains invalid expression
  // can be:
  // 1. {{{....
  // 2. }}}}.....
  // 3. }}{{{{ , }}}}{{ [both even]
  // 4. }}}}}{ , }{{{ [both odd]
  // mathematically, number of reversals will be equal to ((open + 1) / 2  + (close + 1) / 2)


// TC: O(N)
// SC; O(N)

#include <bits/stdc++.h> 
int findMinimumCost(string str) {


  if(str.length() % 2 != 0)
    return -1;
    
  stack<char> s;
  
  for (auto ch : str) 
  {
    if (ch == '}')
    {
      if(!s.empty() && s.top() == '{')
        s.pop();
      
      else
        s.push(ch);
      
    }


    else
        s.push(ch);
  }
  
  int open = 0;
  int close = 0;
  // s contains invalid expression
  // can be:
  // 1. {{{....
  // 2. }}}}.....
  // 3. }}{{{{ , }}}}{{ [both even]
  // 4. }}}}}{ , }{{{ [both odd]
  // mathematically, number of reversals will be equal to ((open + 1) / 2  + (close + 1) / 2)
  
  while(!s.empty())
  {
    char top = s.top();
    
    if(top == '{')
      open++;
      
    else
      close++;
      
    s.pop();
  }


  if(open == 0)
    return close / 2;
  
  if(close == 0)
    return open / 2;
  
  return ((open + 1) / 2  + (close + 1) / 2);
}
