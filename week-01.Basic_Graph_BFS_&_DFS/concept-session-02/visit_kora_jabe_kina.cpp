#include <bits/stdc++.h>
using namespace std;

int n, m;
char graph[1001][1001];
bool vis[1001][1001];

int dx[4] = {-1, 0, 1, 0}; // row er move
int dy[4] = {0, 1, 0, -1}; // col er move

bool valid(int x, int y)
{

    if (x >= 0 && x < n && y >= 0 && y < m && graph[x][y] == '.')
        return true;
    else
        return false;
}

void dfs(int si, int sj)
{
    vis[si][sj] = true;

    for (int i = 0; i < 4; i++)
    {

        int ci = si + dx[i]; // children er row
        int cj = sj + dy[i]; // children er column

        if (valid(ci, cj) && vis[ci][cj] == false)
        {
            vis[ci][cj] = true;
            dfs(ci, cj);
        }
    }
}

void bfs(int si, int sj)
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

        for (int i = 0; i < 4; i++)
        {

            int ci = nrow + dx[i]; // children er row
            int cj = ncol + dy[i]; // children er column

            if (valid(ci, cj) && vis[ci][cj] == false)
            {
                vis[ci][cj] = true;
                q.push({ci, cj});
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
            cin >> graph[i][j];
    }

    int source_row, source_column;
    cin >> source_row >> source_column;
    int destination_row, destination_column;

    cin >> destination_row >> destination_column;

    dfs(source_row, source_column); // source node

    if (vis[destination_row][destination_column])
        cout << "jawa jabe" << endl;
    else
        cout << "jawa jabe na";

    return 0;
}