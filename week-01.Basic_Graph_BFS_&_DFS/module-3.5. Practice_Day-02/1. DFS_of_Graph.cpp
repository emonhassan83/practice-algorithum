//* https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int node, vector<int> adj[], vector<bool> &visited, vector<int> &dfsResult)
    {
        //* Mark the current node as visited
        visited[node] = true;

        //* Add the current node to the DFS result
        dfsResult.push_back(node);

        //* Traverse all adjacent vertices
        for (int neighbor : adj[node])
        {
            //* If the neighbor is not visited, do a DFS on it
            if (!visited[neighbor])
                dfs(neighbor, adj, visited, dfsResult);
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> dfsResult;
        vector<bool> visited(V, false);

        //* Start DFS from node 0
        dfs(0, adj, visited, dfsResult);

        return dfsResult;
    }
};

int main()
{
    
    return 0;
}