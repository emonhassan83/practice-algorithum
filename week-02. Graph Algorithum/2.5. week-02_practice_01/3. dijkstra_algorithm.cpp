//* https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfs(int node, vector<int> adj[], vector<bool> &visited, vector<bool> &pathVisited)
    {
        visited[node] = true;
        pathVisited[node] = true;

        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                if (dfs(neighbor, adj, visited, pathVisited))
                    return true;
            }
            else if (pathVisited[neighbor])
                return true; //* Cycle found
        }

        pathVisited[node] = false; //* Backtracking
        return false;
    }

    //* Function to detect cycle in a directed graph.
    bool isCycle(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        vector<bool> pathVisited(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, adj, visited, pathVisited))
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    Solution obj;
    if (obj.isCycle(V, adj))
        cout << "1\n";
    else
        cout << "0\n";

    return 0;
}