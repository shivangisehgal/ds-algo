//Q.1 print all subsequences whose sum = k

void subSequenceSum(vector<int> A, int k, vector<int> &v, int i = 0, int sum = 0)
{
    if (i >= A.size())
    {
        if (sum == k)
        {
            for (int a : v)
            {
                cout << a << " ";
            }
            cout << endl;
        }
        return ;
    }
  
    v.push_back(A[i]);
    subSequenceSum(A, k, v, i + 1, sum + A[i]);
                                                                 
    v.pop_back();
    subSequenceSum(A, k, v, i + 1, sum);
                                        
}

//Q. 2 print ONLY/ ANY ONE subseq whose sum is k
//general procedure. base case satis -> return true. else return false
bool subSequenceSum(vector<int> A, int k, vector<int> &v, int i = 0, int sum = 0)
{
    if (i >= A.size())
    {
        //conition satisfied
      
      if (sum == k)
        {
            for (int a : v)
            {
                cout << a << " ";
            }
            cout << endl;
            return true;
        }
      
        return false;
    }
  
    v.push_back(A[i]);
    if(subSequenceSum(A, k, v, i + 1, sum + A[i]) == true)
      return true;
  
    //else if                                                      
    v.pop_back();
    if(subSequenceSum(A, k, v, i + 1, sum) == true)
      return true;
  
    return false;
                                        
}


//counting problems
// f()
// {
//     base case
//         return 1 -> condn. satisfied
//         return 0 -> not satisfied
//      l = f()
//      r = f()
//      return l + r
// }


//Q.3 count subsequences with sum k
int subSequenceSum(vector<int> A, int k, vector<int> &v, int i = 0, int sum = 0)
{
    if (i >= A.size())
    {
        //conition satisfied
      if (sum == k)
          return 1;
      else
          return 0;
    }
  
    v.push_back(A[i]);
    int l = subSequenceSum(A, k, v, i + 1, sum + A[i]) ;                                                  
    v.pop_back();
    int r = subSequenceSum(A, k, v, i + 1, sum);
    
    return l + r;
                                        
}
