//* https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

// vector<int> bfsOfGraph(int V, vector<int> adj[])
// {
//     vector<int> bfs;                // This will store the BFS traversal result
//     vector<bool> visited(V, false); // To keep track of visited nodes

//     queue<int> q;      // Queue for BFS
//     q.push(0);         // Start BFS from vertex 0
//     visited[0] = true; // Mark 0 as visited

//     while (!q.empty())
//     {
//         int node = q.front(); // Get the front node
//         q.pop();              // Remove it from the queue
//         bfs.push_back(node);  // Add it to the BFS result

//         // Traverse all the adjacent nodes of the current node
//         for (auto it : adj[node])
//         {
//             if (!visited[it])
//             {
//                 q.push(it);         // Push adjacent node to the queue
//                 visited[it] = true; // Mark it as visited
//             }
//         }
//     }

//     return bfs; // Return the BFS traversal result
// }