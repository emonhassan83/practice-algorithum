#include <bits/stdc++.h>
using namespace std;
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
    vector<pair<int, int>> edgeList;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 1 && i != j)
                edgeList.push_back({i, j});
        }
    }

    //* printing edge list
    for (pair<int, int> edge : edgeList)
        cout << edge.first << " " << edge.second << endl;

    return 0;
}