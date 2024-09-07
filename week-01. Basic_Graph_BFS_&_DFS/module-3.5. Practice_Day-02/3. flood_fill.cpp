//* https://leetcode.com/problems/flood-fill/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    
    return 0;
}


class Solution {
public:
void bfs(vector<vector<int>>& image, int sr, int sc, int initialColor, int newColor) {
        int n = image.size();
        int m = image[0].size();
        
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        queue<pair<int, int>> q;
        
        q.push({sr, sc});
        image[sr][sc] = newColor; // Color the starting pixel

        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int x = p.first, y = p.second;

            for (const auto& d : directions) {
                int nx = x + d.first;
                int ny = y + d.second;

                // Check if the new position is within bounds and matches the initial color
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && image[nx][ny] == initialColor) {
                    q.push({nx, ny});
                    image[nx][ny] = newColor; // Color the new position
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int initialColor = image[sr][sc];
        
        // If the initial color is the same as the new color, return image as no change is needed
        if (initialColor == color) return image;

        // Perform BFS
        bfs(image, sr, sc, initialColor, color);
        
        return image;
    }
};