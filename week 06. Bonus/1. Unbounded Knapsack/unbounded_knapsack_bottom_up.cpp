#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];

int main()
{
    int n, s;
    cin >> n >> s;

    int val[n], weight[n];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++)
        cin >> val[i];

    for (int i = 0; i < n; i++)
        cin >> weight[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            //* unbound knapsack logic
            if (weight[i - 1] <= j)
                dp[i][j] = max(val[i - 1] + dp[i][j - weight[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[n][s] << endl;
    
    return 0;
}