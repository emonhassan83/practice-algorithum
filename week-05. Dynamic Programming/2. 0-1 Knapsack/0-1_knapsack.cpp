#include <bits/stdc++.h>
using namespace std;

int knapsack(int n, int weight[], int value[], int W)
{
    if (weight[n] <= W)
    {
        if (n < 0 || W == 0)
            return 0; //* base case

        //* dutia option (niye dekhbo ar na niye dekhbo)
        int option1 = knapsack(n - 1, weight, value, W - weight[n]) + value[n];
        int option2 = knapsack(n - 1, weight, value, W);

        return max(option1, option2);
    }
    else
    {
        //* ekta option: na niye dekhbo
        int option2 = knapsack(n - 1, weight, value, W);
        return option2;
    }
}

int main()
{
    int n;
    cin >> n;

    int weight[n], value[n];

    for (int i = 0; i < n; i++)
        cin >> weight[i];

    for (int i = 0; i < n; i++)
        cin >> value[i];

    int W;
    cin >> W;

    cout << knapsack(n, weight, value, W) << endl;
    return 0;
}