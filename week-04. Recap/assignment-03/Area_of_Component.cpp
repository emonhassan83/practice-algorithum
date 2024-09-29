#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
char grid[N][N];
bool vis[N][N];
int n, m;

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool valid(int ci, int cj)
{
    if (ci >= 0 && ci < n && cj >= 0 && cj < m)
        return true;
    else
        return false;
}

int dfs(int si, int sj)
{
    vis[si][sj] = true;
    int area = 1;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.')
            area += dfs(ci, cj);
    }
    return area;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    }

    memset(vis, 0, sizeof(vis));

    int minArea = INT_MAX;
    bool cmp = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && !vis[i][j])
            {
                int area = dfs(i, j);

                minArea = min(minArea, area);
                cmp = true;
            }
        }
    }

    if (cmp)
        cout << minArea << endl;
    else
        cout << -1 << endl;

    return 0;
}
