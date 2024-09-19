#include <bits/stdc++.h>
using namespace std;

int parent[105];
int level[105];

void initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
        level[i] = 0;
    }
}

int find_dsu(int node)
{
    if (parent[node] == -1)
        return node;
    else
    {
        int leader = find_dsu(parent[node]);
        parent[node] = leader;

        return leader;
    }
}

void union_dsu(int p, int q)
{
    int parentP = find_dsu(p);
    int parentQ = find_dsu(q);

    parent[parentQ] = parentP;
}

void union_dsu_rank(int p, int q)
{
    int parentP = find_dsu(p);
    int parentQ = find_dsu(q);

    if (level[parentP] > level[parentQ])
        parent[parentQ] = parentP;
    else if (level[parentP] < level[parentQ])
        parent[parentP] = parentQ;
    else
    {
        parent[parentQ] = parentP;
        level[parentP]++;
    }
}

int main()
{
    initialize(5);

    union_dsu_rank(1, 2);
    union_dsu_rank(3, 4);
    union_dsu_rank(2, 3);

    cout << find_dsu(2) << endl;
    cout << find_dsu(4) << endl;
    return 0;
}