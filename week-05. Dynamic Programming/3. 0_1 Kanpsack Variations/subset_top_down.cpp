#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];

bool subset_sum(int n, int a[], int s)
{
    //* base case
    if (n == 0)
    {
        if (s == 0)
            return true;
        else
            return false;
    }

    //* for memoization
    if (dp[n][s] != -1)
        return dp[n][s];

    //* apply 0_1 knapsack and if we select or choses value in range
    if (a[n - 1] <= s)
    {
        bool op1 = subset_sum(n - 1, a, s - a[n - 1]);
        bool op2 = subset_sum(n - 1, a, s);

        return dp[n][s] = op1 || op2;
    }
    else
    {
        return dp[n][s] = subset_sum(n - 1, a, s);
    }
}

int main()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int s;
    cin >> s;

    //* for initialize 
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
            dp[i][j] = -1;
    }

    if (subset_sum(n, a, s))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}