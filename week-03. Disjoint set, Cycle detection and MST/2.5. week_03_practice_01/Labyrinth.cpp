#include <bits/stdc++.h>
using namespace std;

const int INF = 1005;
int n, m;
char grid[INF][INF];
bool visited[INF][INF];
pair<int, int> parent[INF][INF];
int dist[INF][INF];

vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
string dirStr = "UDLR"; // Corresponding distance

bool isValid(int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#' && !visited[x][y]);
}

void bfs(int i, int j)
{
    queue<pair<int, int>> q;
    q.push({i, j});

    visited[i][j] = true;
    dist[i][j] = 0;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // Explore neighbors
        for (int i = 0; i < 4; i++)
        {
            int nx = x + d[i].first;
            int ny = y + d[i].second;

            if (isValid(nx, ny))
            {
                visited[nx][ny] = true;
                dist[nx][ny] = dist[x][y] + 1;
                parent[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    pair<int, int> start, end;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j]; //* take in 2D matrix

            if (grid[i][j] == 'A')
                start = {i, j};
            if (grid[i][j] == 'B')
                end = {i, j};
        }
    }

    memset(visited, false, sizeof(visited));
    memset(dist, -1, sizeof(dist));

    // Run BFS from the start
    bfs(start.first, start.second);

    // Check if the end is reachable
    if (!visited[end.first][end.second])
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        cout << dist[end.first][end.second] << endl;

        string path = "";
        pair<int, int> curr = end;

        while (curr != start)
        {
            pair<int, int> p = parent[curr.first][curr.second];
            int prevX = p.first;
            int prevY = p.second;

            //* Figure out the direction
            for (int i = 0; i < 4; i++)
            {
                if (prevX + d[i].first == curr.first && prevY + d[i].second == curr.second)
                {
                    path += dirStr[i];
                    break;
                }
            }

            curr = parent[curr.first][curr.second]; // Move to the parent node
        }

        reverse(path.begin(), path.end()); // Path was built in reverse, so reverse it
        cout << path << endl;
    }

    return 0;
}
