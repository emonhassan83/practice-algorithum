#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

int bfs(int source) {
    queue<int> q;
    q.push(source);
    visited[source] = true;
    int count = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++;

        // Explore all neighbors
        for (int child : adj[node]) {
            if (!visited[child]) {
                visited[child] = true;
                q.push(child);
            }
        }
    }
    return count;
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n);
    visited.resize(n, false);

    // Read edges
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int N;
    cin >> N;

    int result = bfs(N);
    cout << result << endl;

    return 0;
}
