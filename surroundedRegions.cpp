#include<iostream>
#include<vector>
using namespace std;
class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& vis,
             vector<vector<char>>& mat,
             int delrow[], int delcol[]) {

        vis[row][col] = 1;

        int n = mat.size();
        int m = mat[0].size();

        // Check top, right, bottom, left
        for (int i = 0; i < 4; i++) {

            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            // Check boundary + not visited + O
            if (nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol < m &&
                !vis[nrow][ncol] &&
                mat[nrow][ncol] == 'O') {

                dfs(nrow, ncol, vis, mat, delrow, delcol);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // -----------------------------
        // Step 1: First and last row
        // -----------------------------
        for (int j = 0; j < m; j++) {

            // First row
            if (!vis[0][j] && board[0][j] == 'O') {
                dfs(0, j, vis, board, delrow, delcol);
            }

            // Last row
            if (!vis[n - 1][j] && board[n - 1][j] == 'O') {
                dfs(n - 1, j, vis, board, delrow, delcol);
            }
        }

        // -----------------------------
        // Step 2: First and last column
        // -----------------------------
        for (int i = 0; i < n; i++) {

            // First column
            if (!vis[i][0] && board[i][0] == 'O') {
                dfs(i, 0, vis, board, delrow, delcol);
            }

            // Last column
            if (!vis[i][m - 1] && board[i][m - 1] == 'O') {
                dfs(i, m - 1, vis, board, delrow, delcol);
            }
        }

        // -----------------------------
        // Step 3: Convert surrounded O
        // -----------------------------
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // O not connected to boundary
                // => surrounded
                if (!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};


//another approach 
class Solution {
public:
    bool isSafe(int r, int c, int m, int n) {
        return (r >= 0 && r < m && c >= 0 && c < n);
    }

    void floodFill(int r, int c, int m, int n, vector<vector<char>>& board) {
        board[r][c] = 'V';
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int k = 0; k < 4; k++) {
            int newr = r + dir[k][0];
            int newc = c + dir[k][1];
            if (isSafe(newr, newc, m, n) && board[newr][newc] == 'O') {
                floodFill(newr, newc, m, n, board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();

        // Step 1: Traverse borders and mark connected 'O's as 'V'
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') floodFill(0, j, m, n, board);
            if (board[m - 1][j] == 'O') floodFill(m - 1, j, m, n, board);
        }

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') floodFill(i, 0, m, n, board);
            if (board[i][n - 1] == 'O') floodFill(i, n - 1, m, n, board);
        }

        // Step 2: Capture surrounded 'O's and restore 'V' back to 'O'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'V') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};