//problem is, we have to do in-place
//hence, keep a track of arr[i + 1] using a variable.
//now you will have a suffix-max variable for greatest to the right, and a lastEl variable which will be used for finding max for its left elements.

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        
        int n = arr.size();
        
        int lastEl = arr[n - 1];
        
        //arr is now suffix
        arr[n - 1] = -1;
        
        for(int i = n - 2; i >= 0; i--)
        {
            int maxi = max(lastEl, arr[i + 1]);
            lastEl = arr[i];
            arr[i] = maxi;
        }
        
        return arr;
    }
};
