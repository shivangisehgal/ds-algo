//BRUTE
//SORT (IF NOT SORTED) AND USE TEMPORARY ARRAY
//TC: O(NlogN)
//SC: O(N)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp(m + n);
        
        int i = 0, j = 0, k = 0;
        while(i < m and j < n)
        {
            if(nums1[i] <= nums2[j])
            {
                temp[k++] = nums1[i];
                i++;
            }
            
            else
            {
                temp[k++] = nums2[j];
                j++;
            }
        }
        
        while(i < m)
        {
            temp[k++] = nums1[i];
            i++; 
        }
        
        while(j < n)
        {
                temp[k++] = nums2[j];
                j++;
        }
        
        nums1 = temp;
    }
};


//BETTER (IF ASKED FOR CONSTANT SPACE)
//SWAPPING
/*
    This approach utilzes the fact that both arrays are sorted.
    swap with the first element of second array in case its smaller than the encountered element of first array,
    sort the second array (by insertion of the first element at correct place)
    the remaining second array would be appended.
*/
//TC: O(M*N)
//SC: O(1)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int i = 0;
        
        if(!nums2.empty())
        {
            while(i < m)
            {
                if(nums1[i] > nums2[0])
                {
                    swap(nums1[i], nums2[0]);

                    //sort nums2

                    int current = nums2[0];
                    int prev = 1;
                    while(prev < n and current > nums2[prev])
                    {
                         nums2[prev - 1] = nums2[prev];
                         prev++;
                    }
                    nums2[prev - 1] = current;
                }

                i++;
            }

            for(i = 0; i < n; i++)
            {
                nums1[i + m] = nums2[i];
            }
        }
    }
};

//OPTIMAL
//GAP METHOD
/*
    create a gap = ceil((m + n) /2)
    compare elements spaced by 'gap'
    after one entire iteration, reduce the gap by half
    keep doing, until the gap become 0.
*/
//TC: O( (M + N) * (log (M + N)) )
//SC: O(1)

class Solution {
public:
    
    int nextGap(int gap)
    {
        if(gap <= 1)
            return 0;
        //     if(gap & 1)
        //     return (gap / 2) + 1;
        // else
            return (gap / 2) + (gap % 2);
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        for(int i = 0; i < n; i++)
        {
            nums1[i + m] = nums2[i];
        }
        
        int gap = m + n;
        
        for(gap = nextGap(gap); gap > 0; gap = nextGap(gap))
        {
            for(int i = 0; i + gap < m + n; i++)
            {
                if(nums1[i] > nums1[i + gap])
                {
                    swap(nums1[i], nums1[i + gap]);
                }
            }
        }
    }
};

