#include <bits/stdc++.h>
using namespace std;

const long long int INF = 1e18;
int nodes, edge;

vector<pair<int, int>> adj[100005];
long long int dis[100005];
long long int p[100005];
bool vis[100005];

void dijkstra(int src)
{
    //* initially set distance value infinite
    for (int i = 1; i <= nodes; i++)
        dis[i] = INF;

    dis[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({dis[src], src});

    while (!pq.empty())
    {
        pair<int, int> parent = pq.top();
        pq.pop();

        int parentNode = parent.second;
        int parentCost = parent.first;

        vis[parentNode] = true;

        for (auto child : adj[parentNode])
        {
            int childCost = child.first;
            int childNode = child.second;

            if (dis[parentNode] + childCost < dis[childNode])
            {
                dis[childNode] = dis[parentNode] + childCost;
                pq.push({dis[childNode], childNode});
                p[childNode] = parentNode;
            }
        }
    }
}

int main()
{
    cin >> nodes >> edge;

    while (edge--)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back(make_pair(w, v));
        adj[v].push_back(make_pair(w, u));
    }

    int src = 1;
    dijkstra(src);

    return 0;
}