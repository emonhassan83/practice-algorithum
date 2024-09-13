#include <bits/stdc++.h>
using namespace std;


const long long INF = 1e18;

int main()
{
    int n, e, q;
    cin >> n >> e;

    vector<vector<long long>> dist(n + 1, vector<long long>(n + 1));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dist[i][j] = INF;
            if (i == j)
                dist[i][j] = 0;
        }
    }

    while (e--)
    {
        int a, b;
        long long w;
        cin >> a >> b >> w;

        dist[a][b] = min(dist[a][b], w);
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;

        if (dist[x][y] == INF)
            cout << -1 << endl;
        else
            cout << dist[x][y] << endl;
    }

    return 0;
}
