#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int par[N];
int group_size[N];
int level[N];

void dsu_initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
        group_size[i] = 1; //* for size track
        level[i] = 0;      //* for level track
    }

    // //* manually parent connect
    // par[1] = 2;
    // par[2] = 3;
    // par[5] = 6;
    // par[6] = 7;
}

int dsu_find(int node)
{
    if (par[node] == -1)
        return node;

    int leader = dsu_find(par[node]);
    par[node] = leader;

    return leader;
}

void dsu_union(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);

    //* compromise leaderA to give leaderB
    par[leaderA] = leaderB;
}

void dsu_union_level(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);

    if (level[leaderA] > level[leaderB])
    {
        par[leaderB] = leaderA;
    }
    else if (level[leaderB] < level[leaderA])
    {
        par[leaderA] = leaderB;
    }
    else
    {
        par[leaderA] = leaderB;
        level[leaderB]++;
    }
}

void dsu_union_by_size(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);

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
    // dsu_initialize(8);
    // dsu_union(1, 5);

    // cout << find(0) << endl;
    // cout << find(2) << endl;
    // cout << find(3) << endl;

    // for (int i = 1; i <= 7; i++)
    //     cout << par[i] << " ";

    // cout << dsu_find(1) << endl;

    dsu_initialize(7);

    // //* 1st Group: 1 -> 2 -> 3(leader)
    // dsu_union_by_size(1, 2);
    // dsu_union_by_size(2, 3);

    // //* 2nd Group: 4 -> 5 -> 6(leader)
    // dsu_union_by_size(4, 5);
    // dsu_union_by_size(5, 6);
    // dsu_union_by_size(1, 4);

    //* 1st Group: 1 -> 2 -> 3(leader)
    dsu_union_level(1, 2);
    dsu_union_level(2, 3);

    //* 2nd Group: 4 -> 5 -> 6(leader)
    dsu_union_level(4, 5);
    dsu_union_level(5, 6);
    dsu_union_level(1, 4);

    cout << dsu_find(1) << endl;
    cout << dsu_find(4) << endl;

    return 0;
}