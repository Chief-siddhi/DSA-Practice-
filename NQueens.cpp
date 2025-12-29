#include <bits/stdc++.h>
using namespace std;

void solve(int n, int row,
           vector<string> &board,
           vector<vector<string>> &solutions,
           vector<int> &col,
           vector<int> &diag1,
           vector<int> &diag2) 
{
    if (row == n) {
        solutions.push_back(board);
        return;
    }

    for (int c = 0; c < n; c++) {
        if (col[c] || diag1[row - c + n - 1] || diag2[row + c])
            continue;

        // place queen
        board[row][c] = 'Q';
        col[c] = diag1[row - c + n - 1] = diag2[row + c] = 1;

        solve(n, row + 1, board, solutions, col, diag1, diag2);

        // backtrack
        board[row][c] = '.';
        col[c] = diag1[row - c + n - 1] = diag2[row + c] = 0;
    }
}

int main() {
    int n;
    cout << "Enter N: ";
    cin >> n;

    vector<string> board(n, string(n, '.'));
    vector<vector<string>> solutions;

    vector<int> col(n, 0), diag1(2 * n - 1, 0), diag2(2 * n - 1, 0);

    solve(n, 0, board, solutions, col, diag1, diag2);

    cout << "Total solutions: " << solutions.size() << "\n\n";

    for (auto &sol : solutions) {
        for (auto &row : sol)
            cout << row << "\n";
        cout << "\n";
    }

    return 0;
}
