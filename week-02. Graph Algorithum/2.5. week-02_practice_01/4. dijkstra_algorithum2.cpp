//* https://basecamp.eolymp.com/en/problems/1365

#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int INF = INT_MAX;

vector<pair<int, int>> adj[N];
int dist[N];

//* Dijkstra's algorithm using a priority queue
void dijkstra(int src, int n)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i <= n; ++i)
        dist[i] = INF;
        
    dist[src] = 0;

    pq.push({0, src});

    while (!pq.empty())
    {
        int u = pq.top().second;
        int currDist = pq.top().first;
        pq.pop();

        //* Skip processing if we have already found a better distance
        if (currDist > dist[u])
            continue;

        //* Relaxation step for all neighbors of u
        for (auto edge : adj[u])
        {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, s, f;
    cin >> n >> s >> f;

    s--;
    f--;

    //* Reading the adjacency matrix
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int weight;
            cin >> weight;

            if (weight != -1 && i != j)
                adj[i].push_back({j, weight});
        }
    }

    dijkstra(s, n);

    if (dist[f] == INF)
        cout << -1 << endl; //* No path found
    else
        cout << dist[f] << endl; //* Shortest distance found

    return 0;
}
