//* https://cses.fi/problemset/task/1666

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
        group_size[i] = 1; //* for size track
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

    if (leaderA == leaderB)
        return; //* if find same leader then return

    //* compromise leader by group size
    if (group_size[leaderA] > group_size[leaderB])
    {
        par[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB]; //* update or marge group size
    }
    else
    {
        par[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA]; //* update or marge group size
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    dsu_initialize(n);

    while (m--)
    {
        int a, b;
        cin >> a >> b;

        dsu_union_by_size(a, b);
    }

    vector<int> leaders;
    for (int i = 1; i <= n; i++)
    {
        if (par[i] == -1)
            leaders.push_back(i);
    }

    cout << leaders.size() - 1 << endl;

    for (int i = 1; i <= leaders.size() - 1; i++)
    {
        cout << leaders[i - 1] << " " << leaders[i] << endl;
    }

    return 0;
}