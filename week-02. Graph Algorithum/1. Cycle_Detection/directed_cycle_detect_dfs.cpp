#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
bool visited[N];
bool pathVisited[N];
vector<int> adj[N];
bool ans;

void dfs(int parent)
{
    visited[parent] = true;
    pathVisited[parent] = true;

    for (int child : adj[parent])
    {
        if(pathVisited[child])
            ans = true;

        if (!visited[child]) //* for unique children
            dfs(child);
    }
    pathVisited[parent] = false;
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
    }

    memset(visited, false, sizeof(visited));
    memset(pathVisited, false, sizeof(pathVisited));
    ans = false;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            dfs(i);
    }

    if (ans)
        cout << "Found Cycle" << endl;
    else
        cout << "Can't Found Cycle" << endl;

    return 0;
}