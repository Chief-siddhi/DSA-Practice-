#include <iostream>
using namespace std;

bool isSafe(int sudoku[9][9], int row, int col, int num) {
    // Check row
    for (int j = 0; j < 9; j++)
        if (sudoku[row][j] == num)
            return false;

    // Check column
    for (int i = 0; i < 9; i++)
        if (sudoku[i][col] == num)
            return false;

    // Check 3×3 box
    int sr = row - row % 3;
    int sc = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (sudoku[sr + i][sc + j] == num)
                return false;

    return true;
}

void printSudoku(int sudoku[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            cout << sudoku[i][j] << " ";
        cout << endl;
    }
}

// returns true if solved
bool sudokuSolver(int sudoku[9][9], int row, int col) {

    // If reached beyond last row → solved
    if (row == 9) {
        printSudoku(sudoku);
        return true;
    }

    // compute next cell
    int nextRow = row;
    int nextCol = col + 1;

    if (col == 8) {
        nextRow = row + 1;
        nextCol = 0;
    }

    // if already filled → move ahead
    if (sudoku[row][col] != 0)
        return sudokuSolver(sudoku, nextRow, nextCol);

    // try digits 1–9
    for (int digit = 1; digit <= 9; digit++) {
        if (isSafe(sudoku, row, col, digit)) {
            sudoku[row][col] = digit;

            if (sudokuSolver(sudoku, nextRow, nextCol))
                return true;

            // backtrack
            sudoku[row][col] = 0;
        }
    }

    return false; // trigger backtracking
}

int main() {
    int sudoku[9][9] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    if (!sudokuSolver(sudoku, 0, 0))
        cout << "No solution exists";

    return 0;
}
