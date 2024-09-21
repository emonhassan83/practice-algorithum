//* https://codeforces.com/problemset/problem/25/D
//* Blog_Link: https://codeforces.com/blog/entry/594

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
     int n;
    cin >> n;
    
    vector<pair<int, int>> edges; // To store all the original roads

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }

    dsu_initialize(n);

    // Step 1: Union all the given roads
    for (auto &road : edges) {
        dsu_union_by_size(road.first, road.second);
    }

    // Step 2: Find all the components (leaders of each component)
    vector<int> leaders;
    for (int i = 1; i <= n; i++) {
        if (dsu_find(i) == i) {
            leaders.push_back(i); // Each leader represents a distinct component
        }
    }

    int t = leaders.size() - 1; // Number of new roads to connect all components
    cout << t << endl;

    // Step 3: For each leader, we will create a new road connecting components
    for (int i = 1; i < leaders.size(); i++) {
        // Close an existing road and open a new road connecting components
        cout << edges[i - 1].first << " " << edges[i - 1].second << " " 
             << leaders[0] << " " << leaders[i] << endl;
    }

    return 0;
}