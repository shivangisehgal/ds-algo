//Reverse a string

//Using 2 variables
void helper(string &s, int low, int high)
{
    if(low >= high)
        return;
    
    swap(s[low], s[high]);
    helper(s, low + 1, high - 1);
}
string reverseWord(string str){
    
    helper(str, 0, str.length() - 1);
    return str;
}

//Using 1 variable
void helper(string &s, int i)
{
    if(i >= (s.length() / 2))
        return;
        
    swap(s[i], s[s.length() - 1 - i]);
    helper(s, i + 1);
}
string reverseWord(string str){
    
    helper(str, 0);
    return str;
}
