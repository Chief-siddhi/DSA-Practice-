#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<pair<int, int>> directions = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        if (heights.empty() || heights[0].empty()) {
            return {};
        }

        int ROWS = heights.size();
        int COLS = heights[0].size();

        vector<vector<bool>> pac(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atl(ROWS, vector<bool>(COLS, false));

        // Pacific Ocean
        for (int c = 0; c < COLS; ++c) {
            dfs(0, c, pac, heights);
            dfs(ROWS - 1, c, atl, heights);
        }

        // Atlantic Ocean
        for (int r = 0; r < ROWS; ++r) {
            dfs(r, 0, pac, heights);
            dfs(r, COLS - 1, atl, heights);
        }

        vector<vector<int>> res;

        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {

                if (pac[r][c] && atl[r][c]) {
                    res.push_back({r, c});
                }
            }
        }

        return res;
    }

private:
    void dfs(int r, int c,
             vector<vector<bool>>& ocean,
             vector<vector<int>>& heights) {

        ocean[r][c] = true;

        for (auto direction : directions) {

            int dr = direction.first;
            int dc = direction.second;

            int nr = r + dr;
            int nc = c + dc;

            if (nr >= 0 &&
                nr < heights.size() &&
                nc >= 0 &&
                nc < heights[0].size() &&
                !ocean[nr][nc] &&
                heights[nr][nc] >= heights[r][c]) {

                dfs(nr, nc, ocean, heights);
            }
        }
    }
};

int main() {

    vector<vector<int>> heights = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4}
    };

    Solution obj;

    vector<vector<int>> result = obj.pacificAtlantic(heights);

    cout << "Result:\n";

    for (auto cell : result) {
        cout << "[" << cell[0] << ", " << cell[1] << "]" << endl;
    }

    return 0;
}