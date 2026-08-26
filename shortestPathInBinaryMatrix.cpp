#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int shortestPathBinaryMatrix(vector<vector<int> > &grid)
{
    int n = grid.size();

    // If starting or ending cell is blocked
    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
    {
        return -1;
    }

    // Queue stores: {row, column, distance}
    queue<pair<pair<int, int>, int> > q;

    q.push(make_pair(make_pair(0, 0), 1));

    // Mark starting cell as visited
    grid[0][0] = 1;

    // 8 possible directions
    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    while (!q.empty())
    {
        // Get front element
        pair<pair<int, int>, int> current = q.front();
        q.pop();

        int r = current.first.first;
        int c = current.first.second;
        int dist = current.second;

        // Destination reached
        if (r == n - 1 && c == n - 1)
        {
            return dist;
        }

        // Check all 8 directions
        for (int i = 0; i < 8; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            // Check if the new cell is valid
            if (nr >= 0 && nr < n &&
                nc >= 0 && nc < n &&
                grid[nr][nc] == 0)
            {
                // Mark visited
                grid[nr][nc] = 1;

                // Add to queue
                q.push(make_pair(make_pair(nr, nc), dist + 1));
            }
        }
    }

    // No path found
    return -1;
}

int main()
{
    vector<vector<int> > grid = {
        {0, 1, 0},
        {0, 0, 0},
        {1, 0, 0}
    };

    int answer = shortestPathBinaryMatrix(grid);

    cout << "Shortest Path Length: " << answer << endl;

    return 0;
}