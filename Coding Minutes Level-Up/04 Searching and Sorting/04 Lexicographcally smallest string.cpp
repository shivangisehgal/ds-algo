//Q. Given an array of strings, find the lexcographically smallest contraction


//Same as Biggest Number String

bool compare(string a, string b)
{
    return (a+b < b+a);
}
 
string lexSmallest(string arr[], int n)
{
    sort(arr, arr + n, compare);
    
  string ans = "";
  
    for (int i = 0; i < n; i++)
        ans += arr[i];
 
    return ans;
}
