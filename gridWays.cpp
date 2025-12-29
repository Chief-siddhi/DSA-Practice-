// Grid ways
// Find number of ways to reach from (0,0) to (n-1,m-1) in an n*m grid
// Allowed moves - right or down

#include <iostream>
using namespace std;

int gridWays(int r, int c, int n, int m, string ans) {
    // reached destination
    if (r == n - 1 && c == m - 1) {
        cout << ans << "\n";  // print path (R = right, D = down)
        return 1;
    }

    // out of bounds
    if (r >= n || c >= m) {
        return 0;
    }

    // move right
    int val1 = gridWays(r, c + 1, n, m, ans + "R");

    // move down
    int val2 = gridWays(r + 1, c, n, m, ans + "D");

    return val1 + val2;
}

int main() {
    int n = 3;
    int m = 3;

    cout << "Total ways: "
         << gridWays(0, 0, n, m, "")  // pass empty string
         << endl;

    return 0;
}
