#include <bits/stdc++.h>
using namespace std;

vector<int> arr[100];

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int u, v;
        cin >> u >> v;

        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << "-->";
        for (int j = 0; j < arr[i].size(); j++)
            cout << arr[i][j] << " ";
            
        cout << endl;
    }

    return 0;
}