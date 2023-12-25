#include <bits/stdc++.h> 

int customBinarySearch(int low, int high, string& key, vector<string>& arr)
{
    while (low <= high) 
    {
        int mid = (low + high) / 2;
        int mid_left = mid - 1;
        int mid_right = mid + 1;

        if (arr[mid] == "") 
        {
            while (true) 
            {
                if (mid_left < low && mid_right > high) 
                  return -1;

                if (mid_right <= high && arr[mid_right] != "") 
                {
                    mid = mid_right;
                    break;
                } 
                
                if (mid_left >= low && arr[mid_left] != "") {
                    mid = mid_left;
                    break;
                }

                mid_left--;
                mid_right++;
            }
        }

        if (arr[mid] == key) 
          return mid;
        
        else if (arr[mid] > key) 
          high = mid - 1;
        
        else 
          low = mid + 1;
    }

    return -1;
}

int sparseSearch(vector<string>& arr, string& k) {


	int low = 0;
	int high = arr.size() - 1;

	return customBinarySearch(low, high, k, arr);

}
