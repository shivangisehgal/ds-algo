//Store all negative elements for first window of size k
//Your front element in queue, would be the first negative element for this window


//Now, for each element, remove the element in the queue, which do not lie in this window
//(since we are starting from k+1 th element, and check for each next element, so the number of elements in any queue occuring 
//before a window, can be max 1)
//Since we have to remove elements thta lie before the window of size k, we have to store indices in the q instead.
//Now, push this element in the queue if negative.
//Now, the front element in the queue will be our first negative element in the window, since, we have already gotten rid of the negative elements that 
//lie before this window and pushed the latest element of the window in case its zero.

//TC: O(N)
//SC: O(K) //queue will have the max size k.

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
    
    queue<long long> q;
    vector<long long> ans;
    
    for(long long i = 0; i < K; i++)
    {
        if(A[i] < 0)
            q.push(i);
    }
    
    if(q.empty())
        ans.push_back(0);
    
    else
        ans.push_back(A[q.front()]);
    
    
    for(long long i = K; i < N; i++)
    {

        if(!q.empty() && (i - q.front() >= K))
             q.pop();
        
        if(A[i] < 0)
            q.push(i);
        
        if(q.empty())
        ans.push_back(0);
    
        else
        ans.push_back(A[q.front()]);
    }
    
    return ans;
    
 }
