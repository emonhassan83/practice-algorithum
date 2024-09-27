#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
bool vis[N][N];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
map<pair<int, int>, pair<int, int>> par;

int n, m;
char graph[N][N];

bool valid(int ci, int cj)
{
    if (ci >= 0 && ci < n && cj >= 0 && cj < m)
        return true;
    else
        return false;
}

void bfs(int si, int sj)
{
    vis[si][sj] = true;

    queue<pair<int, int>> q;
    q.push({si, sj});

    while (!q.empty())
    {
        pair<int, int> node = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ci = node.first + dx[i];
            int cj = node.second + dy[i];

            if (valid(ci, cj) && graph[ci][cj] != '#' && !vis[ci][cj])
            {
                vis[ci][cj] = true;
                q.push({ci, cj});

                par[{ci, cj}] = {node.first, node.second};

                if (graph[ci][cj] == 'D')
                    return;
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    memset(vis, false, sizeof(vis));

    pair<int, int> src, des;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];

            if (graph[i][j] == 'R')
                src = {i, j};

            if (graph[i][j] == 'D')
                des = {i, j};
        }
    }

    bfs(src.first, src.second);

    if (!vis[des.first][des.second])
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << graph[i][j];

            cout << endl;
        }
        return 0;
    }


    pair<int, int> current = des;
    while (current != src)
    {
        if (graph[current.first][current.second] != 'D')
        {
            graph[current.first][current.second] = 'X'; 
        }
        current = par[current];
    }
    graph[src.first][src.second] = 'R';

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << graph[i][j];

        cout << endl;
    }

    return 0;
}
