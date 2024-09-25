#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = 25;
char grid[N][N];
bool vis[N][N];
int cnt;

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int ci, int cj)
{
    if (ci >= 0 && ci < n && cj >= 0 && cj < m)
        return true;
    else
        return false;
}

void dfs(int si, int sj)
{
    vis[si][sj] = true;
    cnt++; //* increase count here

    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.')
            dfs(ci, cj);
    }
}

int main()
{
    int t;
    cin >> t;

    int cs = 1;
    while (t--)
    {
        cin >> m >> n;

        int si, sj;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];

                if (grid[i][j] == '@')
                {
                    si = i;
                    sj = j;
                }
            }
        }

        cnt = 0; //* set count 0 initially
        memset(vis, 0, sizeof(vis));

        dfs(si, sj);

        cout << "Case " << cs++ << ": " << cnt << endl;
    }

    return 0;
}