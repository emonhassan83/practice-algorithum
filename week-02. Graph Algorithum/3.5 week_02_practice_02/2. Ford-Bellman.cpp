//* https://basecamp.eolymp.com/en/problems/1453

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

const int INF = 30000;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<Edge> EdgeList;

    //* Input the edges
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        EdgeList.push_back(Edge(u - 1, v - 1, w));
    }

    vector<int> dist(n, INF);
    dist[0] = 0;

    //* Bellman-Ford algorithm: Relax all edges n-1 times
    for (int i = 0; i < n - 1; i++)
    {
        for (const Edge &edge : EdgeList)
        {
            int u = edge.u;
            int v = edge.v;
            int w = edge.c;

            if (dist[u] != INF && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    //* Output the shortest distance from vertex 1 to all others
    for (int i = 0; i < n; i++)
    {
        if (dist[i] == INF)
            cout << 30000 << " "; //* Unreachable vertices
        else
            cout << dist[i] << " "; //* Shortest distance
    }

    cout << endl;

    return 0;
}
