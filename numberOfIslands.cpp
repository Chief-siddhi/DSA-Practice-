#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid){
    vis[row][col] = 1;
    queue<pair<int,int>> q;
    q.push({row,col});

    int n = grid.size();
    int m = grid[0].size();

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    while(!q.empty()){
        auto it = q.front();
        q.pop();

        int r = it.first;
        int c = it.second;

        for(int i=0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr>=0 && nr<n && nc>=0 && nc<m &&
               grid[nr][nc]=='1' && !vis[nr][nc]){

                vis[nr][nc] = 1;
                q.push({nr,nc});
            }
        }
    }
}

int numIslands(vector<vector<char>>& grid){
    int n = grid.size();
    int m = grid[0].size();
    int cnt = 0;

    vector<vector<int>> vis(n, vector<int>(m,0));

    for(int row=0; row<n; row++){
        for(int col=0; col<m; col++){
            if(!vis[row][col] && grid[row][col]=='1'){
                cnt++;
                bfs(row,col,vis,grid);
            }
        }
    }
    return cnt;
}
//time complexity:- O(n*m) where n and m are the dimensions of the grid. Each cell is visited at most once during the BFS traversal.
//space complexity:- O(n*m) in the worst case when the grid is filled with land, the queue can hold all the cells, and the visited array also takes O(n*m) space.


//another approach 
class Solution {
public:

    void dfs(int i, int j, vector<vector<bool>>& vis,
             vector<vector<char>>& grid, int n, int m) {

        // Boundary check + already visited + water
        if (i < 0 || j < 0 || i >= n || j >= m ||
            vis[i][j] || grid[i][j] == '0') {
            return;
        }

        vis[i][j] = true;

        // Top
        dfs(i - 1, j, vis, grid, n, m);

        // Right
        dfs(i, j + 1, vis, grid, n, m);

        // Bottom
        dfs(i + 1, j, vis, grid, n, m);

        // Left
        dfs(i, j - 1, vis, grid, n, m);
    }

    int numIslands(vector<vector<char>>& grid) {

        int islands = 0;

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == '1' && !vis[i][j]) {

                    dfs(i, j, vis, grid, n, m);

                    islands++;
                }
            }
        }

        return islands;
    }
};