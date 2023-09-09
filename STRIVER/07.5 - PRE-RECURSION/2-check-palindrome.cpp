//Check if a string is a palindrome
#include <bits/stdc++.h> 
bool helper(string s, int i = 0)
{
    if(i >= s.length() / 2)
        return true;
    
    if(s[i] != s[s.length() - 1 - i])
        return false;
     
    return helper(s, i + 1);
}
bool checkPalindrome(string s)
{
    return helper(s, 0);
}

//its considering case-sensitive
