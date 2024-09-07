#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
bool visited[N];
vector<int> adj[N];
int parentArray[N];
bool ans;

void dfs(int parent)
{
    visited[parent] = true;

    for (int child : adj[parent])
    {
        if(visited[child] && parentArray[parent] != child)
            ans = true;
        
        if (!visited[child]) //* for unique children
        {
            dfs(child);
            parentArray[child] = parent;
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

    memset(visited, false, sizeof(visited));
    memset(parentArray, 0, sizeof(parentArray));
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