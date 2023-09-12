//no. of distinct islands, can be stored as matrices (zero-based)
//all these matrices would be stored in set.
//since we don't know the size of the island, we cannot create a matrix beforehand
//instead, we'll store the zero-based indices of 1 while dfs, in a vector
//and insert this vector of (zero-based row, zero-based col)s in the set

 
#include <bits/stdc++.h>

void dfs(int i, int j, int rowLen, int colLen, vector<pair<int, int>>& v, vector<vector<bool>>& visited, int** arr, int n, int m)
{
    if(i < 0 || j < 0 || i >= n || j >= m || visited[i][j] == true || arr[i][j] == 0)
        return;
    
    v.push_back({i - rowLen, j - colLen});
    visited[i][j] = true;

    dfs(i - 1, j, rowLen, colLen, v, visited, arr, n, m);
    dfs(i, j - 1, rowLen, colLen, v, visited, arr, n, m);
    dfs(i + 1, j, rowLen, colLen, v, visited, arr, n, m);
    dfs(i, j + 1, rowLen, colLen, v, visited, arr, n, m);
}


int distinctIslands(int** arr, int n, int m)
{
    //Write your code here
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    set<vector<pair<int, int>>> hashSet;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!visited[i][j] && arr[i][j] == 1)
            {
                int rowLen = i;
                int colLen = j;
                vector<pair<int, int>> v;
                dfs(i, j, rowLen, colLen, v, visited, arr, n, m);
                hashSet.insert(v);
            }
        }
    }

    return hashSet.size();
}
