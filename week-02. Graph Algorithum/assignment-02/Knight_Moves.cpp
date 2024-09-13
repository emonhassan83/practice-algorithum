#include <bits/stdc++.h>
using namespace std;
int n, m;

const vector<pair<int, int>> d = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

bool valid(int i, int j, int n, int m)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}

int bfs(int si, int sj, int di, int dj)
{
    vector<vector<int>> dist(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            dist[i][j] = -1;
    }

    queue<pair<int, int>> q;

    q.push({si, sj});
    dist[si][sj] = 0;

    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        int x = parent.first, y = parent.second;
        q.pop();

        if (x == di && y == dj)
        {
            return dist[x][y];
        }

        for (auto ed : d)
        {
            int nx = x + ed.first;
            int ny = y + ed.second;

            if (valid(nx, ny, n, m) && dist[nx][ny] == -1)
            {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return -1;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        int Ki, Kj, Qi, Qj;
        cin >> Ki >> Kj;
        cin >> Qi >> Qj;

        int result = bfs(Ki, Kj, Qi, Qj);
        cout << result << endl;
    }

    return 0;
}
