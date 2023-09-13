//Keep a bool vector for visited and path, after a path is completed in dfs, backtrack from path
//TC: O(V+E)+O(V) , where V = no. of nodes and E = no. of edges. There can be at most V components. So, another O(V) time complexity.
//SC: O(V)

//OPTIMAL - 1 = using two vectors 
bool dfs(int node, vector<bool>& path, vector<bool>& visited, vector<vector<int>>& adjList)
{
	if(visited[node] == false)
	{
		visited[node] = true;
		path[node] = true;

		for(int neighbour : adjList[node])
		{
			if(dfs(neighbour, path, visited, adjList) == true)
				return true;
		}

		path[node] = false; //backtrack
	}
	//has been visited AND PATH EXISTS
	else if(path[node] == true)
		return true;

	return false;
}


bool isCyclic(vector<vector<int>>& edges, int v, int e)
{
	vector<vector<int>> adjList(v);

	for(int i = 0; i < e; i++)
	{
		int a = edges[i][0];
		int b = edges[i][1];

		adjList[a].push_back(b);
	}

	vector<bool> path(v, false);
	vector<bool> visited(v, false); //important for components

	for(int i = 0; i < v; i++)
	{
		if(!visited[i])
		{
			if(dfs(i, path, visited, adjList) == true)
				return true;
		}
	}

	return false;
}


//OPTIMAL 2 - using the visited vector to represent path as well
//we had three states:
//if not visited it was obvious it was not in path: 0 0
//if visited but not in path: 1 0
//if visited and in path: 1 1

//instead of bool visited vector, use three int states (like -1, 0, 1)

bool dfs(int node, vector<int>& visited, vector<vector<int>>& adjList)
{
	if(visited[node] == -1)
	{
		visited[node] = 1; //visited and in path

		for(int neighbour : adjList[node])
		{
			if(dfs(neighbour, visited, adjList) == true)
				return true;
		}

		visited[node] = 0; //backtrack | visited but not part of path
	}
	//has been visited AND already exists in path
	else if(visited[node] == 1) 
		return true;

	return false;
}


bool isCyclic(vector<vector<int>>& edges, int v, int e)
{
	vector<vector<int>> adjList(v);

	for(int i = 0; i < e; i++)
	{
		int a = edges[i][0];
		int b = edges[i][1];

		adjList[a].push_back(b);
	}

	vector<int> visited(v, -1); //important for components

	for(int i = 0; i < v; i++)
	{
		if(visited[i] == -1)
		{
			if(dfs(i, visited, adjList) == true)
				return true;
		}
	}

	return false;
}

