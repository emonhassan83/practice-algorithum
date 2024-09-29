#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 10e+5;
ll dp[N];

ll fibo(ll n)
{
    if (n == 0 || n == 1)
        return n; //* base case

    //* memoization case
    if (dp[n] != -1)
        return dp[n];

    ll ans = fibo(n - 1) + fibo(n - 2);
    dp[n] = ans; //* save memoization answer in variable
    return ans;
}

int main()
{
    ll n;
    cin >> n;

    memset(dp, -1, sizeof(dp));
    cout << fibo(n) << endl;

    return 0;
}