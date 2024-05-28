#include<bits/stdc++.h>
using namespace std;
/*
    Very Important to learn How to traverse via DFS in Grids by introducing a new Data_Type point => 
*/

vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool is_valid_point(int x, int y, int rows, int cols) {
        return (x >= 0 && y >= 0 && x < rows && y < cols);
    }

    bool DFS(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y, int parentX, int parentY, char c) {
        visited[x][y] = true;

        for (const auto& dir : directions) {
            int newX = x + dir[0];
            int newY = y + dir[1];

            // Skip if out of bounds or not matching the character or already visited
            if (!is_valid_point(newX, newY, grid.size(), grid[0].size()) ||
                grid[newX][newY] != c || (newX == parentX && newY == parentY))
                continue;

            if (visited[newX][newY] || DFS(grid, visited, newX, newY, x, y, c))         // Updating of parent pointer; parent pointer is there to avoid backtracking during DFS Traversal :)
                return true; // Cycle detected
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (!visited[i][j]) {
                    if (DFS(grid, visited, i, j, -1, -1, grid[i][j])) {         // Initiating parent pointers with -1 :)
                        return true;
                    }
                }
            }
        }
        return false;
    }

int main(){
    
}