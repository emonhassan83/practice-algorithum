#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[20][20];
bool visited[20][20];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;

    return true;
}

void dfs(int si, int sj)
{
    cout << si << " " << sj << endl;
    visited[si][sj] = true;

    for (int i = 0; i < d.size(); i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if (valid(ci, cj) && !visited[ci][cj] && a[ci][cj] == '.')
            dfs(ci, cj);
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    }

    int si, sj;
    cin >> si >> sj;
    memset(visited, false, sizeof(visited));

    dfs(si, sj);

    return 0;
}