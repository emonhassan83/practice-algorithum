//* https://basecamp.eolymp.com/en/problems/975

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> dist[i][j];

            if (dist[i][j] == -1 && i != j)
                dist[i][j] = INF; //* If there's no edge between i and j, set to infinity
        }
    }

    //* Floyd-Warshall algorithm to find all-pairs shortest paths
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    //* Now find the maximum shortest distance
    int maxShortestDist = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            //* Exclude unreachable pairs and self-pairs
            if (dist[i][j] < INF && i != j) 
                maxShortestDist = max(maxShortestDist, dist[i][j]);
        }
    }

    // //* print adjacent matrices
    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = 0; j < n; ++j)
    //        cout << dist[i][j] << " ";

    //     cout << endl;
    // }

    cout << maxShortestDist << endl;

    return 0;
}
