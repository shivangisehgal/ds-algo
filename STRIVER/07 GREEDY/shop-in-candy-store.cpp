//TC: O(NlogN)
//SC: O(1)

vector<int> candyStore(int candyPrice[], int N, int k)
    {
       
       sort(candyPrice, candyPrice + N);
       
       if(k >= N - 1)
        return {candyPrice[0], candyPrice[N - 1]};
        
       int i = 0;
       int j = N - 1;
       
       int minPrice = 0;
       int maxPrice = 0;
       
       while(i <= j)
       {
           minPrice += candyPrice[i];
           j = j - k;
           i++;
       }
       
       i = 0;
       j = N - 1;
       
       while(i <= j)
       {
           maxPrice += candyPrice[j];
           i = i + k;
           j--;
       }
       
       return {minPrice, maxPrice};
    }
