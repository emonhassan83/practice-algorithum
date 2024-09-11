#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int u, v, c;

    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

int main()
{
    int n;
    cin >> n;

    const int INF = 1e9;
    vector<Edge> edges;
    vector<vector<int>> adj(n, vector<int>(n));

    //* Input the adjacency matrix of the graph
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> adj[i][j];

            if (i != j && adj[i][j] == 0)
                adj[i][j] = INF; //* No edge between i and j

            if (adj[i][j] != INF)
                edges.push_back(Edge(i, j, adj[i][j])); //* Create edge list
        }
    }

    //* Bellman-Ford algorithm inside main function
    for (int src = 0; src < n; ++src)
    {
        vector<int> dist(n, INF);
        dist[src] = 0;

        for (int i = 0; i < n - 1; i++)
        {
            for (const Edge &edge : edges)
            {
                int u = edge.u;
                int v = edge.v;
                int c = edge.c;

                //* Relaxation step
                if (dist[u] < INF && dist[u] + c < dist[v])
                    dist[v] = dist[u] + c;
            }
        }

        for (int j = 0; j < n; ++j)
        {
            if (dist[j] == INF)
                cout << "INF "; //* If there's no path, print INF
            else
                cout << dist[j] << " "; //* Otherwise, print the shortest distance
        }
        cout << endl;
    }

    return 0;
}
