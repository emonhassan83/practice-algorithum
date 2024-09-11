#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int u, v, c;

    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

const int N = 1e5 + 5;
int dis[N];

int main()
{
    int n, e;
    cin >> n >> e;

    vector<Edge> EdgeList;
    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;

        EdgeList.push_back(Edge(u, v, c)); //* create class object then push back
        // EdgeList.push_back(Edge(v, u, c)); //* for undirected graph
    }

    //* set distance initial value set
    for (int i = 0; i < n; i++)
        dis[i] = INT_MAX;

    dis[0] = 0; //* set initial source 0

    for (int i = 0; i < n - 1; i++)
    {
        for (Edge ed : EdgeList)
        {
            int u, v, c;
            u = ed.u;
            v = ed.v;
            c = ed.c;

            //* path relax condition
            if (dis[u] < INT_MAX && dis[u] + c < dis[v])
                dis[v] = dis[u] + c;
        }
    }

    //* using for detect neg cycle here
    bool cycle = false;
    for (Edge ed : EdgeList)
    {
        int u, v, c;
        u = ed.u;
        v = ed.v;
        c = ed.c;

        //* detect neg cycle here
        if (dis[u] < INT_MAX && dis[u] + c < dis[v])
        {
            cycle = true;
            break;
        }
    }

    //* print distance
    if (cycle)
        cout << "Neg cycle found no ans!";
    else
    {
        for (int i = 0; i < n; i++)
            cout << i << " -> " << dis[i] << endl;
    }

    return 0;
}