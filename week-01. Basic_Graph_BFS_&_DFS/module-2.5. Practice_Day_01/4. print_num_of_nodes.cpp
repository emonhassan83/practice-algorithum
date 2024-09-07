#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, e;
    cin >> n >> e;

    //* create an adjacency list
    vector<int> adj[1005];

    while (e--) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int n;
    cin >> n;

    //* The number of nodes directly conected to n is simply the size of adj[n]
    cout << adj[n].size() << endl;

    return 0;
}