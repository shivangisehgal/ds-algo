void binSort(int arr[], int n)
    {
        int start = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(arr[i] == 0)
            {
                arr[start] = 0;
                start++;
            }
        }
        
        while(start < n)
        {
            arr[start] = 1;
            start++;
        }
    }


void binSort(int arr[], int n)
    {
        int left = 0;
        int right = n - 1;
        
        while(left < right)
        {
            if(arr[left] == 1)
            {
                swap(arr[left], arr[right]);
                right--;
            }
            
            else
                left++;
        }
    }
