#include <bits/stdc++.h>
using namespace std;

const int N = 10e+5;
vector<int> v[N];
bool visited[N];

void dfs(int src)
{
    visited[src] = true;

    for (int child : v[src]) // Explore all connected nodes (children)
    {
        if (!visited[child]) // If a child node is not visited, call DFS on it
            dfs(child);
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    memset(visited, 0, sizeof(visited));
    int cnt = 0;

    // Check each node
    for (int i = 0; i < n; i++)
    {
        if (!visited[i]) // If the node is unvisited, it's a new component
        {
            dfs(i); // Perform DFS starting from this node
            cnt++;  // Increment the component count
        }
    }

    cout << cnt << endl;
    return 0;
}
