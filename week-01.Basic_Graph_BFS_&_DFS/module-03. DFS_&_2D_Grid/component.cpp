#include <bits/stdc++.h>
using namespace std;

const int N = 10e+5;
vector<int> v[N];
bool visited[N];

void dfs(int src)
{
    cout << src << endl;
    visited[src] = true;

    for (int child : v[src])
    {
        if (!visited[child])
            dfs(child);
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
        v[a].push_back(b);
        v[b].push_back(a);
    }

    memset(visited, 0, sizeof(visited));
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            cnt++;
        }
    }
    cout << "component - " << cnt << endl;
    
    return 0;
}