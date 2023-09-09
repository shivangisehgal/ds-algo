//BRUTE
//TC: O(M*N * LOG(M * N))
//SC: O(M*N) 

int Solution::findMedian(vector<vector<int> > &A) {
    vector<int> v;
    int row = A.size();
    int col = A[0].size();
    for(int i = 0; i < (row * col); i++)
    {
        v.push_back(A[i / col][i % col]);
    }
    
    sort(v.begin(), v.end());
    
    return v[((row * col) - 1) / 2];
}


your search space would be from min to max.
find mid, and get the no. of elements <= mid using upper_bound() (element that is just greater than this element) or binary search.
