
AKA (How far or close the array is from being sorted)

//BRUTE
//Nested loop.
//TC: O(N^2)
//SC: O(1)

int getInversions(int * A, int n) {
  int count = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (A[i] > a[j]) {
        ++count;
      }
    }
  }
  return count;
}


//OPTIMAL

/*
Refer this for solution:
https://lh6.googleusercontent.com/DktuLgUJG45YBYqt4rRHCDQoFhktVT-_9dO7IjrRP-hsQZePEzktTPzq5Np6GUdu3wLyWsUSqfWwl7e_jRYCuiw83i8mq-0rUhrJ0SbUMNzPDaIwge2cpaVrbY41mB7YtiDCpZY3

  after slicing down and while merging, count the inversions. How? a[j] will start from the right half. 
  if (a[j] < a[i] then that means all the elements of left half are greater a[j], as in merge sort it is assumed left and right sub-halfs are sorted.
  
*/
  
//ENHANCED MERGE SORT
//TC: O(NlogN)
//SC: O(N)

#include<bits/stdc++.h>
using namespace std;

int merge(int arr[],int temp[],int left,int mid,int right)
{
    int inv_count=0;
    int i = left;
    int j = mid;
    int k = left;
    while((i <= mid-1) && (j <= right)){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i); // (mid - 1) - (i) + 1
        }
    }

    while(i <= mid - 1)
        temp[k++] = arr[i++];

    while(j <= right)
        temp[k++] = arr[j++];

    for(i = left ; i <= right ; i++)
        arr[i] = temp[i];
    
    return inv_count;
}

int merge_Sort(int arr[],int temp[],int left,int right)
{
    int mid,inv_count = 0;
    if(right > left)
    {
        mid = (left + right)/2;

        inv_count += merge_Sort(arr,temp,left,mid);
        inv_count += merge_Sort(arr,temp,mid+1,right);

        inv_count += merge(arr,temp,left,mid+1,right);
    }
    return inv_count;
}

int main()
{
    int arr[]={5,3,2,1,4};
    int n=5;
    int temp[n];
    int ans = merge_Sort(arr,temp,0,n-1);
    cout<<"The total inversions are "<<ans<<endl; 


    return 0;
}
