//Calculating minimum number of multiplications reqd. of start with any array element any number of time to reach end % mod.
//Maintain a queue, and a vector for min ops to reach (start * a[i]) => dist[0......mod]
//=> a bfs/ dijkstra's problem.

//TC: O(mod) hypothetically, way less though.
//SC: SC: O(mod)
int minimumOperations(int n, int start, int end, vector<int> &a)
{
    if (start == end)
        return 0;

    int mod = 1000;
    vector<int> dist(mod, INT_MAX);

    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int i = 0; i < n; i++)
        {
            int el = a[i];
            int neighbour = (el * node) % mod;

            if (dist[node] + 1 < dist[neighbour])
            {
                dist[neighbour] = 1 + dist[node];
                q.push(neighbour);
            }

            if (neighbour == end)
                return dist[neighbour];
        }
    }

    if (dist[end] == INT_MAX)
        return -1;

    return dist[end];
}
