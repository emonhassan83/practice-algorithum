#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[20][20];
bool visited[20][20];
int dis[20][20];
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

        cout << a << " " << b << endl;

        for (int i = 0; i < d.size(); i++)
        {
            int ci = a + d[i].first;
            int cj = b + d[i].second;

            if (valid(ci, cj) && !visited[ci][cj])
            {
                q.push({ci, cj});
                visited[ci][cj] = true;
                dis[ci][cj] = dis[a][b] + 1;
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
            cin >> a[i][j];
    }

    int si, sj;
    cin >> si >> sj;

    memset(visited, false, sizeof(visited));
    memset(dis, -1, sizeof(dis));
    bfs(si, sj);

    //* count shortest path
    cout << dis[2][3] << endl;

    return 0;
}