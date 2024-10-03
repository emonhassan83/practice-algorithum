#include <bits/stdc++.h>
using namespace std;
int dp[100005];

int fibo(int n)
{
    if (n < 2)
        return n; //* base case

    //* memoization case
    if (dp[n] != -1)
        return dp[n];

    return dp[n] = fibo(n - 1) + fibo(n - 2);
}

int main()
{
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));

    cout << fibo(n) << endl;
    return 0;
}