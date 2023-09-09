// Print all the subsequnece

#include <bits/stdc++.h>
using namespace std;

// Time complexity : 2^N 
// Space complexity : N
void printSubSequence(vector<int> A,int index = 0, vector<int> v = {})
{
    if (index >= A.size()) 
    {
        for(int a : v) {cout << a << " ";}
        cout << endl;
        return;
    }
  
  //take
    v.push_back(A[index]) ;
    printSubSequence(A, index+1, v);
  
  //don't take
    v.pop_back();
    printSubSequence(A, index+1, v) ;
}
