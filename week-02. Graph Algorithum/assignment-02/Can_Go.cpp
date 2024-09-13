#include <bits/stdc++.h>
using namespace std;


const int INF = 1e9;
const int N = 1005;

vector<pair<int, int>> adj[N];
vector<int> dist(N, INF);

void dijkstra(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty())
    {
        pair<int, int> parent = pq.top();
        pq.pop();

        int node = parent.first;
        int cost = parent.second;

        if (node > dist[cost])
            continue;

        for (pair<int, int> child : adj[cost])
        {
            int childNode = child.first;
            int childCost = child.second;

            if (dist[cost] + childCost < dist[childNode])
            {
                dist[childNode] = dist[cost] + childCost;
                pq.push({dist[childNode], childNode});
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
        int a, b, w;
        cin >> a >> b >> w;

        adj[a].push_back({b, w});
    }

    int src;
    cin >> src;

    dijkstra(src);

    int t;
    cin >> t;

    while (t--)
    {
        int dest, cost;
        cin >> dest >> cost;

        if (dist[dest] <= cost)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
