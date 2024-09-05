#include <bits/stdc++.h>
using namespace std;

const int N = 10e+5;
vector<int> adj[N];
bool visited[N];

int dfs(int node)
{
    visited[node] = true;
    int count = 1;

    for (int child : adj[node])
    {
        if (!visited[child])
            count += dfs(child); // Recursively count all connected nodes
    }
    return count;
}

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(visited, 0, sizeof(visited));
    vector<int> component_sizes;

    // Check each node to see if it has been visited
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {                      // If the node is unvisited, it's a new component
            int size = dfs(i); // Perform DFS to get the size of the component
            component_sizes.push_back(size);
        }
    }

    //* Sort the sizes in ascending order
    sort(component_sizes.begin(), component_sizes.end());

    for (int size : component_sizes)
        cout << size << " ";
        
    cout << endl;

    return 0;
}
