#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int target = 1000 - m;

        if (target < 0)
        {
            cout << "NO" << endl;
            continue;
        }

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        bool dp[n + 1][target + 1];

        memset(dp, 0, sizeof(dp));

        for (int i = 0; i <= n; i++)
            dp[i][0] = true;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= target; j++)
            {
                if (a[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i - 1]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        if (dp[n][target])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
