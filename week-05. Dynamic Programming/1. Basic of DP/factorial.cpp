#include <bits/stdc++.h>
using namespace std;

//* Complexity O(N)
int fact(int n){
    if(n == 0) return 1; //* base case

    int initialFactorial = fact(n-1);
    return initialFactorial *n;
}

int main()
{
    int n;
    cin >> n;

    // cout << fact(n) << endl;

    //* looping solution 
    int ans = 1;
    for (int i = 1; i <= n; i++)
        ans *= i;
    
    cout << ans << endl;
    return 0;
}