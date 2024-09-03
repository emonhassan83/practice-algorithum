#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];
bool vis[1005];

void bfs(int src, int des)
{
    queue<pair<int, int>> q;
    q.push({src, 0});

    vis[src] = true;
    bool find = false;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        int par = p.first;
        int level = p.second;

        if (par == des)
        {

            cout << level << endl;
            find = true;
        }

        for (int child : v[par])
        {
            //* children is not visited then push queue and track
            if (!vis[child])
            {
                q.push({child, level + 1});
                vis[child] = true;
            }
        }
    }
    if (!find)
        cout << "not found(-1)" << endl;
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

    int src;
    cin >> src;

    memset(vis, false, sizeof(vis));

    bfs(src, 6);

    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << " " << level[i] << endl;
    // }

    return 0;
}