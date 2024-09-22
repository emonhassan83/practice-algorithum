#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int u, v, w;

    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int main()
{
    int n;
    cin >> n;
    int mat[n][n];

    //* initialized 2d matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    }

    //* convert matrix to edge list
    vector<Edge> edgeList;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] > 0)
                edgeList.push_back(Edge(i, j, mat[i][j]));
        }
    }

    //* printing edge list
    for (Edge edge : edgeList)
        cout << edge.u << " " << edge.v << " " << edge.w << endl;

    return 0;
}