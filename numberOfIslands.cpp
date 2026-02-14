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
