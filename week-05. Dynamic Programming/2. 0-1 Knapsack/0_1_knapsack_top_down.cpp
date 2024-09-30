#include <bits/stdc++.h>
using namespace std;

const int maxN = 1000;
const int maxW = 1000;
int dp[maxN][maxW];

int knapsack(int n, int weight[], int value[], int W)
{
    if (n < 0 || W == 0)
        return 0; //* base case

    //* apply memoization condition
    if(dp[n][W] != -1)
        return dp[n][W];

    if (weight[n] <= W)
    {

        //* dutia option (niye dekhbo ar na niye dekhbo)
        int option1 = knapsack(n - 1, weight, value, W - weight[n]) + value[n];
        int option2 = knapsack(n - 1, weight, value, W);

        return dp[n][W] = max(option1, option2);
    }
    else
    {
        //* ekta option: na niye dekhbo
        int option2 = knapsack(n - 1, weight, value, W);
        return dp[n][W] = option2;
    }
}

int main()
{
    int n;
    cin >> n;

    int weight[n], value[n];

    int W;
    cin >> W;

    for (int i = 0; i < n; i++)
        cin >> weight[i];

    for (int i = 0; i < n; i++)
        cin >> value[i];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
            dp[i][j] = -1;
    }

    cout << knapsack(n, weight, value, W) << endl;
    return 0;
}