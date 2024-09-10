//* https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

// class Solution
// {
// public:
//     bool bfsCheckCycle(int s, vector<int> adj[], vector<bool> &visited, vector<int> &parentArray)
//     {
//         queue<int> q;
//         q.push(s);
//         visited[s] = true;

//         while (!q.empty())
//         {
//             int parent = q.front();
//             q.pop();

//             for (int child : adj[parent])
//             {
//                 if (visited[child] && parentArray[parent] != child)
//                 {
//                     return true; // Cycle detected
//                 }

//                 if (!visited[child])
//                 {
//                     visited[child] = true;
//                     parentArray[child] = parent;
//                     q.push(child);
//                 }
//             }
//         }
//         return false;
//     }

//     //* Function to detect cycle in an undirected graph.
//     bool isCycle(int V, vector<int> adj[])
//     {
//         vector<bool> visited(V, false);
//         vector<int> parentArray(V, -1);

//         for (int i = 0; i < V; i++)
//         {
//             if (!visited[i])
//             {
//                 if (bfsCheckCycle(i, adj, visited, parentArray))
//                 {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// }