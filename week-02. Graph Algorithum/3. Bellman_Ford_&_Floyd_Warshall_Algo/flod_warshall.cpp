#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n, e;
    cin >> n >> e;

    ll adj[n][n];

    //* for set default values in adj matrix values
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adj[i][j] = INT_MAX;
            if (i == j)
                adj[i][j] = 0; //* if row and column are equal
        }
    }

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a][b] = c;
    }

    //* for using set relation path from every k th value then set new cost of adj matrix
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adj[i][k] + adj[k][j] < adj[i][j])
                    adj[i][j] = adj[i][k] + adj[k][j];
            }
        }
    }

    //* for printing matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    //* for detect cycle
    for (int i = 0; i < n; i++)
    {
        if (adj[i][i] < 0)
        {
            cout << "Cycle detected" << endl;
            break;
        }
    }

    return 0;
}