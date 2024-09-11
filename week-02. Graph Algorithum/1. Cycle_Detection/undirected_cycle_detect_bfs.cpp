#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
bool visited[N];
vector<int> adj[N];
int parentArray[N];
bool ans;

void bfs(int s)
{
    queue<int> q;
    q.push(s);

    visited[s] = true;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        for (int child : adj[parent])
        {
            if (visited[child] && parentArray[parent] != child)
                ans = true;

            if (!visited[child])
            {
                visited[child] = true;
                parentArray[child] = parent;
                q.push(child);
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(visited, 0, sizeof(visited));
    memset(parentArray, 0, sizeof(parentArray));
    ans = false;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            bfs(i);
    }

    if (ans)
        cout << "Found Cycle" << endl;
    else
        cout << "Can't Found Cycle" << endl;

    return 0;
}