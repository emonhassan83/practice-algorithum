#include <bits/stdc++.h>
using namespace std;

int n, m;
char grid[1001][1001];
bool visited[1001][1001];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool isValid(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '.' && !visited[x][y])
        return true;
    else
        return false;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj] = true;

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first, y = p.second;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isValid(nx, ny))
            {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    }

    memset(visited, false, sizeof(visited));

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && !visited[i][j])
            {
                bfs(i, j);
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}
