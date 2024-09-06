#include <bits/stdc++.h>
using namespace std;

int n, m;
char graph[1001][1001];
bool vis[1001][1001];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool valid(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < m && (graph[x][y] == '.' || graph[x][y] == 'B') && !vis[x][y])
        return true;
    else
        return false;
}

bool bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

    while (!q.empty())
    {
        pair<int, int> node = q.front();
        q.pop();

        int nrow = node.first;
        int ncol = node.second;

        if (graph[nrow][ncol] == 'B')
            return true;

        for (int i = 0; i < 4; i++)
        {
            int ci = nrow + dx[i];
            int cj = ncol + dy[i];

            if (valid(ci, cj))
            {
                vis[ci][cj] = true;
                q.push({ci, cj});
            }
        }
    }

    return false;
}

int main()
{
    cin >> n >> m;

    int ax, ay, bx, by;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];

            if (graph[i][j] == 'A')
            {
                ax = i;
                ay = j;
            }
            if (graph[i][j] == 'B')
            {
                bx = i;
                by = j;
            }
        }
    }

    memset(vis, false, sizeof(vis));
    bool reach = bfs(ax, ay);

    if (reach)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
