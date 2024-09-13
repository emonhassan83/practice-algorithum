#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int u, v, w;

    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

const int INF = 1e9 + 5;
const int N = 1005;
int dis[N];

int main()
{
    int n, e;
    cin >> n >> e;

    vector<Edge> EdgeList;
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;

        EdgeList.push_back(Edge(u, v, w));
    }

    for (int i = 1; i <= n; i++)
        dis[i] = INF;

    int source;
    cin >> source;

    dis[source] = 0;

    if (source < 1 || source > n)
        return 0;

    dis[source] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (Edge ed : EdgeList)
        {
            int u, v, w;
            u = ed.u;
            v = ed.v;
            w = ed.w;

            if (dis[u] < INF && dis[u] + w < dis[v])
                dis[v] = dis[u] + w;
        }
    }

    bool cycle = false;
    for (Edge ed : EdgeList)
    {
        int u = ed.u;
        int v = ed.v;
        int w = ed.w;

        if (dis[u] < INF && dis[u] + w < dis[v])
        {
            cycle = true;
            break;
        }
    }

    if (cycle)
    {
        cout << "Negative Cycle Detected" << endl;
        return 0;
    }

    int t;
    cin >> t;

    while (t--)
    {
        int dest;
        cin >> dest;

        if (dis[dest] == INF)
            cout << "Not Possible" << endl;
        else
            cout << dis[dest] << endl;
    }

    return 0;
}
