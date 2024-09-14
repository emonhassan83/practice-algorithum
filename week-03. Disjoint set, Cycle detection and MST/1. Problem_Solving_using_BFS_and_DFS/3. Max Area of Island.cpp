//* https://leetcode.com/problems/max-area-of-island/description/

// class Solution {
// public:
//     int n, m;
//     bool vis[55][55];
//     int ans;
//     int mx;
//     vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

//     bool vaild(int ci, int cj) {
//         if (ci >= 0 && ci < n && cj >= 0 && cj < m)
//             return true;
//         else
//             return false;
//     }

//     void dfs(int si, int sj, vector<vector<int>>& grid) {
//         vis[si][sj] = true;
//         ans++;

//         for (int i = 0; i < 4; i++) {
//             int ci = si + d[i].first;
//             int cj = sj + d[i].second;

//             if (vaild(ci, cj) && !vis[ci][cj] && grid[ci][cj] == 1) {
//                 dfs(ci, cj, grid);
//             }
//         }
//     }

//     int maxAreaOfIsland(vector<vector<int>>& grid) {
//         memset(vis, false, sizeof(vis));

//         n = grid.size();
//         m = grid[0].size();

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (!vis[i][j] && grid[i][j] == 1) {
//                     ans = 0;
//                     dfs(i, j, grid);
//                     mx = max(mx, ans);
//                 }
//             }
//         }
//         return mx;
//     }
// };