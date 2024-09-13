#include <bits/stdc++.h>
using namespace std;

int n, m;
const int N = 1005;
char grid[N][N];
bool visited[N][N];

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool bfs(int si, int sj, int di, int dj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj] = true;

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        int a = p.first, b = p.second;
        q.pop();

        if (a == di && b == dj)
            return true;

        for (pair<int, int> dir : d)
        {
            int nx = a + dir.first;
            int ny = b + dir.second;

            if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny] && grid[nx][ny] == '.')
            {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }

    return false;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    }

    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;

    if (grid[si][sj] == '-' || grid[di][dj] == '-')
    {
        cout << "NO" << endl;
        return 0;
    }

    memset(visited, false, sizeof(visited));

    if (bfs(si, sj, di, dj))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
