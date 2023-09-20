//Linear ordering of all nodes in a DAG, such that if, u->v, then u comes first.
//Intuition: we want all children of a parent vertex to be printed first then the parent, 
//hence we can call for dfs of children, push in stack when we get a leaf node, backtrack, 
//and after this doing for all children, we can now push this parent.
//Thus, if we use a LIFO structure where we push chidren first and then their parent, popping out we get a sequence where parent comes first.
//Hence, Topo.

//Note: we will need universal stack. and why individual stacks for a dfs calls from main won't work?
//If you are thinking, why don't we put into list when you start dfs, this way we don't have to use stack or reverse order. 
//  Consider a case 6->0->1->2->3->4->5, we start from 0 and put into list, 
//    so ordering comes out to be, 0,1,2,3,4,5 and then we check for 6, so 6 at last, but this is wrong. 
//    Hence we cannot put into list when starting the dfs, because we dont' know if 0 was coming from somewhere else. 
//    Hence we put into list at last and then reverse(or use stack and pop). So ordering becomes 5->4->3->2->1->0 and then we check for 6, 
// so 5->4->3->2->1->0->6 and reversing this is correct topo.


// TC: O(N) + O(E)
// SC: O(N)

#include <stack>

void dfs(int node, vector<bool>& visited, stack<int>& s, vector<vector<int>> &adjList)
{
    visited[node] = true;

    for(int neighbour : adjList[node])
    {
        if(!visited[neighbour])
            dfs(neighbour, visited, s, adjList);
    }

    s.push(node);
}


vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    // Write your code here!
    vector<vector<int>> adjList(nodes);

    for(int i = 0; i < edges; i++)
    {
        int u = graph[i][0];
        int v = graph[i][1];

        adjList[u].push_back(v);
    }

    vector<bool> visited(nodes, false);
    stack<int> s;

    for(int i = 0; i < nodes; i++)
    {
        if(!visited[i])
            dfs(i, visited, s, adjList);
    }

    vector<int> ans;

    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}
