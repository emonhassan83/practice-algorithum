//* https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

// class Solution {
//     public:
//     // Function to detect cycle in an undirected graph.
//     bool isCycle(int V, vector<int> adj[]) {
//         vector<int> parent(V, -1);
//         vector<int> group_size(V, 1);
    
//         // Function to find the ultimate parent (with path compression)
//         function<int(int)> dsu_find = [&](int node) {
//             if (parent[node] == -1)
//                 return node;
            
//             int leader = dsu_find(parent[node]);
//             parent[node] = leader;

//             return leader;
//         };

//         // Function to perform union operation by size
//         auto dsu_union_by_size = [&](int node1, int node2) {
//             int leaderA = dsu_find(node1);
//             int leaderB = dsu_find(node2);
            
//             if (leaderA != leaderB) {
//                 if (group_size[leaderA] > group_size[leaderB]) {
//                     parent[leaderB] = leaderA;
//                     group_size[leaderA] += group_size[leaderB];
//                 } else {
//                     parent[leaderA] = leaderB;
//                     group_size[leaderB] += group_size[leaderA];
//                 }
//             }
//         };

//         // Iterate over each edge in the adjacency list
//         for (int u = 0; u < V; u++) {
//             for (int v : adj[u]) {
//                 if (v > u) {
//                     int leaderU = dsu_find(u);
//                     int leaderV = dsu_find(v);
                    
//                     if (leaderU == leaderV)
//                         return true; // If two vertices have the same leader, a cycle is detected
//                      else
//                         dsu_union_by_size(u, v);
//                 }
//             }
//         }

//         return false; 
//     }
// };