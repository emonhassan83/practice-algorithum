#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int par[N];
int group_size[N];

void dsu_initialize(int n)
{
    for (int i = 1; i <= n; i++)
    {
        par[i] = -1;
        group_size[i] = 1;
    }
}

int dsu_find(int node)
{
    if (par[node] == -1)
        return node;

    int leader = dsu_find(par[node]);
    par[node] = leader;

    return leader;
}

void dsu_union_by_size(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);

    if (group_size[leaderA] > group_size[leaderB])
    {
        par[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {
        par[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    }
}

int main()
{

    int n, e;
    cin >> n >> e;

    dsu_initialize(n);

    int cycleEdges = 0;

    while (e--)
    {
        int u, v;
        cin >> u >> v;

        int leaderU = dsu_find(u);
        int leaderV = dsu_find(v);

        if (leaderU == leaderV)
            cycleEdges++;
        else
            dsu_union_by_size(u, v);
    }

    cout << cycleEdges << endl;

    return 0;
}