//BINARY SEARCH
//TC: O(NlogN)
//SC: O(1)

//no of pages can minimum be = min element
//maximum be equal to total sum (in case of students m = 1)
//calculate mid, and find out in how many students can the books be distributes, such that
//sum of pages with each student is less than mid
//if number of students exceeds m, that means each student can have more pages => increase mid, i.e., shift to right
//else, it could be our our potential answer
class Solution 
{
    public:
    //Function to find minimum number of pages.
    int findPages(int pages[], int n, int m) 
    {
        if(m > n)
            return -1;
        
        int totalSum = 0;
        int minEl = INT_MAX;
        
        for(int i = 0; i < n; i++)
        {
            minEl = min(minEl, pages[i]);
            totalSum += pages[i];
        }
        
        int s = minEl;
        int e = totalSum;
        int mid;
        int ans = -1;
        while(s <= e)
        {
            mid = (s + e) / 2;
            
            int studCount = 1;
            int sum = 0;
            bool pagesExceedFlag = false;
            for(int i = 0; i < n; i++)
            {
                if(pages[i] > mid)
                {
                    pagesExceedFlag = true;
                    break;
                }
                
                sum += pages[i];
                
                if(sum > mid)
                {
                    sum = pages[i];
                    studCount++;
                }
                
                if(studCount > m)
                    break;
            }
            
            if(pagesExceedFlag || studCount > m)
                s = mid + 1;
                
            else //(studCount <= m)
            {
                ans = mid; //or min of mid(mid, ans)
                e = mid - 1;
            }
            
        }
        
        return ans;
    }
}
