#include<iostream>
#include<vector> 
using namespace std;

class Solution {
public:

    bool isSafe(int r, int c, int m, int n) {
        return (r >= 0 && r < m && c >= 0 && c < n);
    }

    void floodFill(int r, int c, int m, int n, vector<vector<int>>& grid) {

        // Mark as visited
        grid[r][c] = 0;

        int dir[4][2] = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };

        for (int k = 0; k < 4; k++) {

            int newr = r + dir[k][0];
            int newc = c + dir[k][1];

            if (isSafe(newr, newc, m, n) &&
                grid[newr][newc] == 1) {

                floodFill(newr, newc, m, n, grid);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        // Step 1:
        // Remove all land connected to the boundary

        for (int j = 0; j < n; j++) {

            // Top row
            if (grid[0][j] == 1) {
                floodFill(0, j, m, n, grid);
            }

            // Bottom row
            if (grid[m - 1][j] == 1) {
                floodFill(m - 1, j, m, n, grid);
            }
        }

        for (int i = 0; i < m; i++) {

            // Left column
            if (grid[i][0] == 1) {
                floodFill(i, 0, m, n, grid);
            }

            // Right column
            if (grid[i][n - 1] == 1) {
                floodFill(i, n - 1, m, n, grid);
            }
        }

        // Step 2:
        // Whatever 1s remain are enclaves

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {
                    count++;
                }
            }
        }

        return count;
    }
};

//time complexity : O(m*n)
//space complexity : O(m*n)