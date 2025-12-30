//rat in maze
//you are given a starting position for a rat which is stuck in a maze at an initial point (0,0)(the maze can be thought of as a 2 dimensional plane).The maze would be given in the form of a square matrix of order N*N where the cells with value 0 represent the mazes blocked locations while value 1 is the open / available path that the rat can take to reach its destination. the rat's destination is at (N-1, N-1)
//your task is to find all the possible paths that the rat can take to reach from source to destination in the maze. the possible directions that it can take to move in the maze are 'U'(up) that is (x,y-1), D down that is (x,y+1) , L left that is (x-1,y) R right that is (x+1, y)
#include<iostream>
#include<vector>
#include<string>
using namespace std;
void solveMazeUtil(int maze[][4], int x, int y, string sol, int N, vector<vector<bool>> vis){
    if(x == N-1 && y==N-1 && maze[x][y]==1){
        cout<<sol<<"\n";
        return;
    }
    //up
    if(x-1 >= 0 && !vis[x-1][y] && maze[x-1][y] == 1){
        vis[x][y] = true;
        solveMazeUtil(maze, x-1, y, sol+"U", N, vis);
        vis[x][y] = false;
    }
    //down
    if(x+1 < N && !vis[x+1][y] && maze[x+1][y] == 1){
        vis[x][y] = true;
        solveMazeUtil(maze, x+1, y, sol+"D", N, vis);
        vis[x][y] = false;
    }
    //left
    if(y-1 >= 0 && !vis[x][y-1] && maze [x][y-1] == 1){
        vis[x][y] = true;
        solveMazeUtil(maze, x, y-1, sol+"L", N, vis);
        vis[x][y] = false;
    }  
    //right
    if(y+1 < N && !vis[x][y+1] && maze[x][y+1] == 1){
        vis[x][y] = true;
        solveMazeUtil(maze, x, y+1, sol+"R", N, vis);
        vis[x][y] = false;
    }
}
void solveMaze(int maze[][4], int N){
    string sol="";
    vector<vector<bool>> vis(N, vector<bool>(N, false));
    if(maze[0][0] == 1){
        solveMazeUtil(maze, 0, 0, sol, N, vis);
    }
}
int main(){
    int n=4;
    int maze[4][4] = { { 1, 0, 0, 0 },
                       { 1, 1, 0, 1 },
                       { 1, 1, 0, 0 },
                       { 0, 1, 1, 1 } };    
    solveMaze(maze, n);
    return 0;
}