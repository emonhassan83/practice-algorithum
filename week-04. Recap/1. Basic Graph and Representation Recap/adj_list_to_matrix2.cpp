#include <bits/stdc++.h>
using namespace std;

//* convert adjacency list to adjacency matrix
void convert(int n, vector<pair<int, int>> adj[])
{
    int mat[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat[i][j] = -1; //* initialize adj matrix

            //* if the adj matrix i and j are same
            if (i == j)
                mat[i][j] = 0;
        }
    }

    //* convert to 2d adj matrix
    for (int i = 0; i < n; i++)
    {
        for (pair<int, int> child : adj[i])
        {
            int childNode = child.first;
            int childCost = child.second;

            mat[i][childNode] = childCost;
        }
    }

    //* print adjacency matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << mat[i][j] << " ";

        cout << endl;
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    vector<pair<int, int>> v[n];

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        v[a].push_back({b, c});
    }

    convert(n, v);

    return 0;
}