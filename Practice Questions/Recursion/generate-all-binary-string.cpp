void rec(string s, int i, int last, int n, vector<string>& ans)
{
    if(i == n)
    {
        ans.push_back(s);
        return;
    }

    rec(s + '0', i + 1, 0, n, ans);

    if(last == 0)
        rec(s + '1', i + 1, 1, n, ans);
}


vector<string> generateString(int N) {
    // Write your code here.
    vector<string> ans;
    string s = "";
    
    rec(s, 0, 0, N, ans);

    return ans;
}
