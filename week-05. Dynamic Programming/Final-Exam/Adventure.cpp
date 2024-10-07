#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, maxWeight;
        cin >> n >> maxWeight;

        int dp[n + 1][maxWeight + 1];

        int weight[n], v[n];
        for (int i = 0; i < n; i++)
            cin >> weight[i];

        for (int i = 0; i < n; i++)
            cin >> v[i];

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= maxWeight; j++)
                dp[i][j] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= maxWeight; j++)
            {
                if (weight[i - 1] <= j)
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i - 1]] + v[i - 1]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        cout << dp[n][maxWeight] << endl;
    }

    return 0;
}
