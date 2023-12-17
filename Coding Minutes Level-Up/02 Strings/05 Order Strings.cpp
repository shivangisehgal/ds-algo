// https://www.hackerrank.com/contests/morgan-stanley-codeathon-2017/challenges/shell-sort-command/problem

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map> 

using namespace std;

bool customCompL(pair<string, string> a, pair<string, string> b)
{

    return a.first < b.first;
}

bool customCompN(pair<string, string> a, pair<string, string> b)
{
    int num1 = stoi(a.first);
    int num2 = stoi(b.first);

    return num1 < num2;
}

vector<pair<string, string>> mapStrings(vector<string>& strs, int col)
{
    int tokenCount = 0;

    vector<pair<string, string>> tokenArr;

    for (int i = 0; i < strs.size(); i++)
    {
        string s_i = strs[i];

        string s_i_temp = s_i;

        string num;

        // tokenize string
        stringstream ss(s_i_temp);

        // col_th token
        while (getline(ss, num, ' '))
        {
            tokenCount++;

            if (tokenCount == col)
            {
                //cout << num << " " << s_i << endl;
                
                tokenArr.push_back({num, s_i});
                break;
            }
        }

        tokenCount = 0;
    }

    return tokenArr;
}

int main()
{
    int n;
    cin >> n;

    vector<string> strs;
    string temp;
    cin.get();

    for (int i = 0; i < n; i++)
    {
        getline(cin, temp);
        strs.push_back(temp);
    }

    int col;
    cin >> col;

    string rev_str;
    cin >> rev_str;

    string comp_type;
    cin >> comp_type;
    

    vector<pair<string, string>> getCol = mapStrings(strs, col);

    if (comp_type == "lexicographic")
        sort(getCol.begin(), getCol.end(), customCompL);
    
    else if (comp_type == "numeric")
        sort(getCol.begin(), getCol.end(), customCompN);

    if (rev_str == "true")
        reverse(getCol.begin(), getCol.end());

    for (int i = 0; i < getCol.size(); i++)
    {
        cout << getCol[i].second << endl;
    }

    return 0;
}
