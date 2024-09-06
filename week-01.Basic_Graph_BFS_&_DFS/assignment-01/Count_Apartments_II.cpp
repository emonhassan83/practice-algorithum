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

int dfs(int x, int y)
{
    visited[x][y] = true;
    int cnt = 1;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (isValid(nx, ny))
            cnt += dfs(nx, ny);
    }
    return cnt;
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
    vector<int> sz;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && !visited[i][j])
            {
                int size = dfs(i, j);
                sz.push_back(size);
            }
        }
    }

    if (sz.empty())
        cout << "0" << endl;
    else
    {
        sort(sz.begin(), sz.end());
        for (int size : sz)
            cout << size << " ";
            
        cout << endl;
    }

    return 0;
}
