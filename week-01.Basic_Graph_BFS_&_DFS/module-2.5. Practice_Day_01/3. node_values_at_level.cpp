#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
bool visited[1005];
int level[1005];

void bfs(int src)
{
    queue<int> q;
    q.push(src);

    visited[src] = true;
    level[src] = 0;
    while (!q.empty())
    {
        int p = q.front();
        q.pop();

        for (int child : adj[p])
        {
            //* children is not visited then push queue and track
            if (!visited[child])
            {
                q.push(child);
                visited[child] = true;
                level[child] = level[p] + 1;
            }
        }
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

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int l;
    cin >> l;

    memset(visited, false, sizeof(visited));
    memset(level, -1, sizeof(level));

    bfs(0); // Perform BFS starting from node 0

    vector<int> nodeLevelVal;
    for (int i = 0; i < n; i++)
    {
        if (level[i] == l)
            nodeLevelVal.push_back(i);
    }

    reverse(nodeLevelVal.begin(), nodeLevelVal.end());

    // Print the sorted nodes
    for (int node : nodeLevelVal)
        cout << node << " ";

    cout << endl;

    return 0;
}