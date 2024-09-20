//* https://cses.fi/problemset/task/1193

#include <bits/stdc++.h>
using namespace std;

int n, m;
char grid[20][20];
bool visited[20][20];
int dis[20][20];
pair<int, int> parent[20][20];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;

    return true;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj] = true;
    dis[si][sj] = 0;

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        int a = p.first, b = p.second;
        q.pop();

        for (int i = 0; i < d.size(); i++)
        {
            int ci = a + d[i].first;
            int cj = b + d[i].second;

            if (valid(ci, cj) && !visited[ci][cj] && grid[ci][cj] != '#')
            {
                q.push({ci, cj});
                visited[ci][cj] = true;
                dis[ci][cj] = dis[a][b] + 1;
                parent[ci][cj] = {a, b}; //* update parent queue array
            }
        }
    }
}

int main()
{
    int si, sj, di, dj;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];

            if (grid[i][j] == 'A')
            {
                si = i;
                sj = j;
            }
            else if (grid[i][j] == 'B')
            {
                di = i;
                dj = j;
            }
        }
    }

    memset(visited, false, sizeof(visited));
    memset(dis, -1, sizeof(dis));

    bfs(si, sj);

    if (visited[di][dj])
    {
        cout << "YES" << endl;
        cout << dis[di][dj] << endl;

        pair<int, int> p = {di, dj};
        vector<pair<int, int>> path;

        while (!(p.first == si && p.second == sj))
        {
            path.push_back(p);
            p = parent[p.first][p.second];
        }

        path.push_back({si, sj});
        reverse(path.begin(), path.end());

        //* for printing direction like -> LDRU
        string ans = " ";
        for (int i = 1; i < path.size(); i++)
        {
            if (path[i - 1].first == path[i].first)
            {
                //* LEFT / RIGHT
                if (path[i - 1].second + 1 == path[i].second)
                    ans += "R";
                else
                    ans += "L";
            }
            else
            {
                //* UP / DOWN
                if (path[i - 1].first + 1 == path[i].first)
                    ans += "D";
                else
                    ans += "U";
            }
        }
        cout << ans << endl;
    }
    else
        cout << "NO" << endl;

    return 0;
}