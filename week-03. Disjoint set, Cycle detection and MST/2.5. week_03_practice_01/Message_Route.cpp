#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = 1e5 + 5;
vector<int> adj[N];
int parent[N];
bool visited[N];

vector<int> bfs(int src, int des)
{
    queue<int> q;
    q.push(src);

    visited[src] = true;
    parent[src] = -1;

    while (!q.empty())
    {
        int p = q.front();
        q.pop();

        for (int child : adj[p])
        {
            if (!visited[child])
            {
                visited[child] = true;
                parent[child] = p;
                q.push(child);

                //* if we reach the destination
                if (child == des)
                {
                    vector<int> path;
                    int current = des;

                    while (current != -1)
                    {
                        path.push_back(current);
                        current = parent[current];
                    }

                    reverse(path.begin(), path.end());
                    return path;
                }
            }
        }
    }

    return {};
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a); //* it's an undirected graph
    }

    //* Perform BFS to find the shortest path from 1 to n
    vector<int> path = bfs(1, n);

    if (path.empty())
        cout << "IMPOSSIBLE" << endl;
    else
    {
        cout << path.size() << endl;

        for (int node : path)
            cout << node << " ";

        cout << endl;
    }

    return 0;
}
