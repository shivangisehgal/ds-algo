//1. Brute
//2. STL find
//3. Similar LEETCODE (First Occ)
//4. KMP Algo : TODO

//Brute:

#include<bits/stdc++.h>
using namespace std;

vector<int> stringSearch(string big,string small){
    //store the occurrences in the result vector
    vector<int> result = {};
    
    int n1 = big.length();
    int n2 = small.length();
    
    int i = 0;
    
    while(i < n1)
    {
        if(big[i] == small[0])
        {
            int k = i;
            bool flag = false;
            
            for(int j = 0; j < n2; j++)
            {
                if( k == n1 || (big[k++] != small[j]))
                {
                    flag = true;
                    break;
                }
            }
            
            if(flag == false)
            {
                result.push_back(i);
                i = k - 1;
            }
            
        }
        
        i++;
        
    }
    
    return result;

}


//2. Find func
#include<bits/stdc++.h>
using namespace std;
 
vector<int> stringSearch(string big,string small){
    
    vector<int> result;
    int index = big.find(small);
  
    while(index != -1){
    	result.push_back(index);
    	index = big.find(small,index+1);
    }
    
    return result;
}

//3. LC
// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/submissions/

//4. KMP Algo
//TODO

